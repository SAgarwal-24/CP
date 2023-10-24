#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define watch(x) cout << (#x) << " -> "  << (x) << endl

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int left=k, right=k, n = nums.size(), mi = 1e5, ans = 0;
        
        
        mi = nums[k];
        ans = mi * 1;  // len = 1 (initially)
        
        while(left-1>=0 || right+1<n){  // possible to go left or right, till then keep iterating :)
            
            int leftNum = (left-1 >=0 ) ? nums[left-1] : 0;
            int rightNum = (right+1 < n) ? nums[right+1] : 0;
        
            if( leftNum >= rightNum ){ // go left 
                mi = min(mi, leftNum);
                left -= 1;
            }
            else{                      // go right
                 mi = min(mi, rightNum); 
                right += 1;
            }
            
            int subArrLen = abs(min(right, n-1)  - max(left, 0)) + 1;
            
            ans = max(ans, mi * subArrLen);
            
        }
        
        return ans;
    }
};

/*

[3,2,1]

2,1  2
2,2  4
1,3  3

*/
