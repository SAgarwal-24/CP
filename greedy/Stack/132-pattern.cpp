class Solution {
public:
    
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
    
    bool find132pattern(vi& a) {
        
        int i, n = a.size();
        
        if(n <= 2)
            return false;
        
        int mini = a[0];
        
        stack<pii>st;   // monotonic decreasing stack
        st.push({a[0], a[0]});
        
        for(i=1; i<n; i++){
            
            // check that 
            //-  a[i] is  'k th' candidate ie element with index 'k' or not  (acc. to cond.  i<j<k && a[i]<a[k]<a[j])
            
          
            while( !st.empty() &&  st.top().ff <= a[i]){ // remove useless elements w.r.t a[k] ie elements can't be a[j] or a[i]
                st.pop();
            }
            
           
            if( !st.empty() &&  ( st.top().ss < a[i] && a[i] < st.top().ff )){             
                return true;
            }
            
            
            st.push({a[i], mini});            
            mini = min(mini, a[i]);
        }
        
        return false;
    }
};

/*



[3,5,0,3,4]

 (3, 3)   3
 
 (5, 3)   3
 
 (5, 3)   3
 (0, 3)   3
 
 (5, 3)   3
 (3, 3)   3
  
  (5, 3)   3
  =======================
  
  
 [1,2,3,4]
[3,1,4,2]
[-1,3,2,0]
[1,2,3]
[1,3,2]
[1]
[1,2]
[1,2,3,3,4,5,2]
[3,5,0,3,4]
  


*/
