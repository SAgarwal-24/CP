// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

class Solution {
public:
    
    int maximize(string a, int k, char ch){
        
         int ans = 0, n = a.size(), st=0, end=0;
        
        for(end=0; end<n; end++){
            
            if(!(a[end]==ch)){
                k--;
                
                while(k<0){
                    if( !(a[st]==ch) ){
                        k++;
                    }
                    st++;
                }    

             }
               
            
            
            ans = max(ans, end-st+1);
            
        }
        
         // ans = max(ans, end-st+1);
        
        return ans;
        
    }
    
    int maxConsecutiveAnswers(string a, int k) {
        
        int ans = 0;
        
        ans = max(ans, maximize(a, k, 'T'));
        
        // cout<<"t: "<<ans<<endl;
        
        ans = max(ans, maximize(a, k, 'F'));
        
        return ans;
       
    }
};
