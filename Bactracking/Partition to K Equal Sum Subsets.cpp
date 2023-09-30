question link:https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
post link:https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/1495820/C++or-Similarity-and-difference-in-mycode-and-gfg-standard-code


if a newbie(others plz skip this) asks why comparison between code is needed😅?
Understanding the different style of code and recurrence is helpful that's why I tried to figure out the difference between standard solution(like from gfg,which I was seeing approx from last 2 years when I was not good at recursion and today when I am developed with style thinking or approach of problem solving how it is different from standard approach, this habit helped me to see my thought process)

Explanation
a -> [0,1,2........n-1] (n - elements)

sum -> [0,1,2,...k-1] (k - sets)

My notion of code implementation is similar and different from gfg standard code (however final working is same only difference is how reccurence is being governed)

Base case
-> all the elements are exausted or not (mycode)
-> whether k-1 sets out of k sets are filled or not (gfg code)

note: in gfg code they are perfoming recurrence if k-1 sets are not filled ie when a particular set is filled they procced to fill the next set

Recursive case: case for exploring all possiblites - (this portion of mycode is similar to gfg code)

-> for each element a[i](for all n-elements) check all k-sets(loosely speaking) in which we can fit a[i]



class Solution {
public:
    
   
    int sum[16]={0};
    
    int n=0,s=0;
    
    bool subsets(vector<int>&a, int i, int k){
        
        // mycode->base case when all elements(i==n) are exausted this is one of the place where this code is different from  gfg standard code
        // bcz in gfg standard code there base case is depending whether all the k-sets are filled up(exhausted) or not
        
        if(i==n){
            
            //check whether all k subsets have same sum
            for(int j=1;j<k;j++){ 
                
                if(sum[j]!=sum[j-1])
                    return false;
            }
            
            return true;
        }
        
        //for each element a[i] check all subsets  k-sets(or strictly speaking first "i sets" otherwise it will be redundant work)
        
        
        for(int j=0;j<k and j<=i;j++){ 
            
            //check from starting whether this a[i] can be included in sum[j] or not
            // each subset has capacity s/k (ie k partitions each having s/k capacity so that ->  [total sum = k*(s/k) = s]  )
            if(sum[j]+a[i]>(s/k) ){ 
                
                //if this exceeds capacity skip this element 
                continue;
            }
            
            sum[j]+=a[i]; //include the ith element  in jth set 
            
            if(subsets(a,i+1,k)) //if this configuration worked - means we our done and ans=true
                return true;
            
            //if we our at this point means this configuration didn't worked
            // and we need to find other possiblities
            
            sum[j]-=a[i]; //exclude again ith element from the jth set (to explore other possibilities )
            
           
        }
        
        //this configuration didn't worked so return false
        return false;
    }

    bool canPartitionKSubsets(vector<int>& a, int k) {
        
        this->n = a.size();
        
        
        if(n<k)  //not enough elements to distribute in k sets
            return false;
        
        if(k==1) //only one set in which whole array can be fit 
            return true;
        
        int s=0;
        
        for(int i=0;i<n;i++)
            s+=a[i];
        
        if(s%k!=0) //sum is can't distributed equally among k-elements
            return false;
        
        this->s = s;

        
        return subsets(a,0,k);
    }
};
