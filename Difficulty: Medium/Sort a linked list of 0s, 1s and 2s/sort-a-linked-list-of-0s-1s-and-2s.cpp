/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // heads and tails for three sublists (0s, 1s, and 2s)
        Node *zeroHead = nullptr, *zeroTail = nullptr;
        Node *oneHead = nullptr, *oneTail = nullptr;
        Node *twoHead = nullptr, *twoTail = nullptr;
        Node* temp = head;
        // divide nodes into 0, 1, and 2 lists
        while (temp) {
            if (temp->data == 0) {
                if (!zeroHead) {
                    zeroHead = zeroTail = temp;
                } else {
                    zeroTail->next = temp;
                    zeroTail = zeroTail->next;
                }
            }
            else if (temp->data == 1) {
                if (!oneHead) {
                    oneHead = oneTail = temp;
                } else {
                    oneTail->next = temp;
                    oneTail = oneTail->next;
                }
            }
            else {
                if (!twoHead) {
                    twoHead = twoTail = temp;
                } else {
                    twoTail->next = temp;
                    twoTail = twoTail->next;
                }
            }
            temp = temp->next;
        }

        // Connect 0s list to 1s list
        if (zeroTail) zeroTail->next = oneHead;
        else zeroHead = oneHead; // If no 0s, start from 1s

        // Connect 1s list to 2s list
        if (oneTail) oneTail->next = twoHead;
        // If no 1s, connect 0s directly to 2s
        else if (zeroTail) zeroTail->next = twoHead;
        // If no 0s and no 1s, head is 2s
        else zeroHead = twoHead; 

        // Terminate the final list properly
        if (twoTail) twoTail->next = nullptr;

        return zeroHead;
    }
};