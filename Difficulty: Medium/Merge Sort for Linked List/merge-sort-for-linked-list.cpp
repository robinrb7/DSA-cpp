//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
    private:
    Node* findMiddle(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast->next && fast->next->next){
            slow = slow ->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* merge(Node* leftHead, Node* rightHead){
        Node* temp1 = leftHead;
        Node* temp2 = rightHead;
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        while(temp1 && temp2){
            if(temp1->data < temp2->data){
                tail->next = temp1;
                tail = temp1;
                temp1= temp1->next;
            }
            else{
                tail->next = temp2;
                tail = temp2;
                temp2= temp2->next;
            }
        }
        if(temp1) tail->next = temp1;
        if(temp2) tail->next = temp2;
        
        return dummy->next;
    }
    Node* mergesort(Node* head){
        if(head==NULL || head->next==NULL) return head;
        
        Node* mid = findMiddle(head);
        Node* leftHead= head;
        Node* rightHead= mid->next;
        mid->next = NULL;
        leftHead = mergesort(leftHead);
        rightHead = mergesort(rightHead);
        Node* ans = merge(leftHead,rightHead);
        return ans;
    }
    
  public:
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
      if(head==NULL || head->next==NULL) return head;
      return mergesort(head);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends