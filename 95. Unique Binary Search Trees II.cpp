class Solution {
public:
    vector<TreeNode*> Recursion(int start, int end){
        if(start == end)
            return {new TreeNode(start)};

        if(start>end)
            return {NULL};

        vector<TreeNode*> result;
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left = Recursion(start, i-1);
            vector<TreeNode*> right = Recursion(i+1 , end);
            
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return Recursion(1, n);
    }
};