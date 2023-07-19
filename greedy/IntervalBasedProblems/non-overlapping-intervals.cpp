/*
link
  https://leetcode.com/problems/non-overlapping-intervals/

resources
 https://www.youtube.com/watch?v=nONCGxWoUfM
 https://www.youtube.com/watch?v=BTObFnHbD4U&t=813s


merge interval based problems
  https://leetcode.com/list/?selectedList=rddr2hj7


*/

class Solution {
public:
    
    #define pb push_back
    #define vi vector<int>
    #define vvi vector<vi>
    #define all(x) (x).begin(), (x).end()
    #define sz(x) ((ll)(x).size())
    #define watch(x) cout << (#x) << " -> "  << (x) << endl

    void print(vvi& intervals){
        
        for(auto x: intervals){
            cout<<"["<<x[0]<<","<<x[1]<<"] ";
        }
        
        cout<<endl;
    }
    
    
    
    /*
    
    in approach_1 -> we sort acc. to starting point 
                     so we need to decide whether interval[l] endpoint is < or > interval[r] endpoint
                     and accordingly remove interval[l] or interval[r] whichever is smaller (greedy approach) 
                     
     while in approach_2 -> we sort acc. to end point
                            then we always remove interval[r] as it has greater endpoint
                            and greedily we interval[r] is harmful choice bcz it has more probablity of increasing overlaps
                            hence we remove interval[r] and include interval[l]
                            
        
        both approach have same intution but in approach_2 there is less confusion or less cases
        as we have sort acc. to ending point
    */
    
    static bool cmp(vi &v1,vi &v2){
        
        if(v1[1]<v2[1])return true;
        
        if(v1[1]==v2[1] and v1[0]<v2[0])return true;
        
        return false;
    }
    
    int approach_2(vvi& a) {
        
        int ans=0, l=0, r=0, n=a.size();
        
        sort(all(a),cmp);
        
        while(l<n){
            r = l+1;
            
            while(r<n and a[r][0]<a[l][1]){
                r++;
                ans++;
            }
            
            l = r;
        }
        
        return ans;
    }
    
    
    int approach_1 (vvi& intervals) {
        
        sort(all(intervals)); // sort by starting point 
        
        print(intervals);
        
        int removals = 0, l=0, r=1 , n = intervals.size();
        
        while(r<n){
             
            if(intervals[l][1] <= intervals[r][0]){ // non overlapping - straight forward case
                l = r;
                r++;
                continue;
            }
            
            // overalapping cases
           
            removals++;
            
            if(  intervals[r][1] < intervals[l][1] ){
                l = r; // we remove - intervals[l] bcz of greater ending point otherwise we simply remove interval[r]
            }
            
            r++;
            
        }
        
        return removals;
        
    }
    
    int eraseOverlapIntervals(vvi& intervals) {
        
        // return approach_1(intervals);
        
         return approach_2(intervals);
        
    }
};

/*

  1      6
     2 3
     2   6
       3    7


*
