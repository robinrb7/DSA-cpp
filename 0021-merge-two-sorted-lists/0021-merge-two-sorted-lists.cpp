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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        ListNode* temp1=list1;
        ListNode* temp2 =list2;
        if(list1->val > list2->val){
            temp1=list2;
            temp2=list1;
        }

        ListNode* head =temp1;

        while(temp2!=NULL && temp1!=NULL){
            if(temp1->next==NULL){
                temp1->next = temp2;
                break;
            }


            int data =temp2->val;
            ListNode* front1 = temp1->next;
            ListNode* front2 = temp2->next;
            if(data >= temp1->val &&front1 !=NULL && data <= front1->val){
                temp1->next = temp2;
                temp2->next = front1;
                temp2 = front2;
            }
            else{
                temp1=temp1->next;
            }
        }

        return head;
        
    }
};