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
    ListNode* rev(ListNode* head){
        if(head->next==NULL) return head;

        ListNode* newHead = rev(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return 0;
        if(head->next==NULL) return 1;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHead = rev(slow->next);
        ListNode* firstHead = head;
        while(secondHead){
            if(firstHead->val != secondHead->val) return 0;
            firstHead = firstHead->next;
            secondHead = secondHead->next;
        }

        rev(slow->next);

        return 1;
    }
};