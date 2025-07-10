/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        if(head == nullptr) {
            Node* headNode = new Node(x);
            head = headNode;
            return head;
        }
        Node* temp = head;
        while(temp->next != nullptr)
            temp = temp->next;
        Node* endNode = new Node(x);
        temp->next = endNode;
        return head;
    }
};