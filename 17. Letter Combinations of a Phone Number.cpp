class Solution {
public:
    vector<string> str;

    void dfs(int start, string num, vector<string>& code, string child){
        if(child.length() == num.length()){
            str.push_back(child);
            return;
        }

        if(start >= num.length())
            return;

        for(auto& letter: code[num[start]-'0']){
            dfs(start+1, num, code, child+letter);
        }
    }

    vector<string> letterCombinations(string digits) {
        
        if(digits == "")
            return str;

        vector<string> code = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(0, digits, code, "");
        return str;

    }
};