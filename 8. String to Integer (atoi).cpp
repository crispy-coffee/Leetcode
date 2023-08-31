class Solution {
public:
    int myAtoi(string& s) {
    
        int i=0;
        while(s[i] == ' '){
            i++;
        }
 
        double ans = 0;
        bool negative = false;
        
        if(s[i] == '-'){
            negative = true;
            i++;
        }else if(s[i] == '+'){
            i++;
        }

        while(i<s.size() and '0' <= s[i] and s[i] <= '9'){
            int num = s[i]-'0';
            ans = ans*10 + num;
            i++;
        }

        if(negative) ans = -ans;

        if(ans > INT_MAX)
            return INT_MAX;
        else if(ans < INT_MIN)
            return INT_MIN;

        return ans;
    }
};
