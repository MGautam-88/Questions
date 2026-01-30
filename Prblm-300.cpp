//------------------------------------------DP O(n^2)---------------------------------------
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n,1);//dp[i] -> len of longest subseq ending at ith place
        int ans=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }

        return ans;
    }
};

//-------------------------------------------------------------------------------------------

//----------------------------we can use Binary search for O(n* lg n)------------------------
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int> tails;

        for(int x:a){
            auto pos=lower_bound(tails.begin(),tails.end(),x);
            if(pos==tails.end()){
                tails.push_back(x);//this x will keep the tails sorted
            }
            else{
                *pos=x;
            }
        }

        return tails.size();
    }
};
