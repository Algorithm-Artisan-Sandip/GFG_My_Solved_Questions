/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/


class Solution {
  private:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while(curr != nullptr) {
            Node* nextToCurr = curr->next; 
            curr->next = prev;            
            prev = curr;                   
            curr = nextToCurr;          
        }
        return prev;
    }
    Node* getKthNode(Node* head, int k) {
        while(head != nullptr && k > 1) {
            head = head->next;
            k--;
        }
        return head; 
    }
  public:
    Node* reverseKGroup(Node* head, int k) {
        Node* temp = head;         
        Node* prevGroupTail = nullptr;  
        while(temp) {
            // Find the k-th node of the current group
            Node* kthNode = getKthNode(temp, k);
            // Save the next group's head if k-th node exists
            Node* nextGroupHead = (kthNode) ? kthNode->next : nullptr;
            // Detach current group from the rest of the list if valid
            if(kthNode)
                kthNode->next = nullptr;
            // Reverse the current group (regardless of group size)
            Node* reversedHead = reverse(temp);
            // Connect previous group to the current reversed group
            if(prevGroupTail)
                prevGroupTail->next = reversedHead;
            else
                head = reversedHead;  // Update head for the first group
            // Connect the tail of the current reversed group to the next group
            temp->next = nextGroupHead;
            // Update the tail pointer for the next iteration
            prevGroupTail = temp;
            // Move temp to the next group's head
            temp = nextGroupHead;
        }
        return head;
    }
};
