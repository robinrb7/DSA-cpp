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
        if(head==NULL) return head;

        ListNode* fast = head;
        ListNode* slow = head;

        int i = 0;
        while(fast && i<n){
            fast = fast->next;
            i++;
        }
        if(!fast){
            head = head->next;
            slow->next = NULL;
            return head;
        }

        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* curr = slow;
        ListNode* delNode = slow->next;

        curr->next = delNode->next;
        delNode->next = NULL;
        delete(delNode);

        return head;
    }
};