class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string excel = "";
        int remainder = 0;
        while(columnNumber > 0){
            columnNumber--;
            remainder = columnNumber%26;
            excel += ('A' + remainder);
            columnNumber /= 26;
        }
        
        reverse(excel.begin(), end(excel));
        return excel;
    }
};