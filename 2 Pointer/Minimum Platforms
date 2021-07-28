/*
 - Greedy concept to realised is that to find no of overlaps is w.r.t time (Not w.r.t to length)
 -  and while considering overlaps all trains must have atleast 1 second common
 
 -> Scenario -1
 ('#'- time instant during which train will be on platform , '.'-  time instant during which train will not be on platform  )
             
 Train-1:  ---########################################################################################-------
 Train-2:  --############------------------------------------------------------------------------------------
 Train-3:  -------------------###########--------------------------------------------------------------------
 Train-4: -------------------------------------#################---------------------------------------------
 
 If see above scenarion then on 1st glance we may se Train-1, Train-2, Train-3, Train-4 are overlapping , hence we conclude 4 platforms are needed but it wrong
 as for given question we need to find "max no of overlaping trains at single point of time" .
 
 - (Train-1 and Train-2,  Train-1 and Train-3,  Train-1 and Train-4 are overlapping sepreately at different point of time) 
 
 So  at a time max 2 trains are overlapping w.r.t time       
 and                4 trains are overlapping w.r.t length     (if we see the diagram as length instead of time instant)
 
- We can also infer that when Train-1 and Train-2 are overlapping and Train-3 arrives and we were close for getting max_no_of_overlapping_train = 3 but Train-2
  already leaves and we again settle down for max_no_of_overlapping_train = 2 and similar when Train-3 left before Train-4 arrives so again max_no_of_overlapping_train = 2.


-> Scenario -2
 Train-1:  ---########################################################################################-------
 Train-2:  --############------------------------------------------------------------------------------------
 Train-3:  -------------------###########--------------------------------------------------------------------
 Train-4: -----------------------------#################-----------------------------------------------------
 
 In this scenario,  max_no_of_overlapping_train = 3 (w.r.t time)
  as Train -1,3,4 are overalapping at single instant of time.
 


*/
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;



class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    
    
    int findPlatform(int arr[], int dep[], int n)
    {
    	
    	int  ans = 0, platforms_needed = 0,i,j;
    
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	i=0, j=0;
    	
    	while(i<n and j<n){
    	    
    	    if(arr[i] <= dep[j]){
    	        platforms_needed+=1;
    	        i++;
    	    }
    	    else{
    	        platforms_needed-=1;
    	        j++;
    	    }
    	    
    	    ans = max(ans, platforms_needed);
    	}
        
        
        
        
        return ans;
    }
};



int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
} 
