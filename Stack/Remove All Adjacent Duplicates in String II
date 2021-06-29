/*
Remove All Adjacent Duplicates in String II
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
*/
class Solution {
public:
    
    #define F first
    #define S second
    
    string removeDuplicates(string s, int k) {
        string res="";
        
        stack<pair<char,int>>st;
        
        for(auto ch:s){
            if(!st.empty() and st.top().F==ch){
                
                auto par = st.top(); st.pop();
                
                if(par.S+1<k){
                    par.S +=1;
                    st.push(par);
                }
            }
            else{
                st.push({ch,1});
            }
        }
        
        char tem[100001];
        int c=0;
        
        while(!st.empty()){
            auto par = st.top(); st.pop();
            
            while(par.S--){
                tem[c++]=par.F;
            }
        }
        
        for(int i=c-1;i>=0;i--){
            res+=tem[i];
        }
        
        return res;
    }
};
