class Solution {
public:
    int maxSubArray(vector<int>& a) {
        
        return maxSubArray2(a);
    }
    
    
     int maxSubArray1(vector<int>& a) {
        
        int gs=INT_MIN, cs=0;

        for(auto ele: a){
            
            cout<<"ele: "<<ele<<endl;
            
            cs = max(ele, cs + ele);
            
            
            gs = max(cs, gs);
            
            cout<<"cs: "<<cs<<endl;
            cout<<"gs: "<<gs<<endl;
            cout<<"----\n";
            
        }

        return gs;
    }
    
    int maxSubArray2(vector<int>& a) {
        
        int gs=INT_MIN, cs=0;

        for(auto ele: a){

            cs = cs + ele;     
            gs = max(cs, gs);          
             if(cs < 0){
                cs = 0;
            }
        }

        return gs;
    }
    
    int maxSubArray3(vector<int>& a) { // this approach fails when there are only negative numbers in array
        
        int gs=INT_MIN, cs=0;

        for(auto ele: a){

            cs = cs + ele;   
            if(cs < 0){
                cs = 0;
            }
            
            gs = max(cs, gs);          
             
        }

        return gs;
    }
};
