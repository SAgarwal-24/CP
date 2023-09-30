/*
https://leetcode.com/problems/maximum-compatibility-score-sum/discuss/1381401/C++-or-Backtracking-or-Explanation
*/

class Solution {
public:
    
    int m,n;
    int ans=0;
    
    #define vvi vector<vector<int>>
    #define vi vector<int>
    
    // s1 s2 s3  -- i
    // m1 m2 m3 --- j 
    // pair ith student and jth mentor
    
    int compatibility(vi &student, vi &mentor){
        
        int score=0, i;
        
        for(i=0;i<n;i++){
            score+=(mentor[i]==student[i]);
        }
        
        return score;
    }
    
    void fun(vvi &students, vvi &mentors, int i, int sum, int assign[]){
        
        if(i==m){
            
            ans = max(ans, sum);
            return ;
        }
        
        for(int j=0; j<m; j++){
            
            if(assign[j] == 0){ // student - i and mentor - j (are paired up)
                
                // compatibility score of student-i and mentor-j
                int score = compatibility(students[i], mentors[j]);
                
                assign[j] = 1;
                fun(students, mentors, i+1, sum+score, assign);
                assign[j] = 0; // back track 
            }
        }
    }
    
    int maxCompatibilitySum(vvi & students, vvi & mentors) {
        
        this-> m = students.size();
        this-> n = students[0].size();
        
        int assign[8]={0};
        
        int sum=0;
        fun(students,mentors,0,sum,assign);
        return ans;
    }
};
