// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        Node* left = head;
        Node* right = head;
        while(right->next != nullptr)
            right = right->next;
        vector<pair<int, int>> ans;
        while(left->data < right->data) {
            if(left->data + right->data > target)
                right = right->prev;
            else if(left->data + right->data < target)
                left = left->next;
            else {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
        }
        return ans;
    }
};

