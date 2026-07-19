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
    ListNode* findKthNode(ListNode* temp, int k){
        k-=1;
        while(temp && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* temp){
        ListNode* last = nullptr;
        ListNode* next = nullptr;
        while(temp){
            next = temp->next;
            temp->next = last;
            last = temp;
            temp = next;
        }
        return last;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* last = nullptr;
        ListNode* next = nullptr;
        while(temp){
            ListNode* KthNode = findKthNode(temp, k);
            if(KthNode == nullptr){
                if(last) last->next = temp;
                break;
            }
            next = KthNode->next;
            KthNode->next = nullptr;
            reverse(temp);
            if(temp == head) head = KthNode;
            else last->next = KthNode;
            last = temp;
            temp = next;
        }
        return head;
    }
};