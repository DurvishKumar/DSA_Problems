class Node{
public :
    int key;
    int data;
    Node* next;
    Node* prev;
    Node() : key(0), data(0), prev(nullptr), next(nullptr) {}
    Node(int k, int d) : key(k), data(d), next(nullptr), prev(nullptr) {}
    Node(int k, int v, Node* p, Node* n) : key(k), data(v), prev(p), next(n) {}
};
class LRUCache {
    int Capacity;
    unordered_map<int,Node*>mpp;
    Node* dummyhead;
    Node* dummytail;
public:
    void deleteNode(Node* node){
        Node* back = node->prev;
        Node* front = node->next;
        back->next = front;
        front->prev = back;
    }
    void insertNode(Node* node, Node* head){
        Node* headNext = head->next;
        head->next = node;
        node->prev = head;
        node->next = headNext;
        headNext->prev = node;
    }
    LRUCache(int capacity) {
        Capacity = capacity;
        dummyhead = new Node(-1,-1);
        dummytail = new Node(-1,-1);
        dummyhead->next = dummytail;
        dummytail->prev = dummyhead;
        mpp.clear();
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertNode(node,dummyhead);
        return node->data;
    }
    
    void put(int key, int value) {
        if (Capacity == 0) return;
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->data = value;
            deleteNode(node);
            insertNode(node,dummyhead);
        }
        else{
            if(mpp.size() == Capacity){
                Node* back = dummytail->prev;
                mpp.erase(back->key);
                deleteNode(back);
                delete back;
            }
            Node* node = new Node(key,value);
            mpp[key] = node;
            insertNode(node, dummyhead);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */