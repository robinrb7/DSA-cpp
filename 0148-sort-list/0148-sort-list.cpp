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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        while(list1 && list2){
            if(list1->val < list2->val){
                dummy->next = list1;
                list1 = list1->next;
                dummy = dummy->next;
            }
            else{
                dummy->next = list2;
                list2 = list2->next;
                dummy = dummy->next;
            }
        }
        if(list1) dummy->next = list1;
        else dummy->next = list2;
        return temp->next;
    }

    ListNode* mergeSort(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* middle = findMiddle(head);
        ListNode* firstHead = head;
        ListNode* secondHead = middle->next;
        middle->next = NULL;
        firstHead = mergeSort(firstHead);
        secondHead = mergeSort(secondHead);
        return merge(firstHead,secondHead);
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        return mergeSort(head);

    }
};