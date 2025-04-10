//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        if(!head || !head->next) return head;
        
        Node* zeroH =  new Node(-1);
        Node* oneH =  new Node(-1);
        Node* twoH =  new Node(-1);
        
        Node* zeroT = zeroH;
        Node* oneT = oneH;
        Node* twoT = twoH;
        
        Node* temp = head;
        while(temp){
            if(temp->data ==0){
                zeroT->next = temp;
                zeroT= temp;
            }
            else if(temp->data ==1){
                oneT->next = temp;
                oneT= temp;
            }
            else{
                twoT->next = temp;
                twoT= temp;
            }
            temp=temp->next;
        }
        
        if(oneH->next != NULL) {
            zeroT->next = oneH->next;
            oneT->next = twoH->next;
        }
        else{
            zeroT->next = twoH->next;
        }
        
        twoT->next= NULL;
        
        return zeroH->next;
       
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends