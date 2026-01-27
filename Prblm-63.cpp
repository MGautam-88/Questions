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



//-------------------------------SPACE Optimized------------------------------------------

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m = o.size();
        int n = o[0].size();
        if (o[0][0] == 1 || o[m - 1][n - 1] == 1) return 0;

        vector<int> rows(n, 0);
        rows[0] = 1;
        for (int j = 1; j < n; j++) {
            if (!o[0][j - 1])rows[j] = 1;
            else break;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if ((o[i - 1][j]))rows[j] = 0;
                if ((o[i][j - 1]))rows[j - 1] = 0;
                //we are not thinking about 2d dp , we are
                //handling it using 1D dp so do not worry about in between state of rows 
                // we need the last m-1 , n-1 th elem only that it!!!!
                else rows[j] = rows[j] + rows[j - 1];
            }
        }
        return rows[n - 1];
    }
};
