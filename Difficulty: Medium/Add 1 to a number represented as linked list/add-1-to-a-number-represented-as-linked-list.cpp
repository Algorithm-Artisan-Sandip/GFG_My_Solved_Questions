//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    void reverseLL(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}
    void addOneToLL(Node* &head) {
    if(head == NULL) {
        return;
    }
    reverseLL(head);
    Node* temp = head;
    int carry = 1;
    while(true) {
        int totalSum = temp->data + carry;
        temp->data = totalSum%10;
        carry = totalSum/10;
        if(temp->next == NULL || carry == 0) break;
        temp = temp->next;
    }

    // linked list is exhausted but we still have carry 1 :
    if(carry == 1) {
        Node* newNode  = new Node(1);
        temp->next = newNode;
    }
    reverseLL(head);
}
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        addOneToLL(head);
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends