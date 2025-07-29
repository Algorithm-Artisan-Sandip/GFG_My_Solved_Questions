/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
*/

class Solution {
  public:
    Node *removeDuplicates(struct Node *head) {
        // Initialize temp pointer to traverse the list from the head
        Node* temp = head;
        // Traverse until the second-last node (as we're comparing temp and temp->next)
        while(temp->next != nullptr) {
            // If current node's data is same as next node's data, it's a duplicate
            if(temp->data == temp->next->data) {
                // Save the duplicate node to be deleted
                Node* toDelete = temp->next;
                // Bypass the duplicate node by changing the next pointer
                temp->next = toDelete->next;
                // If the next node after toDelete exists, fix its prev pointer
                if(toDelete->next != nullptr)
                    toDelete->next->prev = temp;
                // Delete the duplicate node to free memory
                delete toDelete;
            }
            else {
                // If not a duplicate, simply move to the next node
                temp = temp->next;
            }
        }
        // Return the head of the modified list
        return head;
    }
};
