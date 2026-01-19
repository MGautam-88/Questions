class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = (int)mat.size();
        int m = (int)mat[0].size();
        int PSUM[n + 1][m + 1];
        memset(PSUM, 0, sizeof(PSUM));
        for(int i = 1; i <= n; i ++){
            int row_sum = 0;
            for(int j = 1; j <= m; j ++){
                row_sum += mat[i-1][j-1];
                PSUM[i][j] = PSUM[i - 1][j] + row_sum;
            }
        }
        
        auto sum_square = [&](int r, int c, int k) -> int{
            int A = PSUM[r][c];
            int B = PSUM[r-k][c];
            int C = PSUM[r][c-k];
            int D = PSUM[r-k][c-k];
            
            return A - B - C + D;
        };
        
        auto binary_search = [&](int r, int c) -> int{
            int low = 0;
            int hig = min(r, c);
            while(low < hig){
                int mid = (low + hig + 1) / 2;
                if(sum_square(r, c, mid) <= threshold){
                    low = mid;
                }
                else{
                    hig = mid - 1;
                }
            }
            return low;
        };
        
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                ans = max(ans, binary_search(i, j));
            }
        }
        return ans;
    }
};
