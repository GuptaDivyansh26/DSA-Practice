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
  public:
    Node* merge(Node* head1, Node* head2)
    {
        Node* dummynode = new Node(0);
        Node* nlist = dummynode;  //to traverse through the flattened list
        
        while(head1 != NULL && head2 != NULL)
        {
            if(head1 -> data < head2 -> data)
            {
                nlist -> bottom = head1;
                nlist = head1;
                head1 = head1 -> bottom;
            }
            else
            {
                nlist -> bottom = head2;
                nlist = head2;
                head2 = head2 -> bottom;
            }
            
            nlist -> next = NULL;
        }
        
        if(! head1) nlist -> bottom = head2;
        else    nlist -> bottom = head1;
        
        return dummynode -> bottom;
    }
    
    Node *flatten(Node *root) {
        
        if(root == NULL || root -> next == NULL)    return root;
        Node* mergedHead = flatten(root -> next);
        
        return merge(root, mergedHead);
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