class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& a) {
        int n = a.size();
        if(n==1)return 0;
        int ans=0;

        for(int i=0;i<n-1;i++){
            int x1=a[i][0];
            int x2=a[i+1][0];
            int y1=a[i][1];
            int y2=a[i+1][1];

            int d1=abs(x2-x1);
            int d2=abs(y2-y1);

            ans += max(d1,d2);
        }

        return ans;
    }
};
