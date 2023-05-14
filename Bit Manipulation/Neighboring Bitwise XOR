/*
problem - https://leetcode.com/problems/neighboring-bitwise-xor/description/

Important links

https://leetcode.com/problems/neighboring-bitwise-xor/solutions/3522096/illustrated-step-by-step-solution/
https://leetcode.com/problems/neighboring-bitwise-xor/solutions/3522095/java-c-python-sum-is-even/


*/

class Solution {
public:
    
    #define vi vector<int>
    
    void print(vector<int>& a){
        int i, n = a.size();
        for(i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    
    bool makeOriginal(int ele, vi& derived, vi& original){
        
    
        int n = original.size();
        original[0] = ele;
        
        for(int i=1;i<n;i++){
            original[i] = ( original[i-1]) xor derived[i-1]; 
        }
       
        //check
        bool flag = true;
        
        for(int i=0;i<n;i++){
            if(derived[i] != ( original[(i+1)% n] xor original[i])){
                flag = false;
                break;
            }
        }
               
       
       return flag;
        
    }
    
    bool doesValidArrayExist(vi& derived) {
        
        int i, n = derived.size();
        
        /* -- APPROACH 1 ---
        vi original(n, -1);
        
        // --- assume first element is 0 ----
        if ( makeOriginal(0, derived, original) ){
            return true;
        }
    
        // --- assume first element is 1 ----
        original.resize(n, -1);
        if ( makeOriginal(1, derived, original) ){
            return true;
        }
               
        return false;
        */

        // -- APPROACH 2 ---
        int sumXor = 0;
        for(i = 0; i<n; i++){
            sumXor = sumXor xor derived[i];
        }

        return sumXor == 0;
    }
};

