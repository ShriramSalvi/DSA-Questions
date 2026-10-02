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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(!root)return {};

        
        deque<TreeNode*>dq;

        dq.push_back(root);

        vector<vector<int>>ans;

        while(!dq.empty()){
            int size = dq.size();
            
            vector<int>temp;
            while(size--){
                temp.push_back(dq.front()->val);
                if(dq.front()->left)dq.push_back(dq.front()->left);
                if(dq.front()->right)dq.push_back(dq.front()->right);
                dq.pop_front();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};