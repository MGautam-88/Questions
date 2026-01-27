class Solution {
public:
    //-----------RECURSION----------------------
    // int lcs(string &a, string &b,int i,int j){
    //     int n=a.size();
    //     int m=b.size();
    //     if(i==n or j==m)return 0;

    //     if(a[i]==b[j]) return 1+lcs(a,b,i+1,j+1);

    //     return max(lcs(a,b,i,j+1),lcs(a,b,i+1,j));
    //     //jisne future mein max diya hoga (matab return jo max karega) wo rakhe ge 
    // }

    int longestCommonSubsequence(string a, string b) {
        int m=b.size();
        int n=a.size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        bool f=false;
        for(int i=0;i<m;i++){
            if(a[0]==b[i])f=1;
            if(f)dp[i][0]=1;
        }
        f=0;
        for(int j=0;j<n;j++){
            if(b[0]==a[j])f=1;
            if(f)dp[0][j]=1;
        }
        

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(b[i]==a[j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[m-1][n-1];
    }
};
