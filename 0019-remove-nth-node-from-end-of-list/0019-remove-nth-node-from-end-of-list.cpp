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
        ListNode* slow=head;
        ListNode* fast=head;

        int i =n;
        while(i>0 && fast){
            fast=fast->next;
            i--;
        }
        if(fast==NULL){
            ListNode* temp = head;
            head= head->next;
            temp->next=NULL;
            delete temp;
            return head;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* temp = slow->next;
        slow->next= temp->next;
        temp->next=NULL;
        delete temp;

        return head;
    }
};