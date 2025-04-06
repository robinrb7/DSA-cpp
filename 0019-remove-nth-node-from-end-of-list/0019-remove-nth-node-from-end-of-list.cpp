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
        if(head==NULL) return head;
        ListNode* curr=head;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        while(curr!=NULL){
            front = curr->next;

            curr->next=prev;
            prev=curr;
            curr = front;
        }
        
        return prev;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);
        int i =1;
    
        ListNode* curr = head;
        ListNode* prev = NULL;
        if(n==1){
            head=head->next;
            curr->next=NULL;
            delete curr;
            return reverse(head);
        }
    
        while(i<n){
            i++;
            prev=curr;
            curr=curr->next;
        }

        if(prev!=NULL)
            prev->next = curr->next;
        curr->next=NULL;
        delete curr;

        return reverse(head);
    }
};