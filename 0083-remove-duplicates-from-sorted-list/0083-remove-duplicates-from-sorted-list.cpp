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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;

        
        ListNode* temp = head;
        ListNode* curr = temp->next;
        ListNode* del = NULL;
        while(curr){
            if(temp->val == curr->val){
                del = curr;
                temp ->next = curr->next;
                delete del;
                curr=temp->next;
            }
            else {
                curr= curr->next;
                temp=temp->next;
            }
        }
        return head;
    }
};