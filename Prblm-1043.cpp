//------------------------------------RECURSIVE Fn O(k^n)----------------------------------------------------
class Solution {
public:
    int recursion(vector<int>& a, int k,int i){
        if(i>=a.size())return 0;

        int len=0;
        int mx=0;//this will store the max of a particular partition
        int ans=0;

        for(int j=i; j<min(i+k,(int)a.size());j++){
            len++;
            mx=max(mx,a[j]);//as mx will store the max elem upto now , we only need to 
                                 //compare it with the next coming elem only

            int sum = mx*len + recursion(a,k,j+1);
            ans = max(ans,sum);//as we have checked upto i+len
        }

        return ans;
    }

    int maxSumAfterPartitioning(vector<int>& a, int k) {
        return recursion(a,k,0);
    }
};

//-----------------------------------------------------------------------------------------------------------

//--<----<-----<----<-----<----<---<--<--<--<--<-<-<--<-right to left DP filling<--<--<---<---<-----<----<---<---<--<-

class Solution {
public:
int maxSumAfterPartitioning(vector<int>& a, int k) {
        int n=a.size();

        vector<int> dp(n+1,0);//dp[i] represents our ans from i to n-1
        // so dp[n+1]=0 is our BASE CASE and dp[0] is our answer as we will start from 0 to n-1

        for(int i=n-1;i>=0;i){
            int len=0;
            int mx=0;
            int ans=0;

            for(int j=i;j< min(i+k,n);j++){
                len++;//sub array mein us elem ko include kar liya
                mx=max(mx,a[j]);
                int sum = (mx*len) +dp[j+1];//that's why we used dp[n+1]=0
                ans=max(ans,sum);
            }
            dp[i]=ans;
        }

        return dp[0];//ous best ans from taking element from 0 to n-1
    }
};// O(K*N)

///////////////////////////////////////////////////////////////////////////////////////////////////

//------>--->---->---->--->--->---->--->-->->Left to Right DP filling->->-->--->---->--->--->---->---->

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        int n=a.size();
        vector<int> dp(n,0);

        for(int i=0;i<n;i++){
            int mx=0;
            int ans=0;

            for(int len=1;len<=k && len<=i+1 ; len++){
                mx=max(mx,a[i+1-len]);//basically uss subarray ka last elem
                int prev = (i-len>=0) ? dp[i-len]:0;//agar dp se hi bahar hai to lenge BASE CASE
                // jo abhi elem add hua hai usse just pehle wala 
                ans=max(ans,(mx*len) + prev);
            }
            dp[i]=ans;
        }
        return dp[n-1];
    }
};//O(K*N)
