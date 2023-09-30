/*

link- https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

did somewhat overthinking and got confused (in language of question also)

- question is simply - are there any 'p' pairs possible  with 'difference' less than or equal to a 'thresholdDifference' 

(thresholdDifference - by binary search)

*/

class Solution {
public:
    
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define watch(x) cout << (#x) << " -> "  << (x) << endl
    
    bool check(vi &a, int dif, int p){
        
        int i=0, n = a.size();
        
        while(i<n-1){
            
            if(a[i+1] - a[i] <= dif){
                p--;
                i++;
            }
            
            i++;
        }
        
        return p<=0;
    }
    
    int minimizeMax(vi& a, int p) {
        
        sort(all(a));
        
        int n = a.size(), ans = 0;
        int lo = 0,  hi = a[n-1]-a[0];
        
        while(lo <= hi){
            int mid = lo  + (hi-lo)/2;
            
            
            if(check(a, mid, p)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
            
        }
        
        return ans;
    }
};

/*

1 1 2 3 7 10

1 2 3 3 5 7 9 


[1,2,2,2,3]
2
 
      3  3  3  2      3  3  4    2
1 5 10 13 16 19 21 24 29 32 35 39 41 
------------



[1, 5, 10, 13, 16, 19, 21, 24, 29, 32, 35, 39, 41 ]
2
[1, 8, 10, 13, 16, 19, 21, 24, 29, 32, 35, 439, 41 ]
3
[1,5]
0
[1,2,2,3]
0







*/
