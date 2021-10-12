// link- https://leetcode.com/problems/bitwise-and-of-numbers-range/


/*

reference video  - https://www.youtube.com/watch?v=-qrpJykY2gE&t=1s

     4 3 2 1 0
16 - 1 0 0 0 0
19 - 1 0 0 1 1
-----------------
     1 0 0| _ _
(common)   (uncommon)



17-  1 0 0 0 1
19 - 1 0 0 1 1
-----------------
     1 0 0|_ _
(common)   (uncommon)

-> Goal : To get AND of range
        : That is -
        : remove uncommon portion and extract common portion and length of uncommon portion
        

Reasoning : Since bits as we move from smaller no to bigger no 
          :  then it is LSB which keeps on flipping and changing more as compared to MSB
          : or more strictly speaking it is less weight bits position which flips more than heavier weight bits position
          
          Approach - 1
          : - So we have to move from right to left and 1st position where we get different bits then we can stop there
          :   bcz after that bits will be different definetly in the range of [L,R]
          
          Approach - 2 
          : We can apply Approach - 1  in opposite way
          - ie instead of moving from-> right to left (or MSB to  LSB)
          
          : We can move from-> left to right(or LSB to MSB)
          - ie while moving from left to right(by doing right shift) we are removing uncommon portion 
          
          - ie each time we do a right shift if (left_no != right_no)
          - then we are eating up uncommon portion and keep account of uncommon length (see code uncommon_len++ )
          
          - At last we only common_portion is left and we just left shift it uncommon_len times to append zeros and generate AND 
*/


class Solution {
public:
    int rangeBitwiseAnd(int left_no , int right_no) {
        
        // uncommon_len is to keep account of length of uncommon portion 
        
        int uncommon_len=0, common = 0;
        
        //while loop to eat up all uncommon portion
        while(left_no!=right_no){
            
            left_no = left_no>>1;
            right_no = right_no>>1;
            
            uncommon_len++;
        }
        
        common = right_no;  // at this point m=n ie only common portion will be left 
        
        
        return common << uncommon_len; 
        
        
    }
};




