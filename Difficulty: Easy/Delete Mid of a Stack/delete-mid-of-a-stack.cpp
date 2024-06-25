//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    void deleteMiddle(stack<int>& s, int current, int middle) {
        if (current == middle) {
            s.pop();
            return;
        }
        current++;
        int temp = s.top();
        s.pop();
        deleteMiddle(s, current, middle);
        s.push(temp);
    }

    void deleteMid(stack<int>& s, int sizeOfStack) {
        int middle = sizeOfStack / 2;
        deleteMiddle(s, 0, middle);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends