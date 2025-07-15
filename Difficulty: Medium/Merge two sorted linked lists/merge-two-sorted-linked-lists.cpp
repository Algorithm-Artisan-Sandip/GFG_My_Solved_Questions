/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution {
  public:
    // Function to merge two sorted linked lists and return the head of the merged list
    Node* sortedMerge(Node* head1, Node* head2) {
        Node* dummyHead = new Node(-1); // Dummy node
        Node* tail = dummyHead;
        // Traverse both lists until one is exhausted
        while(head1 && head2) {
            if(head1->data < head2->data) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        // Attach remaining nodes of the non-empty list
        if(head1) tail->next = head1;
        if(head2) tail->next = head2;

        Node* newHead = dummyHead->next;
        delete dummyHead;
        return newHead;
    }
};