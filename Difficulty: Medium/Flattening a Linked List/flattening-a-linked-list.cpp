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
  public:
    Node *flatten(Node *root) {
        vector<int> arr;
        Node* horizontal = root;
        while(horizontal != nullptr) {
            arr.push_back(horizontal->data);
            Node* vertical = horizontal->bottom;
            while(vertical != nullptr) {
                arr.push_back(vertical->data);
                vertical = vertical->bottom;
            }
            horizontal = horizontal->next;
        }
        sort(arr.begin(), arr.end());
        Node* dummy = new Node(0);
        Node* temp = dummy;
        for(auto val : arr) {
            temp->bottom = new Node(val);
            temp = temp->bottom;
        }
        Node* head = dummy->bottom;
        delete dummy;
        return head;
    }
};