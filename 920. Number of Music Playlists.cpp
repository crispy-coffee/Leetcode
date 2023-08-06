class Solution {
public:
    int mod = 1000000007;
    int memo[101][101];
    long long Recursion(int curr_goal, int old_songs, int n, int k){

        if(curr_goal == 0 and old_songs == n){
            return 1;
        }

        if(curr_goal == 0)
            return 0;

        if (memo[curr_goal][old_songs] != -1) {
            return memo[curr_goal][old_songs];
        }

        // choose a new song
        long long ans = 0;
        
        ans = Recursion(curr_goal-1, old_songs+1, n, k) * (n - old_songs);

        // Choose a old song
        if(old_songs > k)
            ans = ((Recursion(curr_goal-1, old_songs, n, k) * (old_songs - k))%mod + ans)%mod;

        return memo[curr_goal][old_songs] = ans%mod;
    }   

    int numMusicPlaylists(int n, int goal, int k) {
        memset(memo, -1, sizeof(memo));
        return Recursion(goal, 0, n, k);
    }
};