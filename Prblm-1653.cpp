class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> ca(n,0),cb(n,0);
        for(int i=1;i<n;i++){
            if(s[i-1]=='b')cb[i]=cb[i-1]+1;
            else cb[i]=cb[i-1];
        }

        for(int i=n-2;i>=0;i--){
            if(s[i+1]=='a')ca[i]=ca[i+1]+1;
            else ca[i]=ca[i+1];
        }

        for(int i=0;i<n;i++){
            ca[i]+=cb[i];
        }

        return *min_element(ca.begin(),ca.end());
    }
};
//--------------------------------------------------Formal DP version---------------------------------------
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        int bCount = 0;

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'b') {
                dp[i] = dp[i - 1];
                bCount++;
            } else {
                dp[i] = min(dp[i - 1] + 1, bCount);
            }
        }

        return dp[n];
    }
};
//------------------------------------------------------------SPACE Optimized-------------------------------------------
class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int db=0,ans=0;

        for(int i=0;i<n;i++){
            if(s[i]=='b')db++;

            else ans=min(ans+1,db);//ya to a del karo ya b
        }

        return ans;
    }
};
