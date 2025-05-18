#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x)
        : data(x)
        , next(NULL) {}
};

void append(Node*& head, Node*& tail, int new_data) {
    Node* new_node = new Node(new_data);
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}


class Solution {
  public:
    Node* deleteNthNode(Node* head, int N) {
        
        Node* fast = head;
        Node* slow = head;

        int i = 0;
        while(i < N)
        {
            i++;
            fast = fast -> next;
        }

        if(fast == NULL)    return head -> next;

        while(fast != NULL && fast -> next != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }

        Node* front = slow -> next;
        slow -> next = slow -> next -> next;
        front = NULL;

        return head;
    }
};

int main() {

    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        Node* head = new Node(arr[0]);
        Node* tail = head;

        for (size_t i = 1; i < arr.size(); i++) {
            append(head, tail, arr[i]);
        }

        int K;
        cin >> K;
        cin.ignore(); // Ignore the newline after reading K

        Solution obj;
        Node* res = obj.deleteNthNode(head, K);
        Node* temp = res;

        if (res == NULL) {
            cout << -1 << endl;
        } else {
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends