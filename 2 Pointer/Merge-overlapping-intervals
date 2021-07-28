// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    
    #define all(x) x.begin(), x.end()
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>ans;
        
        sort(all(intervals));
        
        int i=0,j, start = 0, end=0, n=intervals.size();
        
        while(i<n){
            
            start = intervals[i][0];
            end   = intervals[i][1];
            
            j = i+1;
            
            while(j<n and intervals[j][0]<=end){
                end = max(intervals[j][1], end);
                j++;
            }
            
            vector<int>tem(2);
            tem[0] = start, tem[1] = end;
            ans.push_back(tem);
            
            i=j;
        }
        
        return ans;
    }
};
