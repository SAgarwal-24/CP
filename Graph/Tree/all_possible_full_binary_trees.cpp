/*
    
  --------- Jai Sia Ram -------------

- link : https://leetcode.com/problems/all-possible-full-binary-trees/
-  a full binary tree will always have an odd number of nodes (root node + even child nodes).
- google + amazon interview question

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */




class Solution {
public:
    
    unordered_map<int, vector<TreeNode*>> memo;
    
    vector<TreeNode*> allPossibleFBT(int n) {

        if( (n%2) == 0 ){  // full binary tree with even nodes not possible
            return {};
        }
        
        if(n==1){ 
            return {new TreeNode()};
        }
        
        if(memo.find(n) != memo.end()){
            return memo[n];
        }
        
        vector<TreeNode*> allTrees;
        
        // simple brute force to check all possible configurations
        for(int i=1; i<n; i=i+2){ // i = i+2 bcz all for i=even  we wont get odd no in left and right subtree
            
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right   = allPossibleFBT(n-i-1);
            
            for(auto l : left){
                for(auto r: right){
                    TreeNode* possibleRoot = new TreeNode(0, l, r);
                    allTrees.push_back(possibleRoot);
                }
            }
        }
        
        
        return memo[n] = allTrees;
    }
};
