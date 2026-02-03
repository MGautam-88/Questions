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
