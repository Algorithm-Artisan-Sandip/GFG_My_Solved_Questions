// Linked list Node
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        Node* temp1 = head1;
        Node* temp2 = head2;
        // When either pointer reaches the end, redirect it to the 
        // head of the other list. If there is an intersection, they 
        // will meet at the intersection node. If there is no 
        // intersection, both will eventually become nullptr
        while (temp1 != temp2) {
            // Move temp1 to next node, or 
            // to headB if it reaches end of list A
            temp1 = (temp1) ? temp1->next : head2;
            // Move temp2 to next node, or 
            // to headA if it reaches end of list B
            temp2 = (temp2) ? temp2->next : head1;
        }
        return temp1;
    }
};


