class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        
        int i,n=a.size(),sum=0;
        
        map<int,int>fre;
        fre[0]=-1;
        
        for(i=0;i<n;i++){
            
            sum += a[i];
            
            //if the sum % k is present previously
            if(fre.find(sum%k)!=fre.end() ){
                
                //previous occurence should be at gap of atleast two
                if(i-fre[sum%k]>=2)
                return true;
                
                // else part is empty as we need first occurence so that gap is atleast two
                
                
            }
            else{
                
                // if there is no previous occurence then store it
                fre[sum%k]=i;
            }
            
          
            
        }
        
        return false;
    }
};

/*

[23,2,4,6,6]
7
[23,2,4,6,7]
6
[23,2,6,4,7]
6
[23,2,6,4,7]
13
[1,2,3,4,5]
7
[1,2,3,4,5]
3
[1,2,3,4,5]
9
[0]
3
[1]
4
[0,1]
2

*/
