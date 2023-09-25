class Solution {
public:
    char findTheDifference(string s, string t) {
        
        /*
        vector<int> alphabet(26,0);

        for(auto ch:t){
            alphabet[ch-'a']++;
        }

        for(auto ch:s)
            alphabet[ch-'a']--;

        for(int i=0; i<26; i++){
            if(alphabet[i])
                return i+'a';
        }
        return 'z';
        */

        int alphabet = 0;
        for(auto ch:t){
            alphabet += ch-'a';
        }

        for(auto ch:s)
            alphabet -= ch-'a';

        return alphabet+'a';

    }
};