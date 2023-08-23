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
    int height(TreeNode* root){
        if(!root) return 0;
        
        return max(height(root->left), height(root->right))+1;

    }
    void solve(TreeNode* root, vector<vector<int>> &v, int lvl){
        if(!root) return;

        v[lvl].push_back(root->val);
        solve(root->left, v, lvl+1);
        solve(root->right, v, lvl+1);

    }

    vector<vector<int>> rec(TreeNode* root){
        int h=0;
        h = height(root);
        // cout << "Height: "<< h;
        vector<vector<int>> v(h);
        solve(root, v, 0);
        return v;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        // return rec(root);

        queue<TreeNode*> q;
        vector<vector<int>> result;
        if(!root)
            return result;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0; i<size; i++){
                auto top = q.front();
                q.pop();
                if(top->left)
                    q.push(top->left);
                
                if(top->right)
                    q.push(top->right);
                
                temp.push_back(top->val);
            }
            result.push_back(temp);
        }
        return result;
    }
};