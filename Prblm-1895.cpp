class Solution {
public:
    bool check(vector<vector<int>>& g, int r, int c, int k) {
        int t = 0;
        for (int j = c; j < c + k; j++) {
            t += g[r][j];
        }

        for (int i = r; i < r + k; i++) {
            int rs = 0;
            for (int j = c; j < c + k; j++)
                rs += g[i][j];
            if (rs != t)
                return false;
        }

        for (int j = c; j < c + k; j++) {
            int cs = 0;
            for (int i = r; i < r + k; i++)
                cs += g[i][j];
            if (cs != t)
                return false;
        }

        int d=0;
        for(int i=0;i<k;i++){d+=g[r+i][c+i];}
        if(d!=t)return false;

        d=0;
        for(int i=0;i<k;i++){d+=g[r+i][c+k-i-1];}
        if(d!=t)return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        int ans = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for(int wd =2;i+wd<=m&& j+wd<=n;wd++){
                    if(check(g,i,j,wd)){
                        ans=max(ans,wd);
                        if(ans==m || ans==n)return ans;
                    }
                }
            }
        }

        return ans;
    }
};
