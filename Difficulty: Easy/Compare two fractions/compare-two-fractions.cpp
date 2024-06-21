//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int cutFirstNum(string & str){
        int ind = 0;
        while(ind < str.size() && !isdigit(str[ind])){
            ind++;
        }
        int num = 0;
        while(ind < str.size() && isdigit(str[ind])){
            num = (num*10) + (str[ind]-'0');
            ind++;
        }
        str = str.substr(ind);
        return num;
    }
  public:
    string compareFrac(string str) {
        int a1 = cutFirstNum(str);
        int a2 = cutFirstNum(str);

        int b1 = cutFirstNum(str);
        int b2 = cutFirstNum(str);
        
        float a = (float)a1/a2;
        float b = (float)b1/b2;

        if(a > b){
            return to_string(a1)+"/"+to_string(a2);
        }else if(b > a){
            return to_string(b1)+"/"+to_string(b2);
        }
        return "equal";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends