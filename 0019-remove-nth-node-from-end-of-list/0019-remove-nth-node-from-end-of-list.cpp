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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head->next == nullptr){
            if(head == nullptr) return nullptr;
            else if(head->next == nullptr){
                delete head;
                return nullptr;
            }
        }
        ListNode* fast = head;
        for(int i=0; i<n; i++){
            if(fast == nullptr) return head;
            fast = fast->next;
        }
        if(fast == nullptr){
            ListNode* newHead = head->next;
            head->next = nullptr;
            delete head;
            return newHead;
        }
        ListNode* slow = head;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        toDelete->next = nullptr;
        delete toDelete;
        return head;
    }
};