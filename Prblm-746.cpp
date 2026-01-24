class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        a.push_back(0);
        int n=a.size();
        vector<int> dp(n,0);
        dp[0]=a[0];
        dp[1]=a[1];

        for(int i=2;i<n;i++){
            dp[i]=min(dp[i-1],dp[i-2])+a[i];
        }
        return dp[n-1];
    }
};


//------------------------------------SPACE Optimised------------------------------------

class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        a.push_back(0);
        int n=a.size();

        int p1=a[0],p2=a[1];
        for(int i=2;i<n;i++){
            int t=p2;
            p2=min(p1,p2)+a[i];
            p1=t;
        }
        return p2;
    }
};
