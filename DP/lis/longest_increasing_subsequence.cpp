/*

Classical LIS problem (dp and greedy approach)
link - https://leetcode.com/problems/longest-increasing-subsequence

Other similar recommended problems by leetcode feed
  https://leetcode.com/problems/longest-increasing-subsequence-ii/
  https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
  https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/
  https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

*/

class Solution {
public:
    
    #define pb push_back
    #define vi vector<int>
    #define vvi vector<vi>
    #define all(x) (x).begin(), (x).end()
    #define sz(x) ((ll)(x).size())
    #define watch(x) cout << (#x) << " -> "  << (x) << endl
    
    void print(vi &a){
        
        for(auto x:a){
            cout<<x<<" ";
        }
        
        cout<<endl<<" ---\n ";
    }
    
    int lengthOfLIS(vi& a) {  // Time : O(n^log(n)) , Space : O(n)  Binary Search + greedy 
        
       int lenOfLIS = 1, n = a.size();
        
        vi subs;
        
        for(int r=0; r<n; r++){
            
            if( subs.empty() || subs.back() < a[r]){
                subs.push_back(a[r]);
                continue;
            }
            
            // Find the index of the first element >= a[r]
          
                auto it = lower_bound(subs.begin(), subs.end(), a[r]); 
                *it = a[r]; // Replace that number with a[r]
          
            
            /*
            int lo = 0, hi = subs.size()-1, ind = -1;
            while(lo <= hi){
                
                int mid = lo + (hi-lo)/2;
                
                if( a[r] <= subs[mid] ){ 
                    ind = mid;
                    hi = mid - 1;
                }else{
                    lo = mid + 1;
                }
                
            }
            subs[ind] = a[r];
            */
        }
        

        return subs.size();
        
    }
    
    /*
    int lengthOfLIS(vi& a) {  // Time : O(n^2) , Space : O(n)  Dynamic Programming 
        
       int lenOfLIS = 1, n = a.size();
        
        vi len(n+1, 1);

        
        for(int r=0; r<n; r++){
            for(int l=0; l<r; l++){
                
                if( a[l] >= a[r] ){
                    continue;
                }

                len[r] = max( len[r] , len[l] + 1); 
                lenOfLIS = max(lenOfLIS, len[r]);    
            }
            
        }
        
        
        return lenOfLIS;
        
    }
    
    */
};

/*

 [10,9,2,5,3,7,101,18]
   1 1 1 1 1 1  1   1
   1 1 1 2 2 3  4   2
   
   
[10,9,2,5,3,7,101,18]
[0,1,0,3,2,3]
[7,7,7,7,7,7,7]
[1]
[1,2,1,1,2,1,2,1,2]
[1,2,3,1,2,3,2,2,2,1,3,3,3,4]

*/
