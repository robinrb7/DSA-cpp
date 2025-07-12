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
        while(temp && cnt<k){
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
        ListNode* nextNode = NULL;
        while(temp){
            ListNode* kNode = findKNode(temp,k);
            if(!kNode){
                if(previous) previous->next = temp;
                break;
            }
            
            nextNode = kNode->next;
            kNode->next = NULL;
            kNode = rev(temp);

            if(temp==head) head = kNode;
            else previous->next = kNode;
             
            previous = temp;
            temp = nextNode;
        }
        
        return head;
    }
};