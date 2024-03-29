//https://leetcode.com/problems/expression-add-operators/

class Solution {
public:
    
    vector<string>ans;
    int n=0, target=0 ;
    
    void fun(string &num,long cur, int start, string path,long prev){
        
         //cout<<path<<" -> "<<cur<<" "<<target<<endl;
        
        if(start==n){
            
            //cout<<path<<" -> "<<prev<<" "<<cur<<" "<<target<<endl;
            
            if(cur == target){
                
                ans.push_back(path);
               
            }
            
             return ;
        }
        
        long long term = 0;
        string s = "";
        
        for(int i=start;i<num.size();i++){
            
            if(start<i and num[start]=='0') //skip leading zeros
                break;
            
             s += num[i];
             term = term*10 + num[i]-'0';
            
            if(start==0){
                fun(num,term,i+1,path+s,term); //no operation, just pick-> if start==0 ie first term of expression 
            }else{
                
                // these are not first term of expression so operator must come before we append this to path 
                //cout<<"st: "<<start<<", i: "<<i<<", cur: "<<cur<<", path: "<<path<<endl;
                
                fun(num,cur-prev+prev*term,i+1, path+"*"+s,prev*term);
                fun(num,cur+term,i+1, path+"+"+s,term);
                fun(num,cur-term,i+1, path+"-"+s,-term);
            }
        }
        
    
        
    }
    
    vector<string> addOperators(string num, int target) {
        
        
        this -> n = num.size();
        this -> target = target;
      
        string path = "";
        
        fun(num, 0, 0, path, 0);
      
        return ans;
        
    }
};

/*
"135523"
22
"99"
0
"99"
99
"2147483648"
-2147483648

----(leading 0 testcase )
"105"  
5

-> ["1*0+5","1*05","10-5"] in this "1*05" contains leading zeros ie 05 is interpreted as 5 which is not allowed

*/

