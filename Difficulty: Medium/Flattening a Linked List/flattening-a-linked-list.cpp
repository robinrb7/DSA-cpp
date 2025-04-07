//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
    private:
    Node* merge(Node* head1, Node* head2){
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        
        Node* temp1=head1;
        Node* temp2=head2;
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        
        while(temp1 && temp2){
            if(temp1->data < temp2->data){
                tail->bottom = temp1;
                tail=temp1;
                temp1=temp1->bottom;
            }
            else{
                tail->bottom = temp2;
                tail=temp2;
                temp2=temp2->bottom;
            }
        }
        if(temp1) tail->bottom = temp1;
        if(temp2) tail->bottom = temp2;
        
        return dummy->bottom;
    }
    
    Node* solve(Node* head){
        if(head->next==NULL) return head;
        
        Node* head2 = solve(head->next);
        
        Node* temp = merge(head,head2);
        return temp;
    }
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if(root==NULL) return root;
        return solve(root);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends