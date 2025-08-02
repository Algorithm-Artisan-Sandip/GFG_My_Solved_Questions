/* Node structure

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

class Solution {
  public:
    void rearrangeEvenOdd(Node *head) {
        // Edge case: if list has 0 or 1 node, no rearrangement needed
        if (head == nullptr || head->next == nullptr)
            return;
        // Initialize even and odd pointers
        Node* evenHead = head;          // Head of even-indexed nodes
        Node* oddHead = head->next;     // Head of odd-indexed nodes
        Node* evenTail = evenHead;      // Tail pointer for even list
        Node* oddTail = oddHead;        // Tail pointer for odd list
        // Traverse and rearrange nodes
        while (oddTail != nullptr && oddTail->next != nullptr) {
            evenTail->next = oddTail->next;       // Link next even node
            evenTail = evenTail->next;            // Move even tail forward
            
            oddTail->next = evenTail->next;       // Link next odd node
            oddTail = oddTail->next;              // Move odd tail forward
        }
        // Attach the odd list after the even list
        evenTail->next = oddHead;
    }
};
