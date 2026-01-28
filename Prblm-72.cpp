class Solution {
public:
    int minDistance(string a, string b) {
        // int n = a.size();
        // int m = b.size();
        // if(n==0)return m;
        // if(m==0)return n;
        // //dp[i][j]will represent no of opr needed to convert the 1st 'i'
        // chars of a to j chars of b vector<vector<int>>
        // dp(n+1,vector<int>(m+1,0));//1st atring i.e a along rows dp[0][0]=0;
        // for(int j=1;j<=m;j++){
        //     dp[0][j]=j;
        // }
        // for(int i=1;i<=n;i++){
        //     dp[i][0]=i;
        // }

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1];//do nothing
        //         else{
        //             dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
        //         }
        //     }
        // }

        // return dp[n][m];

        // -----------------------------SPACE Optimization----------------------------------------
        int n = a.size();
        int m = b.size();
        vector<int> dp(m + 1, 0);
        dp[0] = 0;
        for (int j = 1; j <= m; j++) {
            dp[j] = j;
        }

        for (int i = 1; i <= n; i++) {
            int prev = dp[0];
            dp[0] = i; // dp[i][0]=i
            for (int j = 1; j <= m; j++) {
                int t = dp[j]; // top as it will change later we keep it for diag track
                if (a[i - 1] == b[j - 1]) dp[j] = prev;

                else if (j > 0) {
                    dp[j] = 1 +min({prev, dp[j],dp[j - 1]}); // dp[j-1]->left and prev is diagonal
                }
                prev = t; // the previous diag elem
            }
        }

        return dp[m];
    }
};

// dp[i-1][j-1] --> replace i-1 th of a with j-1th of b
// dp[i-1][j] --> delete the i-1th char of a
// dp[i][j-1] --> add the j-1th char of b
