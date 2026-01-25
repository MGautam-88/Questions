class Solution {
public:
    //----------------Recursion: O(2^n)--------------
    // int solve(vector<int>& a,int i){
    //     if(i>=a.size())return 0;
    //     return max(a[i]+solve(a,i+2) ,solve(a,i+1));
    // }

    // int rob(vector<int>& a) {
    //     int n=a.size();
    //     if(n==1)return a[0];
    //     if(n==2)return max(a[0],a[1]);
    //     int amt=0;
    //     vector<int> dp(n,0);
    //     dp[0]=a[0];
    //     dp[1]=max(a[0],a[1]);

    //     for(int i=2;i<n;i++){
    //         dp[i]=max(a[i]+dp[i-2],dp[i-1]);
    //     }

    //     return dp[n-1];
    // }

    int rob(vector<int>&a){
        int n= a.size();
        if(n==1)return a[0];
        if(n==2)return max(a[0],a[1]);
        int ans=0;
        int p1=a[0],p2=max(a[0],a[1]);
        for(int i=2;i<n;i++){
            int t=p2;
            p2=max(a[i]+p1,p2);
            p1=t;
        }
        return p2;
    }
};
