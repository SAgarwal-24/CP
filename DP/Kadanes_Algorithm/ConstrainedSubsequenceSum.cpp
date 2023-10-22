/*

Sliding window + dp (bottom up approach like LIS  And Kadanes Algorithm ) 
*/

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
    
    /*
     Note - We need to know the maximum in the window of size k
    
    */
    int bottom_up_heap_approach(vi& a, int k){ // O(nlogn) -- accepeted - :)
        
        int n = a.size(), ans = 0;
        
        int constrained_subsequence_sum = 0;  // constrained_subsequence_sum = stores max  Constrained Subsequence till now achieved 
        
        ans = a[0]; 
        constrained_subsequence_sum = a[0]; // base case - if there is only one  element - then it is the max element - even if it is non neg. - bcz our subsequence is non empty 
        
        priority_queue<pii>pq; 
        pq.push({a[0], 0});
        
        for(int i=1; i<n; i++){
            
            // removed those maximum elements - who doesn't falls into - window of size k 
            while( !pq.empty() && i - pq.top().ss > k){
                pq.pop();
            }
            
            //  maximum in the window of size k
            int preceding_nbr_with_mx_sum = pq.top().ff;
            
            constrained_subsequence_sum = max(a[i],  a[i] + preceding_nbr_with_mx_sum );  // kadane's algorithm type logic           
            ans = max(ans, constrained_subsequence_sum);
            
            pq.push({constrained_subsequence_sum, i});
         
        }
          
        return ans;
      
    }
    
    
    // Note - (bottom up approach like LIS ) 
    int bottom_up_approach(vi& a, int k){ // O(k*n) - O(n*n) - O(10^5 * 10^5) - TLE , since k = n
        
        int n = a.size(), ans = 0;
        
        vi constrained_subsequence_sum(n+1, 0);  // constrained_subsequence_sum[i] = max  Constrained Subsequence sum till a[i]
        
        constrained_subsequence_sum[0] = a[0]; // base case - if there is only one  element - then it is the max element - even if it is non neg. - bcz our subsequence is non empty 
        
        for(int i=1; i<n; i++){
            
            for(int j=i-1; j>=0 && j>=i-k; j--){
                
                constrained_subsequence_sum[i] = max(constrained_subsequence_sum[i],
                                                    a[i] + constrained_subsequence_sum[j]);
            }
            
              ans = max(ans, constrained_subsequence_sum[i] );
        }
        
         // for(int i=0; i<n; i++){
         //     cout<< constrained_subsequence_sum[i] <<" ";
         // }
         // cout<<endl;
        
        return ans;
      
    }
    
    unordered_map<string, int> memo;  // memo["last"+"i"] = max  Constrained Subsequence sum till a[i]
    
    int memo_approach(vi& a, int last, int i, int k){ // O(k*n) - O(n*n) - O(10^5 * 10^5) - TLE , since k = n
        
        if( i>= a.size() ){
            return 0;
        }
        
        string id = to_string(last) + "#" + to_string(i);
        
        if(memo.find(id) != memo.end()){
            return memo[id];
        }
         
        int take = 0, not_take = 0;
         
        not_take =  rec(a, last, i+1, k); 
        
        if(last == -1 || i-last<=k){
          take = a[i] + rec(a, i, i+1, k); 
        }
    
       return memo[id] = max(take , not_take);
    }
   
  
     int rec(vi& a, int last, int i, int k){ // O(2^n) - TLE
        
        if( i>= a.size() ){
            return 0;
        }
         
        int take = 0, not_take = 0;
         
        not_take =  rec(a, last, i+1, k); 
        
        if(last == -1 || i-last<=k){
          take = a[i] + rec(a, i, i+1, k); 
        }
    
           return max(take , not_take); 
        
    }
    
    int constrainedSubsetSum(vi& nums, int k) {
        
         int mx = *max_element(all(nums));
        
         if(mx<0)
            return mx;
    
        // return rec(nums, -1, 0, k);
        
       // return memo_approach(nums, -1, 0, k);
        
        // return bottom_up_approach(nums, k);
        
        return bottom_up_heap_approach(nums, k);
      
        
    }
};

/*

[10,2,-10,5,20]
2
[-1,-2,-3]
1
[10,-2,-10,-5,20]
2
[10,-2,-10,-5,20]
3
[10,-2,-10,-5,20]
5
[10,-2,-10,-5,20,1,2,3]
2
[10,-2,-10,-5,20,1,-4,2,-1,3,-2,9]
2
[10,-2,-10,-5,20,1,-4,2,-1,3,-2,9]
3
[10,-2,-10,-5,20,1,-4,2,-1,3,-2,9]
4
[-1,-4,-40,-11,10,-2,-10,-5,20,1,-4,2,-1,3,-2,9]
2

*/
