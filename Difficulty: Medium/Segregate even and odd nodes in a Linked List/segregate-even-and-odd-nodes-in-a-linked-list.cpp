// User function template for C++

/*
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
    Node* divide(Node* head) {
        // dummy nodes for even and odd lists
        Node* evenHead = new Node(0);
        Node* oddHead = new Node(0);
        // tail pointers for even and odd lists : 
        Node* evenMover = evenHead;      
        Node* oddMover = oddHead;        
        // pointer to traverse the original list
        Node* temp = head;              

        while(temp) {
            if(temp->data & 1) {
                oddMover->next = new Node(temp->data);
                oddMover = oddMover->next;
            } else {
                evenMover->next = new Node(temp->data);
                evenMover = evenMover->next;
            }
            temp = temp->next;
        }
        // Combine the even and odd lists
        Node* ansHead = evenHead->next;       
        evenMover->next = oddHead->next; 
        // Free the dummy nodes
        delete evenHead;
        delete oddHead;

        return ansHead;
    }
};
