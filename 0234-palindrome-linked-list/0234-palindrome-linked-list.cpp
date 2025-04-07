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
    private:
    ListNode* reverse(ListNode* head){
        if(!head || head->next==NULL) return head;
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* front = NULL;
        while(curr){
            front=curr->next;
            curr->next = prev;
            prev=curr;
            curr=front;
        }

        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return 1;

        ListNode* slow = head;
        ListNode* fast= head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast=fast->next->next;
        }
        ListNode* tslow=slow;
        slow->next = reverse(slow->next);
        slow=slow->next;
       
        ListNode* temp=head;
        while(slow){
            if(temp->val != slow->val) return 0;
            temp=temp->next;
            slow=slow->next;
            
        }
        tslow->next = reverse(tslow->next);
        return 1;

    }
};