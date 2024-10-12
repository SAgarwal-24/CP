/*
https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/
https://www.youtube.com/watch?v=w_mHlUZIcas

approach - It is event based 1 problem , need 2 data structures seperately to track - occupied and empty seats
            - Need 1 min heap to track - occupied seats - acc. to min release time <= arrival time of friend
            - Need 1 set - to store empty seats 

mistake done - was trying to solve using 1-priority queue - to track chairs
 
*/

class ChairInfo{
    
        int chairAvailableTime;
        int chairNum;
    
      public:  
    
        ChairInfo(int chairAvailableTime, int chairNum){
            this->chairAvailableTime = chairAvailableTime;
            this->chairNum = chairNum;
        }
        
        
            int getChairAvailableTime() const {
                return chairAvailableTime;
            }
        
            int getChairNum() const {
                return chairNum;
            }
};


class Solution {
public:
    
    #define vi vector<int>
    #define vvi vector<vi>
    
    
    
    class chairComparator {
        
        public: 
        bool operator()(ChairInfo c1, ChairInfo c2){
            
            if(c1.getChairAvailableTime() > c2.getChairAvailableTime()){
                return true;
            }
            
            if(c1.getChairAvailableTime() == c2.getChairAvailableTime()
               && c1.getChairNum() > c2.getChairNum()){
                return true;
            }
            
            return false;
        }
    };
    
    int smallestChair(vvi& friendTimings, int targetFriend) {
        
        int n = friendTimings.size();
  
        for(int i=0; i<n; i++){
            friendTimings[i].push_back(i);
        }
        
        // sort acc. to earliest arrival time of friend
        sort(friendTimings.begin(), friendTimings.end());
        
        vi chairAvaibility(n , 1);
        vi friendsAssignedChair(n, -1);
        priority_queue<ChairInfo, vector<ChairInfo>, chairComparator> occupiedChairs; 
        set<int>emptyChairs; // gives min empty chair
        
        // insert empty chairs
        for(int i=0; i<n; i++){
           emptyChairs.insert(i);
        }
        
            
        for(int i=0; i<n; i++){
            
            int arrival = friendTimings[i][0];
            int leave   = friendTimings[i][1];
            int friendIndex = friendTimings[i][2];
            
           
            
            // check if we can release already occupied chairs
            while(!occupiedChairs.empty() 
                  && occupiedChairs.top().getChairAvailableTime() <= arrival){
                
                // insert relased into emptyChairs set
                emptyChairs.insert(occupiedChairs.top().getChairNum());
                
                occupiedChairs.pop();                
                               
            }
            
            int assignedChair = *emptyChairs.begin();
            emptyChairs.erase(assignedChair);
            occupiedChairs.push(ChairInfo(leave, assignedChair));
            
             // cout<<friendIndex<<"- "<<assignedChair<<endl;
            
            if(friendIndex == targetFriend){
                return assignedChair;
            }
        }
        
        
        
        return -1;
        
    }
};

/*

 charis - 0  1  2  3  4  5  6
    
          1  1 
        
        

friends
  -0     1     2
[[1,4],[2,3],[4,6]],



*/
