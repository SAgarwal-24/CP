// https://leetcode.com/problems/furthest-building-you-can-reach/

// helpful - https://leetcode.com/problems/furthest-building-you-can-reach/discuss/4739684/DP-greater-Binary-Search-greater-Greedy-or-All-Approaches-Explained

// priorty queue based and binary search both approaches are bit challenging to think but each to understand 


class Solution {
public:
    
    #define vi vector<int>
    
   
    int furthestBuilding(vi& heights, int bricks, int ladders) {
        
        int n = heights.size();
        priority_queue<int, vi, greater<int>>pq;
        
        for(int i=0; i<n; i++){
            
            if(i==n-1)
                return i;
            
            int dif = heights[i+1] - heights[i];
            
            // cout<<i<<"-> "<<pq.size()<<","<<bricks<<endl;
            
            if(dif<=0)
                continue;
            
            pq.push(dif);
            
            if(pq.size() <= ladders){
                continue;
            }
            
            int jump = pq.top();
            pq.pop();
            
            // cout<<"jump: "<<jump<<endl;
            
            if(bricks < jump)
                return i;
            
            bricks -= jump;
        }
        
        return n-1;
    }
};
