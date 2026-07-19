/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0) return head;
        ListNode* Tail = head;
        int length = 1;
        while(Tail->next){
            length++;
            Tail = Tail->next;
        }
        k = k % length;
        if(k == 0) return head;
        int splitIndex = length-k;
        ListNode* temp = head;
        for(int i = 1; i < splitIndex; i++){
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        Tail->next = head;
        head = newHead;
        temp->next = nullptr;
        return head;
    }
};