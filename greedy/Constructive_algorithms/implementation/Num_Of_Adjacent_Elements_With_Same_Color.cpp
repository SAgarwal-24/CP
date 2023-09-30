// https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/


class Solution {
public:

    void print(vector<int>a){
        for(int i=0; i<a.size(); i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

    vector<int> colorTheArray(int n, vector<vector<int>>& queries) 
    {
        vector<int>ans(queries.size(), 0);
        vector<int>nums(n, 0);
        int count = 0;
        for (int i = 0; i < queries.size(); i++)
        {
            int index = queries[i][0];
            int newCol = queries[i][1];

            cout<<"count: "<<count<<endl;
            
            int prevCol = (index - 1 < 0)? 0 : nums[index - 1];
            int nextCol = (index + 1 >= n)? 0 : nums[index + 1];
            int oldCol = nums[index];
            
            nums[index] = newCol;
            //===========================================================
            //CHECK CONTRIBUTIONS BEFORE COLORING WITH NEW COLOR
            if (oldCol != 0 && oldCol == prevCol) count--;
            if (oldCol != 0 && oldCol == nextCol) count--;
            //===============================================================
            //CHECK CONTRIBUTIONS AFTER COLORING WITH NEW COLOR
            if (newCol == prevCol) count++;
            if (newCol == nextCol) count++;
            //====================================================================
            ans[i] = count;

            // print(ans);
        }
        return ans;
    }
};
/*


n=7             count
0 1 2 3 4 5 6  
1 0 0 0 0 0 0     0 
1 1 0 0 0 0 0     1
1 1 1 0 0 0 0     2
1 1 1 0 1 0 0     2
1 1 1 1 1 0 0     4
1 1 2 1 1 0 0     4

queries
[[0,1], [1,1], [2,1], [4,1], [3,1], [2,2]]
*/
