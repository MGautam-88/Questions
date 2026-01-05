class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        int n = a.size();
        long long s = 0;
        bool neg = false;
        int mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = a[i][j];

                s += abs(x);

                if (x < 0) {
                    neg = (!neg);
                }

                mn = min(mn, abs(x));
            }
        }
        
        if (!neg) {
            return s;
        }
        return s - (2 * mn);
    }
};
