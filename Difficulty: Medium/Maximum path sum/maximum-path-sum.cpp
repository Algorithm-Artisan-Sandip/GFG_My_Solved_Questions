/*
Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  private:
    int maxPathSumHelper(Node* root, int &maxSum) {
        // Base Case: An empty node contributes 0 to the path sum.
        if (root == nullptr) return 0;

        // Post-order traversal: Get the maximum path sums from left and right subtrees.
        // If a subtree returns a negative sum, we ignore it by taking max(0, sum).
        int leftMax = max(0, maxPathSumHelper(root->left, maxSum));
        int rightMax = max(0, maxPathSumHelper(root->right, maxSum));

        // Update step: The maximum path sum passing through the current node as the "turn" 
        // point (acting as the highest node in the path) is node data + leftMax + rightMax.
        maxSum = max(maxSum, root->data + leftMax + rightMax);

        // Return step: Return the maximum single path sum extending down from this node 
        // to its parent, as a path cannot split into both subtrees for the parent node.
        return root->data + max(leftMax, rightMax);
    }

  public:
    int findMaxSum(Node *root) {
        // code here
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }
};