/* Structure of a Linked List Node
class Node
{
    int data;
    Node next;
    Node(int d) {
       data = d;
       next = nullptr;
    }
};*/
class Solution {
private:

    // Find the middle node
    Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while (left != nullptr && right != nullptr) {

            if (left->data <= right->data) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        // Attach remaining nodes
        if (left != nullptr)
            temp->next = left;
        else
            temp->next = right;

        Node* result = dummy->next;
        delete dummy;

        return result;
    }

public:

    Node* sortLL(Node* head) {

        // Empty list or single node
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find middle
        Node* middle = findMiddle(head);

        // Split into two halves
        Node* rightHead = middle->next;
        middle->next = nullptr;

        // Recursively sort both halves
        Node* left = sortLL(head);
        Node* right = sortLL(rightHead);

        // Merge both sorted halves
        return merge(left, right);
    }
};