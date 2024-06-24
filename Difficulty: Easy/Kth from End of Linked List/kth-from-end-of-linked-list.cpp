//{ Driver Code Starts
// Initial Template for C++
//  C program to find n'th Node in linked list
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

/* Function to get the kth node from the last of a linked list*/
int getKthFromLast(struct Node *head, int k);

/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int lenOfLL(Node* head) {
        Node* temp = head;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    int findNode(Node* head, int count) {
        Node* temp = head;
        int data;
        while(--count) {
            data = temp->data;
            temp = temp->next;
        }
        return temp->data;
    }
    int getKthFromLast(Node *head, int k) {
        // Your code here
        int len = lenOfLL(head);
        
        int toGo = len - k + 1;
        
        if(toGo<1) return -1;
        
        return  findNode(head,toGo);
    }
};


//{ Driver Code Starts.

int main() {
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node *head = NULL, *tail = NULL;

        cin >> n >> k;
        int firstdata;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++) {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.getKthFromLast(head, k) << endl;
    }
    return 0;
}
// } Driver Code Ends