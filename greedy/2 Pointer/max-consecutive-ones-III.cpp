/*

https://leetcode.com/problems/max-consecutive-ones-iii/

Constraint of this question is biggest hint.

Constraint : you can flip at most k 0's = any subarray has atmost k zeros

So check all subarrays (so that there are atmost k zeros) using sliding window technique


*/
class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        
        vector<int>v;
        
        int i=0,st=0, n=a.size();
        int ans=0, one=0, z=0;
        
        
        while(i<n){
            
            if(a[i]==1) one++;
            else z++;
            
            while(z>k){
                if(a[st]==0)z--;
                else one--;
                
                st++;
            }
            
            ans=max(ans,one+z);
            
            i++;
                
                
                
            }
        
        
        return ans;
    
        
        
        
    }
};
