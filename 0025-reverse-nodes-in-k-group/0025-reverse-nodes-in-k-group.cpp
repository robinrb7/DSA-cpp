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
        if(!head || !head->next) return head;

        ListNode* newHead = rev(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

    ListNode* findKNode(ListNode* head, int k){
        int cnt =1;
        ListNode* temp = head;
        while(cnt < k){
            if(!temp) return NULL;
            temp=temp->next;
            cnt++;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;

        ListNode* temp = head;
        ListNode* previous = NULL;
        while(temp){
            ListNode* kNode = findKNode(temp,k);
            ListNode* nextNode = NULL;
            if(kNode){
                nextNode = kNode->next;
                kNode->next = NULL;
                kNode = rev(temp);
            }
            if(temp==head) head = kNode;
            if(kNode && head!=kNode) previous->next = kNode;
            previous = temp;
            if(nextNode) temp->next = nextNode;
            temp = nextNode;
        }
        
        return head;
    }
};