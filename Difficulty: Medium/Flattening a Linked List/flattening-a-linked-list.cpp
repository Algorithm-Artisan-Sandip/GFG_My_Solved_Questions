/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  private:
    Node* mergeTwoList(Node* list1, Node* list2) {
        Node* dummyNode = new Node(0);
        Node* res = dummyNode;
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->data < list2->data) {
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            }
            else {
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom;
            }
            res->next = nullptr;
        }
        if(list1) res->bottom = list1;
        else res->bottom = list2;
        
        Node* head = dummyNode->bottom;
        delete dummyNode;
        return head;
    }
    Node* recursive(Node* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        Node* mergedHead = recursive(head->next);
        return mergeTwoList(head, mergedHead);
    }
  public:
    Node *flatten(Node *root) {
        Node* head = recursive(root);
        return head;
    }
};