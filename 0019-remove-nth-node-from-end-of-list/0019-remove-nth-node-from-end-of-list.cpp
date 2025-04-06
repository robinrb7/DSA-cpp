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
        ListNode* curr = head;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        count = count-n;
        if(count==0){
            ListNode* temp =head;
            head=head->next;
            temp->next=NULL;
            delete temp;

            return head;
        }
        curr=head;
        ListNode* prev=NULL;
        while(count>0){
            prev=curr;
            curr=curr->next;
            count--;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

        return head;
    }
};