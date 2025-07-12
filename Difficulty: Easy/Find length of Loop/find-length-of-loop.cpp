/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// class Solution {
//   public:
//     int countNodesinLoop(Node *head) {
//         unordered_map<Node*, int> mp;
//         Node* temp = head;
//         int timer = 1;
//         while(temp != nullptr) {
//             if(mp.find(temp) != mp.end())
//                 return (timer-mp[temp]);
//             mp[temp] = timer;
//             temp = temp->next;
//             timer++;
//         }
//         return 0;
//     }
// };

class Solution {
  private:
    int findCycleLength(Node* fast) {
        Node* temp = fast->next;
        int cnt = 1;
        while(temp != fast) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
  public:
    int countNodesinLoop(Node *head) {
        Node* fast = head;
        Node* slow = head;
        while(fast!=nullptr && fast->next!=nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                return findCycleLength(fast);
            }
        }
        return 0;
    }
};