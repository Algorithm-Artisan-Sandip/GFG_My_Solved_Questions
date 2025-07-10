/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    DLLNode* reverseDLL(DLLNode* head) {
        DLLNode* curr = head;
        DLLNode* newHead = nullptr;
        while(curr != nullptr) {
            DLLNode* last = curr->prev;
            curr->prev = curr->next;
            curr->next = last;
            newHead = curr;
            curr = curr->prev;
        }
        head = newHead;
        return head;
    }
};