/*

link - https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
     - https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/discuss/2207169/More-Efficient-Max-Heap-Solution-or-JAVA-Explained

1. In this question, we need to completely get rid of the idea that we're working with characters. From now on, we'll be working with integers; primarily the frequencies of each character

## why greedy works?
2. Greedy works since we can only delete characters (we cannot add or replace characters).

Time complexity: O(n + klogk) where k represents the number of frequencies.
Space complexity: O(k) since each data structure is storing up to k different frequencies.



*/


class Solution {
public:
    
    void print(priority_queue<int> pq){
        
        while(!pq.empty()){
            cout<<pq.top()<<" ";
            pq.pop();
        }
        
        cout<<endl;
        
    }
    
    int minDeletions(string s) {
        
        int freq[26] = {0};
        int minDeletions = 0;
        int mxFreq  = 0;
        
        for(auto ch: s){    
            freq[ (ch-'a') ] += 1;
        }
        
        int freqMap[1000001] = {0};
        priority_queue<int>pq;
        
        for(int i=0; i<26; i++){
            freqMap[ freq[i]  ] += 1;
            mxFreq =  max(mxFreq, freq[i]);
        }
        
        for(int i=0; i<=mxFreq; i++){
            
            if(freqMap[i] == 0){
                pq.push(i);
                continue;
            }
            
             // print(pq);
            
            while(freqMap[i] > 1 && !pq.empty()){
                minDeletions += (i-pq.top());
                pq.pop();
                freqMap[i] -= 1;
            }
            
            if(freqMap[i] > 1){
                minDeletions += (freqMap[i] - 1) * i;
            }
            
         
        }
        
        return minDeletions;
        
    }
};
/*
"aab"
"aaabbbcc"
"ceabaacb"
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaabccccccccccddddd"
"d"

"abcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwzabcdefghijklmnopqrstuvwxwz"

*/
