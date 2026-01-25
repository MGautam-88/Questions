class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if (n == 1) return a[0];
        if (n == 2) return max(a[0], a[1]);

        vector<int> inc(n, 0),exc(n, 0);

        inc[0] = a[0];
        inc[1] = max(a[0], a[1]);

        exc[0] = 0;
        exc[1] = a[1];
        exc[2] = max(a[1], a[2]);

        for (int i = 2; i < n - 1; i++) {
            inc[i] = max(a[i] + inc[i - 2], inc[i - 1]);
            exc[i + 1] = max(a[i + 1] + exc[i - 1], exc[i]);
        }
        return max(inc[n - 2], exc[n - 1]);
    }
};
