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
    int getLen(ListNode* head){
        ListNode* temp =head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }

    ListNode* reverse(ListNode* head,int k,int count,int &index){
        if(!head) return head;
        if(index==count) return head;
        else index++;
        
        int i=0;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* front=NULL;
       
        while(i<k && curr){
            front = curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
            i++;
        }
        if(front)
            head->next =  reverse(curr,k,count,index);

        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return head;

        int count = getLen(head)/k;
        int index=0;
        return reverse(head,k,count,index);
    }
};