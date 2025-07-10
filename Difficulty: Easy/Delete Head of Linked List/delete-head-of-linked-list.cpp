// User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }

};

*/

Node *deleteHead(Node *head) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
