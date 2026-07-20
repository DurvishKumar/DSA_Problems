class MyStack {
private:
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i = 0; i < s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(empty()){
            return -1;
        }
        int value = q.front();
        q.pop();
        return value;
    }
    
    int top() {
        if(empty()){
            return -1;
        }
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }

    int size(){
        return q.size();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */