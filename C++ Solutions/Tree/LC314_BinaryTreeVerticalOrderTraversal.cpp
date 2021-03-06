/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples 1:

Input: [3,9,20,null,null,15,7]

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7 

Output:

[
  [9],
  [3,15],
  [20],
  [7]
]
Examples 2:

Input: [3,9,8,4,0,1,7]

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7 

Output:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Examples 3:

Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

Output:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // Using ordered map
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));
        while(!q.empty()){
            // for this level which has Size=size
            int size = q.size();
            for(int i = 0;  i < size; i++){
                TreeNode* t = q.front().second;
                int level = q.front().first;
                q.pop();
                m[level].push_back(t->val);
                if(t->left){
                    q.push({level - 1, t->left});
                }
                if(t->right){
                    q.push({level + 1, t->right});

                }
            }
        }
        for(auto& v : m){
            ans.push_back(v.second);
        }
        return ans;
    }
};