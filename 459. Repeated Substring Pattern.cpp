class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        /*
        int size = s.size();
        for(int i=0; i<size/2; i++){
            string temp = s.substr(0, i+1);
            bool ans = true;
            for(int j=i+1; j<size;){
                if(temp == s.substr(j, i+1)){
                    j += (i+1);
                }else{
                    ans = false;
                    break;
                }
            }
            if(ans)
                return true;
        }

        return false;
        */

        // O(n) (concatenation) + O(n) (substring extraction) + O(n) (substring search) = O(n) 
        string ss = s+s;
        string temp = ss.substr(1, ss.size()-2);
        if(temp.find(s) == -1)
            return false;
        return true;


    }
};