class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector <int> v;
        for(auto i:tokens){

            if(i == "+" || i == "-" || i == "*" || i == "/"){
                int num1 = v.back();
                v.pop_back();
                int num2 = v.back();
                v.pop_back();
                
                if( i == "+") v.push_back(num2+num1);
                else if(i == "-")v.push_back(num2-num1);
                else if(i == "*")v.push_back(num2*num1);
                else v.push_back(num2/num1);
            }else{
                v.push_back(stoi(i));
            }
        }
        return v[0];
    }
};