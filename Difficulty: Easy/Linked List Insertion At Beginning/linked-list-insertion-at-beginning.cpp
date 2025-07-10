// User function Template for C++

class Solution {
  public:
    Node *insertAtBegining(Node *head, int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        return head;
    }
};