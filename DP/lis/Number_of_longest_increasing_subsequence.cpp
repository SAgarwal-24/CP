/*
link - https://leetcode.com/problems/number-of-longest-increasing-subsequence/

(interview type question)

recommended problems by leetcode
 - https://leetcode.com/problems/longest-increasing-subsequence-ii/
 - https://leetcode.com/problems/longest-continuous-increasing-subsequence/

*/

class Solution {
public:
    
    #define pb push_back
    #define ff first
    #define ss second
    #define vi vector<int>
    #define vvi vector<vi>
    #define all(x) (x).begin(), (x).end()
    #define sz(x) ((ll)(x).size())
    #define watch(x) cout << (#x) << " -> "  << (x) << endl
    
    void print(vi &a){
        
        for(auto x:a){
            cout<<x<<" ";
        }
        
        cout<<endl<<"---\n";
    }
    
    int findNumberOfLIS(vi& a) {
        
        int numberOfLIS = 0, l = 0, r = 0, n = a.size(), maxLisLen = 0;
        
        vi len(n, 1);
        vi count(n, 1); // cnt[i] = count of no. of longest increasing subsequences with len[i] 
        
   
        for(l=n-1; l>=0; l--){ // iterate backwards
            
            for(r=l+1; r<n; r++){
                
                if( a[l] >= a[r] ){
                    continue;
                }
                          
                // -> a[l] < a[r]  ===> a[l] can be added before subsequence starting with a[r]
                                               
                if(len[l] < len[r]+1){
                    len[l] = len[r]+1;                    
                    count[l] = count[r]; // first time - count[l] = no of subsequence with starting with a[l] = no of subsequence with starting with a[r]
                }
                else if(len[l] == len[r]+1){
                    count[l] += count[r]; // next time onwards - count[l] increments as it adds before different subsequences starting with a[r]
                }

            }
            
            maxLisLen = max( maxLisLen, len[l]);
        }
        
//         print(len);
//         print(count);
        
        for(int i=0; i<n; i++){      
            numberOfLIS += (maxLisLen == len[i]) ? count[i] : 0;
        }
        
        
        return numberOfLIS;
    }
};

/*

a -> 1 2 3 6 5 4 7
l -> 1 2 3 4 4 4 5

1 2 3 6 7
1 2 3 5 7
1 2 3 4 7

seq -> [1,2,1,2,1,2,1,2]
numOfLIS = 10 = 4 + 3 + 2 + 1 

 1 2,2,2,2   (4)
 1 2,2,2     (3)    
 1 2,2       (2)
 1,2         (1)
 
 
  4, 7
 
 
 
[1,3,5,4,7]
[2,2,2,2,2]
[1,3,4,4,7]
[1]
[1,2]
[1,2,2]
[5,1,5,2,3]
[1,2,1,2,1,2,1,2]

*/
