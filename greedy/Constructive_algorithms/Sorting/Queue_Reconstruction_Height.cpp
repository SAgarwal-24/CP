// link: https://leetcode.com/submissions/detail/734500429/

// https://leetcode.com/problems/queue-reconstruction-by-height/

/*
Nice sorting logic and different Logic involved
kind of out of box question
*/


class Solution {
public:
    
    #define vi vector<int>
    #define vvi vector<vector<int>> 
    
    
    void print(vvi &v){
        
         for(int i=0; i<v.size(); i++){
        
            int numOfPeopleOnLeft = v[i][1];
            int height = v[i][0];
             
             cout<<"["<<height <<","<<numOfPeopleOnLeft<<"] ";
         }
        
        cout<<endl;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        
        sort(people.begin(),  people.end());
      
        
  
        print(people);
        
        int i, n = people.size();
        
        vvi ans (n, vector<int>(2, -1));

        
        //Fix shortest Person - 1st position
        int firstPersonPos = 0;
        int firstPersonHeight = 1e6+3;
        for(i=0; i<n; i++){ //  [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
            
            int numOfPeopleOnLeft = people[i][1];
            int height = people[i][0];
            
            if(numOfPeopleOnLeft == 0 and firstPersonHeight>height){
                firstPersonHeight = height;
                firstPersonPos = i;
                // cout<<"## ["<<height <<","<<numOfPeopleOnLeft<<"] ";
            }
        }
        
        // cout<<"firstPersonPos: "<<firstPersonPos<<endl;
        
        ans[0] = people[firstPersonPos];
        
        for(i=0; i<n; i++){
            
            if(i==firstPersonPos){
                 continue;
            }
            
            int numOfPeopleOnLeft = people[i][1];
            int height = people[i][0];
            
            int cnt = numOfPeopleOnLeft;
            
            // cout<<"Current: "<<height<<", "<<numOfPeopleOnLeft<<endl;
            
            //find correct location of ith people
            for(int j=0; j<n; j++){
                
                // cout<<ans[j][0] << " - " << height <<endl;
                
                if(ans[j][0] != -1){ //someone is allocated this final position 
                   
                    if(ans[j][0] >= height)
                    cnt --;
                }
                else{  // this position is empty
                    
                    if(cnt <= 0){
                        ans[j][0] = height;
                        ans[j][1] = numOfPeopleOnLeft;
                        break;
                    }
                    else{
                        cnt--;
                    }
                }
                
                
            }
            
             // print(ans);
        }
        
        return ans;
    }
};
