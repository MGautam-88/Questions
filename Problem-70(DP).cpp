// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n==0||n==1)return 1;
//         vector<int> dp(n+1);
//         dp[0]=dp[1]=1;
        
//         for(int i=2;i<=n;i++){
//             dp[i]=dp[i-1]+dp[i-2];//ya to n-1th stair se aaya hoga ya fir n-2th se
//         }
//         return dp[n];
//     }
// };

//-------------------Space Optimised-----------------------//
int climbStairs(int n) {
        if(n==0||n==1)return 1;
        int curr=1,prev=1;
        for(int i=2;i<=n;i++){
            int tp=curr;
            curr+=prev;
            prev=tp;
        }
        return curr;
    }
