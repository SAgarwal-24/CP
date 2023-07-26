/*

link : https://leetcode.com/problems/minimum-speed-to-arrive-on-time

learings
 - double and int - promotion  - https://stackoverflow.com/questions/13663545/does-one-double-promote-every-int-in-the-equation-to-double
 - https://en.cppreference.com/w/cpp/language/operator_precedence
 - https://linuxhint.com/convert-int-double-cpp/ (Two Categories of Conversion in C++ - Implicit Type Conversion, Explicit Type Conversion)

leetcode recommended problems
  - https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/
  - https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
  - https://leetcode.com/problems/the-latest-time-to-catch-a-bus/
  - https://leetcode.com/problems/minimize-maximum-of-array/
*/

class Solution {
public:
    
    #define pb push_back
    #define vi vector<int>
    #define vvi vector<vi>
    #define vd vector<double>
    #define all(x) (x).begin(), (x).end()
    #define sz(x) ((ll)(x).size())
    #define watch(x) cout << (#x) << " -> "  << (x) << endl
    
    
    bool checkTravel(vi& dist, int speed, double hour){
        
        double timeTaken = 0.0;
        int  n = dist.size();
        
        for( int i=0; i<n; i++ ){  // iterating through all trains
            timeTaken +=  i<n-1 ? (dist[i] + speed-1)/ speed : dist[i] / (double) speed ;
        } 
        
        return timeTaken <= hour;
    }
    
    int minSpeedOnTime(vi& dist, double hour) {
        
        int i, n = dist.size();
        
     
        int minTime = 1e8, lo = 1, hi = 1e7;
        
        while(lo <= hi){
            
            int mid = lo + (hi-lo)/2;

            if( checkTravel(dist, mid, hour) ){
                minTime = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
            
        }
        
        return minTime == 1e8 ? -1 : minTime ;
        
    }
};

/*
[1,3,2]
6
[1,3,2]
2.7
[1,3,2]
1.9
[1]
1
[2]
1
[3,4,5,6,3]
4.6
[3,4,5,6,3]
1000000
[1,1,100000]
2.01

*/
