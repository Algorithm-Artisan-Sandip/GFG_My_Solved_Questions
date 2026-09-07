/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};*/
class Solution {
private:

    // Find middle of the linked list
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

        Node* ans = dummy->next;
        delete dummy;

        return ans;
    }

public:

    Node* mergeSort(Node* head) {

        // Base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find middle
        Node* middle = findMiddle(head);

        // Split into two halves
        Node* rightHead = middle->next;
        middle->next = nullptr;

        // Sort both halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);

        // Merge sorted halves
        return merge(left, right);
    }
};