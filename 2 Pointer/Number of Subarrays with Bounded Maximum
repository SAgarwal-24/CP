/*
 Number of Subarrays with Bounded Maximum
https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
*/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& a, int left, int right) {
        
        int n=a.size(),i;
        
        int ans=0,c=0,st=0,last=0;
        
        for(i=0;i<n;i++){
            
            if(left<=a[i] and a[i]<=right){
                c++;
                ans+=i-st+1;
                last=i-st+1;    
            }
            else if(a[i]<left){
                
                if(c>0)
                ans+=last;
            }
            else{
                st=i+1;
                last=0;
            }
            
      
        }
        
        return ans;
    }
};


/*
  ----------------Testcases------------------
  
[2,1,4,3]
2
3
[2,1,2,1,4,3]
2
3
[4,5,2,1,4,3]
2
3
[2,3,4,1,5,6,2,1]
4 
6
[5,6,2,1]
4 
6
[5,3,2,3,6,2,1]
4 
6

*/
