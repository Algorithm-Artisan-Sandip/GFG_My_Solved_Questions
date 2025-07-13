/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node* curr = head;
        Node* prev = nullptr;
        while(curr) {
            Node* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        head = prev;
        return head;
    }
};
