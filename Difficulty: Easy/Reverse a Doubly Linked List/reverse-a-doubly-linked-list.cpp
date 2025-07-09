/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
    private:
    DLLNode* revLink(DLLNode* head){
        if(head->next==NULL) return head;

        DLLNode* newHead = revLink(head->next);
        
        head->next->next = head;
        head->next->prev= NULL;
        head->prev = head->next;
        head->next = NULL;

        return newHead;
    }
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        
        return revLink(head);
    }
};