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
  private:
    int findLenLL(Node* head) {
        int length = 0;
        Node* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        return length;
    }
  public:
    int getKthFromLast(Node *head, int k) {
        int len = findLenLL(head);
        if(k>len) return -1;
        Node* temp = head;
        int toFind = len-k;
        while(toFind--) temp = temp->next;
        return temp->data;
    }
};