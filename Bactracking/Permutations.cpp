// link - https://leetcode.com/problems/permutations/
class Solution {
public:
    
    #define pb push_back
    #define ff first
    #define ss second
    #define vi vector<int>
    #define vvi vector<vi>
    #define vd vector<double>
    #define all(x) (x).begin(), (x).end()
    #define sz(x) ((ll)(x).size())
    #define watch(x) cout << (#x) << " -> "  << (x) << endl
    
    vvi ans;
    
    void swap(vi &a, int l, int r){
        
        int temp = a[r];
        a[r] = a[l];
        a[l] = temp;
    }
    
    // space : O(n) - recursive call stack - input & output data structure is not considered in space complexity  
    // Time : O(n*n!)
    void rec(vi &a, int l){
        
        if(l == a.size()){
            ans.pb(a); // O(n)
            return;
        }
        
        for(int r=l; r<a.size(); r++){ // O(n!) - n * n-1 * n-2 .....
            swap(a, l, r);
            rec(a, l+1);
            swap(a, l, r);
        }
    }
    
    vvi permute(vi& a) {
        
        rec(a, 0);
        
        return ans;
    }
};

/*

            1,2,3
        
    1,2,3    2,1,3      3,2,1

1,2,3



*/
