class Solution {
public:

    int Recursion(int i, int j, vector<int>& nums){
        if(i>j)
            return 0;
        
        // Consider player 1 to play for max and expect from player 2 to give min to player 1
        int take_i = nums[i] + min(Recursion(i+2, j, nums), Recursion(i+1, j-1, nums));
        int take_j = nums[j] + min(Recursion(i+1, j-1, nums), Recursion(i, j-2, nums));

        return max(take_i, take_j);
    }

    bool method1(vector<int>& nums){
        int total_score = accumulate(nums.begin(), nums.end(), 0);
        int player1 = Recursion(0, nums.size()-1, nums);

        int player2 = total_score - player1;

        return player1 >= player2;

    }

    int method2(int i, int j, vector<int>& nums){
        if(i>j)
            return 0;
        
        // Whomsoever turn is he will play optimal and choose best
        // and substract the other players score from that
        int take_i = nums[i] - method2(i+1, j, nums);
        int take_j = nums[j] - method2(i, j-1, nums);

        return max(take_i, take_j);
    }       

    bool PredictTheWinner(vector<int>& nums) {
        // method 1
        // return method1(nums);

        // method 2;
        return method2(0, nums.size()-1, nums)>=0;
    }
};