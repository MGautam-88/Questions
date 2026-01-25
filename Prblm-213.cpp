class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if (n == 1) return a[0];
        if (n == 2) return max(a[0], a[1]);

        vector<int> inc(n, 0),exc(n, 0);

        inc[0] = a[0];
        inc[1] = max(a[0], a[1]);

        exc[1] = a[1];
        exc[2] = max(a[1], a[2]);

        for (int i = 2; i < n - 1; i++) {
            inc[i] = max(a[i] + inc[i - 2], inc[i - 1]);
            exc[i + 1] = max(a[i + 1] + exc[i - 1], exc[i]);
        }
        return max(inc[n - 2], exc[n - 1]);
    }
};


//----------------------------SPACE Optimized --------------------------------

class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if (n == 1) return a[0];
        if (n == 2) return max(a[0], a[1]);

        int i1 = a[0],i2 = max(a[0], a[1]);
        int e1 = a[1],e2 = max(a[1], a[2]);

        for (int i = 2; i < n - 1; i++) {
            int t1=i2;
            i2=max(i2,a[i]+i1);
            i1=t1;

            int t2=e2;
            e2=max(e2,a[i+1]+e1);
            e1=t2;
        }
        return max(e2,i2);
    }
};
