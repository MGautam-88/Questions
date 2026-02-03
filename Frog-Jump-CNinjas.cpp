int frogJump(int n, vector<int> &a)
{
    if(n==1)return 0;
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    dp[1]=abs(a[0]-a[1]);
    
    for(int i=2;i<n;i++){
        int fs=dp[i-2]+abs(a[i]-a[i-2]);
        int ss=dp[i-1]+abs(a[i]-a[i-1]);
        dp[i]=min(fs,ss);
    }
    return dp[n-1];
}//o(n)

//------------------------SPACE Optimization------------------------------

int frogJump(int n, vector<int> &a)
{
    // Write your code here.
    if(n==1)return 0;
    int p1=0;
    int p2=abs(a[0]-a[1]);
    
    for(int i=2;i<n;i++){
        int t=p2;
        p2=min(p2+abs(a[i]-a[i-1]),p1+abs(a[i]-a[i-2]));
        p1=t;
    }
    return p2;
}

// follow up question instead of 1 or 2 steps we can go anywhere upto k steps 
class Solution {
public:
    int frogJump(vector<int>& a, int k) {
        int n = a.size();
        if(n==1)return 0;
        vector<int> dp(n,0);
        dp[0]=0;
        dp[1]=abs(a[0]-a[1]);
        for(int i=2;i<n;i++){
            int ans=INT_MAX;
            for(int j=1;j<=i && j<=k;j++){
                ans=min(ans,dp[i-j]+abs(a[i]-a[i-j]));
            }
            dp[i]=ans;
        }

        return dp[n-1];
    }
};
// we can SPACE Optimize it to o(k) vector by removing the first elem of the vector and inserting the last one 
//---------------------------------------------------------------------------------------------------
