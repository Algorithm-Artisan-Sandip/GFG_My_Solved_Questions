//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
  
    Node* midOfLL(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(fast->next != NULL) {
            fast = fast->next;
            if(fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
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
    
    bool checkPalindrome(Node* head, Node* mid) {
        Node* temp1 = head;
        Node* temp2 = mid;
        while(temp2 != NULL) {
            if(temp1->data != temp2->data) {
                return false;
            }
            temp1 = temp1->next; 
            temp2 = temp2->next;
        }
        return true;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node* mid = midOfLL(head);
        reverseLL(mid->next);
        return checkPalindrome(head,mid->next);
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends