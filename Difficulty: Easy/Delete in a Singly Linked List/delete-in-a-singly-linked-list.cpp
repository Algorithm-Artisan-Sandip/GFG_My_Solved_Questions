/* Link list Node
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
    Node* deleteNode(Node* head, int x) {
        // if x is 1 : 
        if(x == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        // else : 
        Node* curr = head;
        Node* prev = head;
        int cnt = 1;
        while(curr != nullptr && cnt<x) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        // if the xth node exists : 
        if(curr != nullptr) {
            prev->next = curr->next;
            delete curr;
        }
        return head;
    }
};