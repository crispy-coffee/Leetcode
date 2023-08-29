class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> nocustomer(n+1,0), penalty(n+1,0);
        
        for(int i=1; i<n+1; i++){
            if(i<n and customers[i-1] == 'N')
                nocustomer[i] = nocustomer[i-1]+1;
            else
                nocustomer[i] = nocustomer[i-1];
        }
        
        penalty[n] = 0;

        for(int i=n-1; i>=0; i--){
            if(customers[i] == 'Y')
                penalty[i] = penalty[i+1]+1;
            else
                penalty[i] = penalty[i+1];
        }

        int mini = INT_MAX, closed = -1;

        for(int i=0; i<=n; i++){
            if(penalty[i] + nocustomer[i] < mini){
                mini = penalty[i] + nocustomer[i];
                closed = i;
            }
        }

        return closed;
    }
};