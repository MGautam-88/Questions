class Solution {
public:
    int longestPalindromeSubseq(string a) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        string b =a; 
        reverse(b.begin(),b.end());

        bool f=0;
        for(int j=0;j<n;j++){
            if(a[0]==b[j])f=1;
            if(f)dp[0][j]=1;
        }
        f=0;
        for(int i=0;i<n;i++){
            if(a[i]==b[0])f=1;
            if(f)dp[i][0]=1;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(a[i]==b[j])dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n-1][n-1];
    }
};
