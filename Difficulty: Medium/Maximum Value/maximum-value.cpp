//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


// } Driver Code Ends
//User function Template for C++
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

class Solution {
  public:
    void createAllLevels(Node* node, vector<vector<int>>& allLevels, vector<int>& singleLevel) {
        if(node == NULL) return;
        queue<Node*> q;
        q.push(node);
        q.push(NULL);
        
        while(!q.empty()) {
            Node* currNode = q.front();
            q.pop();
            
            if(currNode == NULL) {
                allLevels.push_back(singleLevel);
                singleLevel.clear();
                if(!q.empty()) {
                    q.push(NULL);
                }
            }
            
            else {
                singleLevel.push_back(currNode->data);
                
                if(currNode->left != NULL) {
                    q.push(currNode->left);
                }
                if(currNode->right != NULL) {
                    q.push(currNode->right);
                }
            }
        }
    }
    vector<int> findAns(Node* node) {
        vector<vector<int>> allLevels;
        vector<int> singleLevel;
        vector<int> ans;
        
        createAllLevels(node, allLevels, singleLevel);
        
        for(int i=0; i<allLevels.size(); i++) {
            int maxi = INT_MIN;
            for(int j = 0; j<allLevels[i].size(); j++) {
                maxi = max(maxi, allLevels[i][j]);
            }
            ans.push_back(maxi);
        }
        
        return ans;
    }
    
    vector<int> maximumValue(Node* node) {
        //code here
        return findAns(node);
    }
};

//{ Driver Code Starts.

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
/* Function to get Largest value at each level of Binary Tree */
vector<int> maximumValue(struct Node* tree);


int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> answer = ob.maximumValue(root);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends