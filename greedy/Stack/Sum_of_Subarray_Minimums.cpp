/*

link: https://leetcode.com/problems/sum-of-subarray-minimums/
Concept - Monotonic stack (NSL , NSR)

NSL  (Next smallest left)
NSR  (Next smallest right)


testcases classification
 - category 1: elements are distinct  - easy category
 - category 2: elements can be equal/duplicate -  think for this category
                - we will include - element equal to a[i] ie duplicate in either nsl or nsr 
                - to remove duplicate no. of subarrays which a[i] is smallest

*/

class Solution {
public:
    
    void print(vector<int>&a){
        
        for(auto x: a){
            cout<<x<<" ";
        }
        
        cout<<endl;
    }
    
    int mod = 1e9 + 7;
    
    int sumSubarrayMins(vector<int>& a) {
        
        int n = a.size();
        
        // stacks to store group of smaller and bigger elements than a[i] in left and right side
        stack<int>nsl, nsr; 
        
        // pref_nsl, pref_nsr  will store indices of just/closest smallest element than a[i] in left and right side
        vector<int> pref_nsl (n, 0);
        vector<int> pref_nsr (n, 0);
        
        for(int i=0; i<n; i++){
            
            while(!nsl.empty() && ( a[nsl.top()] >= a[i] ) ){ // note - remove duplicate element from nsl 
                nsl.pop();
            }
            
            pref_nsl[i] = nsl.empty() ? -1 : nsl.top();
            nsl.push(i);         
        }
        
        
         for(int i=n-1; i>=0; i--){
            
            while(!nsr.empty() && ( a[nsr.top()] > a[i] ) ){ // note - included duplicate element in nsr 
                nsr.pop();
            }
            
            pref_nsr[i] = nsr.empty() ? n : nsr.top();
            nsr.push(i);         
        }
        
      //  print(pref_nsl);
      //  print(pref_nsr);
        
        int numMinSubarrays = 0, ans = 0;
        
        for(int i=0; i<n; i++){
            
            int leftElements = i-pref_nsl[i];     // leftElements or leftSubarrays in which a[i] is smallest
            int riElements =   pref_nsr[i] - i;   // riElements or rightSubarrays in which a[i] is smallest
            
          //  cout<<i<<" -> "<<leftElements<<", "<<riElements<<endl;
            
            numMinSubarrays = ((leftElements % mod) * 1ll  * (riElements % mod)) % mod; //  update cnt of subarrays in which a[i] is smallest
            
            ans = (ans% mod + (a[i] * 1ll*  numMinSubarrays) % mod) % mod;
        }
     
        return ans;
    }
};

/*
[3,1,2,4]
[11,81,94,43,3]
[1,3,4,5,2,3,4,1,4]
[2]
[1,2]
[2,1]
[2,2]
[2,1,2,1]

*/
