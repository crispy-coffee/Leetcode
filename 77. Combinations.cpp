class Solution {
public:
    vector<vector<int>> ans;
    void Recursion(int start, int end, int k, vector<int> temp){

        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }

        for(int i=start; i<=end; i++){
            temp.push_back(i);
            Recursion(i+1, end, k, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        Recursion(1, n, k, {});
        return ans;
    }
};