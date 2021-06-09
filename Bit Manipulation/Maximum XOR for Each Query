//https://leetcode.com/problems/maximum-xor-for-each-query/
// Maximum XOR for Each Query (observation based)

class Solution {
public:
    
    // Only one thing to realize 
    // In each query we can always do 
    // prefix_xor ^ k = (2^mb)-1 , mb=maximum bit
    
    // ie   prefix_xor ^ k = ((1<<mb)-1)
    
    vector<int> getMaximumXor(vector<int>& a, int mb) {
        
        
        int prefix_xor=0,i,n=a.size(),k=0;
        
        int finally = (1<<mb)-1;
        
        vector<int>ans;
        
        for(i=0;i<n;i++)prefix_xor=prefix_xor^a[i];
        
        for(i=n-1;i>=0;i--){
            
            k=prefix_xor^(finally);
            ans.push_back(k);
            prefix_xor=prefix_xor^a[i];
        }
        
        return ans;
        
        
    }
};
/*
[0,1,1,3]
2
[2,3,4,7]
3
[0,1,2,2,5,7]
3

*/
