/*
-https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

class Solution {
public:
    
    void clear(stack<int>&st){
        while(!st.empty())st.pop();
    }
    
    int largestRectangleArea(vector<int>& h) {
        
        stack<int>st;
        int i,j,n=h.size();
        int left[100002]={0}, ri[100002]={0};
        
        for(i=0;i<n;i++){
            
            while(!st.empty() and h[st.top()]>=h[i]){
                st.pop();
            }
            
            left[i]=(st.empty())?0:st.top()+1;
            st.push(i);
        }
        
        // for(i=0;i<n;i++)cout<<left[i]<<" ";
        // cout<<endl;
        
        clear(st);

        for(i=n-1;i>=0;i--){
            
            while(!st.empty() and h[st.top()]>=h[i]){
                st.pop();
            }
            
            ri[i]=(st.empty())?n-1:st.top()-1;
            st.push(i);
        }
        
        // for(i=0;i<n;i++)cout<<ri[i]<<" ";
        // cout<<endl;
        
        
        int ans=0;
        
        for(i=0;i<n;i++){
            
            int d=ri[i]-left[i]+1;
            
            //cout<<d<<" ";
            ans=max(ans,d*h[i]);
        }
        
        return ans;
    }
};
