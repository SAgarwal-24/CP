/*
link - https://leetcode.com/problems/painting-the-walls/

*/

#define pb push_back
#define ff first
#define ss second
#define lli long long int
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define watch(x) cout << (#x) << " -> "  << (x) << endl



void  print(vector<pii> &paintersInfo){
    
    for(auto pr : paintersInfo){
        cout<<pr.ff<<","<<pr.ss<<endl;
    }
    
    cout<<endl;
}

class Solution {
public:
    
    
    /*
    
    1. Maximize the utilisation by free painter 
    2. and use paid painter with min cost and more time 
    
    max walls <= 500
    
    
    so that while paid painter is occupied we can use free painter more and more
    
    */
    lli compute_paint_amount(int ind, int unpainted_walls, vi& cost, vi& time){
        
        if(unpainted_walls <= 0){
            return 0;  // all walls are painted so no need to spend - hence 0 amount
        }
        
        if(ind >= cost.size()){ 
            return INT_MAX; // its not possible to paint all walls - no more painters
        }
        
        if(memo[ind][unpainted_walls] != -1){
            return memo[ind][unpainted_walls];
        }
        
        lli op1 = 0, op2 = 0;
        
         // choose the ith paid painter
        op1 = cost[ind] + 
            compute_paint_amount(ind+1, unpainted_walls - (1 + time[ind]), cost, time);
        
        op2 = compute_paint_amount(ind+1, unpainted_walls, cost, time);
        
        
        return memo[ind][unpainted_walls] = min (op1 , op2);
    }
    
    lli memo[501][501];
    
    int paintWalls(vi& cost, vi& time) {
      
        int n = cost.size();
        
        memset(memo, -1, sizeof(memo));

        return compute_paint_amount(0,n,cost,time);
    }
};

/*

1 2 2 3 5 - cost
5 1 3 1 2
6 2 4 2 3

1 1 1 1 1
1 1 2 3 3


[26,53,10,24,25,20,63,51]
[1,1,1,1,2,2,2,1]



[26,53,10,24,25,20,63,51]
[1,1,1,1,2,2,2,1]

[1,2,3,2]
[1,2,3,2]
[1,2,2,3,5]
[5,1,3,1,2]
[1,2,2,3,5]
[1,1,1,1,1]
[1,2,2,3,5]
[1,1,2,3,3]
[1]
[2]
[3]
[1]


*/
