/*
https://leetcode.com/problems/longest-happy-string/
greedy solution also exists
learning : use of heap in pure greedy based problem, heap makes easy to track max and second max character during each iteration
*/

class Letter {
  
  public:
    char ch;
    int fre;
    
  
    Letter(char ch, int fre){
        this->ch = ch;
        this->fre =fre;
    }
    
};

class happyStringComparator{
    
 public:
    bool operator()(Letter l1, Letter l2){
        
        return l1.fre < l2.fre;
    }
};

class Solution {
public:
    
    bool isValid(string happyStr, char maxFreCh) {
        
        int si = happyStr.size();
        
        if(si <= 1)
            return true;
        
        
        
        if(happyStr[si-1] == maxFreCh && happyStr[si-2] == maxFreCh){
            return false;
        }
        
        return true;
        
    }
    
    string longestDiverseString(int a, int b, int c) {
        
        
        priority_queue<Letter, vector<Letter>, happyStringComparator>pq;
        
        if(a>0){
            pq.push(Letter('a', a));
        }
        
        if(b>0){
            pq.push(Letter('b', b));
        }
        
        if(c>0){
            pq.push(Letter('c', c));
        }
        
         
        string happyStr = "";
        
        while(!pq.empty()){
            
            Letter maxFreCh = pq.top();
            pq.pop();
            
             // cout<<maxFreCh.ch<<", "<<maxFreCh.fre<<endl;
             // cout<<happyStr<<endl;
            
            if( isValid(happyStr, maxFreCh.ch) ){
                happyStr.push_back(maxFreCh.ch);
                maxFreCh.fre -= 1;
                
            }
            else{
                
               
                if(pq.empty()){
                    return happyStr;
                }
                
                // take second most max char from heap
                Letter secondMaxFreCh = pq.top();
                pq.pop();
                    
                happyStr.push_back(secondMaxFreCh.ch);
                secondMaxFreCh.fre -= 1;
                
                if(secondMaxFreCh.fre>0){
                    pq.push(secondMaxFreCh);
                }
            }
            
            if(maxFreCh.fre>0){
                pq.push(maxFreCh);
            }
            
           
             // cout<<happyStr<<endl;
            // cout<<"------\n";
        }
        
        return happyStr;
    }
};

/*

1  1 7

max = 2

2 2 2

7/2 = 3-1

expected
= 4-1 = 3

actual;
1

rev think -> 1 -> 1+1 = 2 -> 2*2 = 4

(actual_max + 1)*2 = max_occuring_char_freq

---------------
a  b  c
7  4  4

----

6 4 4  a
5 4 4  a
5 3 4  b
4 3 4  a
4 
7 4

bc

acbabababacacac

aabaabaababc


*/
