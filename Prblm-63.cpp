class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m = o.size();
        int n = o[0].size();
        if(o[0][0]==1 || o[m-1][n-1]==1)return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 1; i < m; i++) {
            if (!o[i - 1][0]) {
                dp[i][0] += dp[i-1][0]; // for 0th col}
            }else break;//aage ja hi nahi sakte pehle hi block ho gaya raasta
        }
        for (int j = 1; j < n; j++) {
            if (!o[0][j - 1]) {
                dp[0][j] += dp[0][j-1]; // for 0th col}
            }
            else break;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if ((!o[i][j - 1]))
                    dp[i][j] += dp[i][j - 1];
                if ((!o[i - 1][j]))
                    dp[i][j] += dp[i - 1][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};
