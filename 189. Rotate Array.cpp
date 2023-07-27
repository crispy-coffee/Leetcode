class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(), nums.begin()+(n-k));
        reverse(nums.begin()+(n-k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};

/*
Example:-1234567 ,k=3
1.first reverse the numbers form index 0 to n-k;
->4321 567
2.reverse the k elements from the last
->4321 765
3.now reverse the whole nums;
->5671234 Done Answer is here !!!!
*/