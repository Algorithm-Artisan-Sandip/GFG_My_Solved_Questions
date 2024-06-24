//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    // Function to reverse a linked list
    void reverseLL(Node* &head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
    }

    // Function to add two numbers represented by linked lists
    Node* addTwoNums(Node* head1, Node* head2) {
        reverseLL(head1);
        reverseLL(head2);

        Node* temp1 = head1;
        Node* temp2 = head2;
        Node* head = NULL;
        Node* temp = NULL;
        int carry = 0;

        // Loop until both lists are fully processed and carry is zero
        while (temp1 != NULL || temp2 != NULL || carry != 0) {
            int val1 = (temp1 != NULL) ? temp1->data : 0;
            int val2 = (temp2 != NULL) ? temp2->data : 0;

            int totalSum = val1 + val2 + carry;
            carry = totalSum / 10;
            Node* nextNode = new Node(totalSum % 10);

            if (head == NULL) {
                head = nextNode;
                temp = head;
            }
            else {
                temp->next = nextNode;
                temp = temp->next;
            }

            if (temp1 != NULL) temp1 = temp1->next;
            if (temp2 != NULL) temp2 = temp2->next;
        }

        // Reverse the result list to get the correct order
        reverseLL(head);

        // Remove leading zeros if any
        while(head != NULL && head->data ==0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // If the result list is empty (all zeros), return a single node with zero
        if (head == NULL) {
            head = new Node(0);
        }

        return head;
    }

    // Function to add two numbers represented by linked lists
    struct Node* addTwoLists(struct Node* num1, struct Node* num2) {
        return addTwoNums(num1, num2);
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends