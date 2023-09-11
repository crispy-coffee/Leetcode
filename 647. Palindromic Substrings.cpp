class Solution {
public:
    int countSubstrings(string s) {
        
        int result = 0;

        for(int i=0; i<s.size(); i++){
            int left = i, right = i;

            while(left>=0 and right<s.size() and s[left] == s[right]){
                result++;
                left--;
                right++;
            }

            left = i;
            right = i+1;

            while(left >=0 and right<s.size() and s[left] == s[right]){
                result++;
                left--;
                right++;
            }
        }
        return result;
    }
};