/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // if head is to be deleted : 
        if(x==1) {
            Node* temp = head;
            head = head->next;
            if(head != nullptr)
                head->prev = nullptr;
            delete temp;
            return head;
        }
        // for other nodes : 
        Node* curr = head;
        int cnt = 1;
        while(curr != nullptr && cnt<x) {
            curr = curr->next;
            cnt++;
        }
        // if the xth element exist : 
        if(curr != nullptr) {
            // if the curr->prev exist :
            if(curr->prev != nullptr)
                curr->prev->next = curr->next;
            // if the curr->next exist :
            if(curr->next != nullptr)
                curr->next->prev = curr->prev;
            delete curr;
        }
        return head;
    }
};