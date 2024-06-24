//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


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
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* zeroDummy = new Node(0);
        Node* oneDummy = new Node(0);
        Node* twoDummy = new Node(0);
        
        Node* zero = zeroDummy;
        Node* one = oneDummy;
        Node* two  = twoDummy;
        
        Node* curr = head;
        
        while(curr) {
            if(curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            }
            else if(curr->data == 1) {
                one->next = curr;
                one = one->next;
            }
            else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }
        
        zero->next = (oneDummy->next) ? oneDummy->next : twoDummy->next;
        one->next = twoDummy->next;
        two->next = nullptr;
        
        head = zeroDummy->next;
        
        delete zeroDummy;
        delete oneDummy;
        delete twoDummy;
        
        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends