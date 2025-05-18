#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Deletes middle of linked list and returns head of the modified list
class Solution {
  public:
    Node* deleteMid(Node* head) {
        
        Node* temp = new Node(0);
        temp -> next = head;

        Node* slow= temp;
        Node* fast = head;

        while(fast != NULL && fast -> next !=NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        if(slow == temp)    return NULL;
        else
        {
            Node* front = slow -> next;
            slow -> next = slow -> next -> next;
            front = NULL;
        }

        return head;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

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
        while (ss >> number) {
            arr.push_back(number);
        }
        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution obj;
        head = obj.deleteMid(head);
        printList(head);
        cout << "~\n";
    }
    return 0;
}