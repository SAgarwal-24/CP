/*
link: https://leetcode.com/problems/k-th-smallest-prime-fraction/

- Really good and head breaking problem 
- key points :
      1. Main part is moulding solution thinking process in such a way that we can apply B.S. on it
      2. counting number of fractions 

- read time complexity 


- important BS questions list and links - https://leetcode.com/discuss/study-guide/3444552/binary-search-on-answer-template-generic-template

- Category : BS special case: LC Study Guide: Binary Search on Answer
Must do to master the binary search on answer:

https://leetcode.com/problems/minimum-time-to-repair-cars/ <-- this one is gold!!!
https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
https://leetcode.com/problems/koko-eating-bananas/
https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
https://leetcode.com/problems/magnetic-force-between-two-balls/
https://leetcode.com/problems/sell-diminishing-valued-colored-balls/
https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
https://leetcode.com/problems/divide-chocolate/ <-- this one is gold!!! (hard)

*/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) {
        

        
        int  n = a.size();
        
        // binary search on fraction b/w [0,1]
        double lo = 0,  hi = 1.0;
        
        while(lo <= hi){
            
            
            // check num_of_fractions less than mid_fraction
            double mid_fraction = (lo + hi)/2;
            
           // cout<<lo<<","<<mid_fraction<<","<<hi<<endl;
            
            // count no of fractions (a[i]/ a[j]) which are smaller than mid_fraction (ie no of pairs of a[i], a[j])
            int   num_smaller_fractions = 0.0
                , kth_numerator_idx = 0
                , kth_dinomenator_idx = 0;
            
             
            double max_fraction = 0.0;
            
            for(int i=0; i<n; i++){
                
               
                int j = 1;
                while(j<n && a[i] >= mid_fraction * a[j]){  // a[i] / a[j]   >= mid 
                    j+=1;
                }
                
                num_smaller_fractions += n - j;
                
                if(j==n){
                    break;
                }
                
                 // Calculate the fraction
                double calFraction = static_cast<double>(a[i]) / a[j];
                
             //   cout<<"max_fraction: "<<max_fraction<<" , calFraction: "<<calFraction<<" , "<<a[i]<<", "<<a[j]<<endl;
                
                if( max_fraction  < calFraction  ){
                    max_fraction = calFraction;
                    
                 //   cout<<"updated max_fraction: "<<max_fraction<<endl;
                    
                     kth_numerator_idx =  i;
                     kth_dinomenator_idx = j;
                }
                
               
                
            }
            
            
        //    cout<<"num_smaller_fractions: "<<num_smaller_fractions<<endl;
            
            // update binary search window ie lo, hi
            
            if(num_smaller_fractions == k){ // wow we got it
                return {a[kth_numerator_idx], a[kth_dinomenator_idx]};
            }
            
            
            if(num_smaller_fractions < k){ // we want more fractions lesser than mid_fraction so increase mid_fraction in next iteration
                lo = mid_fraction;
            }
            else{
                hi = mid_fraction;
            }
            
            
        }
        
        return {};
    }
};

/*

[1,2,3,5]
3
[1,7]
1
[1,13,17,59]
6




*/
