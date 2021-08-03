class Solution {
public:
    
    int subarraySum(vector<int>& a, int k) {
        
        int i,st=0, n=a.size(), ans=0,sum=0;
        
        map<int,int>fre;
        fre[0]=1;
        
        for(i=0;i<n;i++){
            
            sum+=a[i];
            
            if(fre.find(sum-k)!=fre.end()){
                ans+=fre[sum-k];
            }
            
            fre[sum]+=1;
        }
        
      
        
        return ans;
        
    }
};
/*
[1,1,1]
2
[1,2,3]
3
[1,2,3,4,3,2,3,4,2]
5
[1,2,3,-1,-2,4,1,3,2,3,4,2]
5
[1]
1
[3]
3
[4,5]
4
[1,6,1]
7

*/
