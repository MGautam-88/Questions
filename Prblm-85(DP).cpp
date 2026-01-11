class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        if(a.empty() || a[0].empty()) return 0;

        int n= a.size();
        int m= a[0].size();

        vector<vector<int>> dp(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=a[i][j]-'0';//converted chars to int
            }
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                if(dp[i][j]==1){dp[i][j]+=dp[i][j-1];}
            }
        }
        int ans=0;

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                int w= dp[i][j];
                if(w==0)continue;
                int cw=w;

                for(int k=i;k<n && dp[k][j]>0;k++){
                    cw=min(cw,dp[k][j]);
                    int h=k-i+1;
                    ans=max(ans,cw*h);
                }

                cw=w;
                for(int k=i;k>=0&& dp[k][j]>0;k--){
                    cw=min(cw,dp[k][j]);
                    int h=i-k+1;
                    ans=max(ans,cw*h);
                }
            }
        }
        return ans;
    }
};
