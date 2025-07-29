// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
public:
    void deleteAllOccurOfX(Node** headRef, int x) {
        if (!headRef || !*headRef) return;
        Node* curr = *headRef;
        while (curr) {
            if (curr->data == x) {
                Node* toDelete = curr;
                Node* prev     = curr->prev;
                Node* next     = curr->next;
                // relink neighbors
                if(prev) prev->next = next;
                else *headRef = next;
                if(next) next->prev = prev;
                curr = next;
                delete toDelete;
            } 
            else curr = curr->next;
        }
    }
};
