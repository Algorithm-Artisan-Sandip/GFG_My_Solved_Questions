/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    Node *addNode(Node *head, int pos, int data) {
        Node* dataNode = new Node(data);
        Node* temp = head;
        int cnt = 0;  // for 0 based indexing
        while(cnt<pos) {
            temp = temp->next;
            cnt++;
        }
        Node* nextToData = temp->next;
        temp->next = dataNode;
        dataNode->prev = temp;
        // if nextToData exists : 
        if(nextToData != nullptr) {
            nextToData->prev = dataNode;
            dataNode->next = nextToData;
        }
        return head;
    }
};