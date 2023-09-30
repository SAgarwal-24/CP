//link : https://leetcode.com/problems/first-missing-positive/


class Solution {
public:
    
    void print(vector<int>&a){
        for(auto x:a)
            cout<<x<<" ";
        
        cout<<endl;
    }
    
    int firstMissingPositive(vector<int>& a) {
        
        int n=a.size(),i,ans=0;
        
       // remove -ve numbers and zeros as they are useless 
       // so they must be replaced by such a number which doesn't affect our final answer
       // since max possible answer is n+1
        // so replace -ve no.s and zeros by any number>n+1
        
       for(i=0;i<n;i++){
           if(a[i]<=0)
               a[i]=n+6;  //  number>n+1 won't affect final answer
       }
        
        for(i=0;i<n;i++){
            int ind = abs(a[i]); //index
            
            //we are marking indexes(numbers) in range 1 to n  which are present

            // Condition-1: 'ind' out of range 1 to n is not useful 
            // Condition-2: also if 'ind' is already marked so no need of marking again 
            //              ie a[ind-1]>0 shows 'ind' is not marked yet
            
            if( (ind>=1 and ind<=n) and a[ind-1]>0)
            a[ind-1] = -1*a[ind-1];
            
        
        }
            
            
        // print(a);
        
        for(i=0;i<n;i++){
            if(a[i]>0)
                return i+1;
        }
        
        return n+1;
    }
};

/*
[1,2,3]
[1,2,3,4]
[1,2,3,0,0]
[1,-2]
*/
