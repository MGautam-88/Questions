//-----------------------------------Greedy will fail here-----------------------------------
class Solution {
public:
    int coinChange(vector<int>& a, int x) {
        int ct=0;
        sort(a.begin(),a.end(),greater<int>());

        for(int i=0;i<a.size();i++){
            if(x<=0)break;
            int r=x/a[i];
            ct+=r;
            x-=(a[i]*r);
        }
        if(x>0)return-1;
        return ct;
    }
};
//-------------------------------------------------------------------------------------------

//--------------------------------Use Knap-Sack DP approch-----------------------------------
class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        if(amt<=0)return 0;
        vector<int> dp(amt+1,INT_MAX);
        dp[0]=0;

        for(int i=1;i<=amt;i++){
            for(int c:coins){
                if(i>=c && dp[i-c]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-c]+1);
                    //remove one coin from previous amt and add 1 coin from curr denominaton
                }
            }
        }
        return (dp[amt]==INT_MAX)?-1:dp[amt];
    }
};
//--------------------------------------------------------------------------------------------
//asymptomaticlly they are same but the outer coin loop is faster as compared to outer amount loop , because of sequential memory access in coin (huge win when amt is large).

class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<int> dp(amt + 1, 1e8);
        dp[0] = 0;

        for (const auto& c: coins) {
            for (int i = 1; i <= amt; i++) {
                if (i >= c) {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }

        return dp[amt] == 1e8 ? -1 : dp[amt];
    }
};
//----------------------------------------------------------------------------------------------
