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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return NULL;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> minHeap;

        for(int i=0;i<n;i++){
            if(lists[i]) 
                minHeap.push({lists[i]->val,lists[i]});
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(!minHeap.empty()){
            temp->next = minHeap.top().second;
            if(minHeap.top().second->next) 
                minHeap.push({minHeap.top().second->next->val,minHeap.top().second->next});
            minHeap.pop();
            temp=temp->next;
        }

        return dummyNode->next;
    }
};