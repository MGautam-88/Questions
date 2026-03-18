class Solution {
public:
    int countSubmatrices(vector<vector<int>>& a, int k) {
        int m=a.size();
        int n=a[0].size();
        int ans=0;
        vector<vector<int>> dp(m,vector<int>(n,a[0][0]));

        for(int j=1;j<n;j++){
            dp[0][j]=dp[0][j-1]+a[0][j];
        }

        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+a[i][0];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=(a[i][j]+dp[i-1][j]+dp[i][j-1])-dp[i-1][j-1];
            }
        }

        int ct=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]<=k)ct++;
            }
        }

        return ct;
    }
};//TC: O(m*n)      and SC : O(m*n)

//--------------------------------------------------------------------------------------------------------------------------------------------------

//In place prefix-sum calcultion 
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& a, int k) {
        if(a[0][0]>k)return 0;
        int m=a.size();
        int n=a[0].size();
        int ans=0;

        for(int j=1;j<n;j++){
            a[0][j]+=a[0][j-1];
        }

        for(int i=1;i<m;i++){
            a[i][0]+=a[i-1][0];
            for(int j=1;j<n;j++){
                a[i][j]+=(a[i-1][j]+a[i][j-1]-a[i-1][j-1]);
            }
        }

        int ct=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]<=k)ct++;
            }
        }

        return ct;
    }
};//TC: O(m*n)         and SC:O(1)

//---------------------------------------------------------------------------------------------------------------------------------------------------

// Further we can reduce the calc inside also , using diff way of calc the sum of curr subMat

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& a, int k) {
        if(a[0][0]>k)return 0;
        int m=a.size();
        int n=a[0].size();
        int ans=0;

        for(int j=1;j<n;j++){
            a[0][j]+=a[0][j-1];
        }

        for(int i=1;i<m;i++){
            int pfx=a[i][0];//har row k a 1st elem
            a[i][0]=a[i-1][0]+pfx;
            for(int j=1;j<n;j++){
                pfx+=a[i][j];//pfx current row ka sum j-1 tak + curr
                a[i][j]=pfx + a[i-1][j];
                // curr row and prev row ka jth idx tak sum that is our curr subMat
            }
        }

        int ct=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]<=k)ct++;
            }
        }

        return ct;
    }
};
