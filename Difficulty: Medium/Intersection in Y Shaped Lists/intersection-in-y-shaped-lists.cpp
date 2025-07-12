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
        unordered_map<Node*, int> mp;
        Node* mover1 = head1;
        while(mover1 != nullptr) {
            mp[mover1] = 1;
            mover1 = mover1->next;
        }
        Node* mover2 = head2;
        while(mover2 != nullptr) {
            if(mp.find(mover2) != mp.end()) {
                return mover2;
            }
            mp[mover2] = 1;
            mover2 = mover2->next;
        }
    }
};