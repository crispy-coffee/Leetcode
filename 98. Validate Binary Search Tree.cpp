class Solution {
public:
    bool solve(TreeNode* root, long long min, long long max){
        if(root == NULL){
            return true;
        }

        if(min < root->val and root->val < max){
            bool left = solve(root->left, min, root->val);
            if(!left)
                return false;
            bool right = solve(root->right, root->val , max);
            return left and right;
        }else{
            return false;
        }

    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
