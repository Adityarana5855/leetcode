class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int totalMasks = 1 << n;

        vector<int> sum(totalMasks, 0);

        for(int mask = 1; mask < totalMasks; mask++) {
            int bit = __builtin_ctz(mask);
            int prev = mask ^ (1 << bit);

            sum[mask] = sum[prev] + tasks[bit];
        }

        vector<int> dp(totalMasks, n + 1);

        dp[0] = 0;

        for(int mask = 1; mask < totalMasks; mask++) {

            for(int sub = mask; sub; sub = (sub - 1) & mask) {

                if(sum[sub] <= sessionTime) {
                    dp[mask] = min(dp[mask],
                                   dp[mask ^ sub] + 1);
                }
            }
        }

        return dp[totalMasks - 1];
    }
};