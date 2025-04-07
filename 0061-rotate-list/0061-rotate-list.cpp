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
        if(!head || k==0) return head;

        ListNode* temp =head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        k = k%n;
        int count= n-k;
        if(count==n) return head;
        temp=head;
        while(count>1){
            temp=temp->next;
            count--;
        }
        
        ListNode* curr = temp->next;
        ListNode* thead = curr;
        temp->next=NULL;
        while(curr->next) curr=curr->next;
        curr->next= head;
        head=thead;

        return head;
    }
};