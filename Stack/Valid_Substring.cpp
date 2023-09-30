//https://practice.geeksforgeeks.org/problems/valid-substring0624/1#

// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        
        stack<int>st;
        st.push(-1);
        
        int i,ans=0,n=s.size();
        
        for(i=0;i<n;i++){
            
            
            if(s[i]==')' and st.top()!=-1 and s[st.top()]=='(')
              st.pop();
            else   // if(s[i]=='(')
              st.push(i);
            
            
           // cout<<i<<" "<<st.top()<<endl;
            ans = max(ans, i-st.top());
              
            
        }
        
        return ans;
    }
};
/*
()(())(()(())()

 l=6        l=8 
()(()) (  ()(())() 

*/

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends
