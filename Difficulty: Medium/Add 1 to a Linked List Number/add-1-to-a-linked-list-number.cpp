/*

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
  private:
    int recursiveAdder(Node* head) {
        // Base case: if we reach the end of the list, 
        // start by returning a carry of 1
        if(head == nullptr) {
            return 1;
        }
        int carry = recursiveAdder(head->next);
        // Add carry to current node's data
        head->data += carry;
        // If no carry is generated, return 0
        if(head->data < 10) 
            return 0;
        // If carry is generated (data >= 10), 
        // set data to 0 and return carry 1
        head->data = 0;
        return 1;
    }

  public:
    Node* addOne(Node* head) {
        // Perform recursive addition starting from the last node
        int carry = recursiveAdder(head);
        // If there's still a carry after processing the whole list
        if(carry == 1) {
            Node* newHead = new Node(1);
            newHead->next = head;
            head = newHead;
        }
        return head;
    }
};
