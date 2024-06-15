/**
https://leetcode.com/problems/ipo/

Building intuition was challenging
key point - how to iterate on sorted array(acc. to capital) with heap/priority queue (to get maximum profit project)

*/


class Solution {
public:
    
    #define vi vector<int>
    
    struct Project {
        
        int profit;
        int capital;
    };
    
    bool static cmp(Project p1, Project p2){
        
        return p1.capital < p2.capital; 
    }
    
    int findMaximizedCapital(int k, int w, vi& profits, vi& capital) {
        
        int maxCap = 0, n = profits.size();
        
        vector<Project> projects;
        Project p;
        
        for(int i=0; i<n; i++){
            
            p.profit = profits[i];
            p.capital = capital[i];
            
            projects.push_back(p);
        }
        
        sort(projects.begin(), projects.end(), cmp);
        
        
        priority_queue<int>projectCanBeStarted;
        
        int i=0;
        maxCap = w;
        while(k--){
            
            while(i<n && projects[i].capital <= maxCap){
                // put all the profits for the project we can start and under our captial range
               projectCanBeStarted.push(projects[i].profit);
               i++;
            }
            
           
            if(projectCanBeStarted.empty())
                break;
            
            maxCap += projectCanBeStarted.top();
            projectCanBeStarted.pop();
            
        }
        
       
        
        return maxCap;
        
    }
};
