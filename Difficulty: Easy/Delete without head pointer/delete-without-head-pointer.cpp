/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/

class Solution {
  public:
    void deleteNode(Node* del_node) {
        int nextNodeVal = del_node->next->data;
        del_node->data = nextNodeVal;
        Node* nextNode = del_node->next;
        del_node->next = nextNode->next;
        delete nextNode;
    }
};