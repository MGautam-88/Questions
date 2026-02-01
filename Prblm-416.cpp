//--------------------------------------Recursive O(2^n)----------------------------
class Solution {
public:
    bool ck(vector<int>& a, int i, int s) {
        if (s == 0) return true;
        if (i >= a.size() || s<0) return 0;

        return ck(a, i + 1, s - a[i]) || ck(a, i + 1, s);
    }

    bool canPartition(vector<int>& a) {
        int s = accumulate(a.begin(), a.end(), 0);
        if (s & 1)return 0;

        return ck(a, 0, s / 2);
        // we will find the half of sum is possibe or not ,
        // if yes then the remaing will be automatically s/2 .
    }
};
//----------------------------------------------------------------------------------

//--------------------------SET+DP O(n*s) where s = sum of array--------------------
class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n=a.size();
        int s=accumulate(a.begin(),a.end(),0);//as a[i]<100 no need of LL
        if(s&1)return 0;
        unordered_set<int> dp;
        dp.insert(0);

        for(int i=0;i<n;i++){
            vector<int> prev(dp.begin(), dp.end());
            for(auto x:prev){
                dp.insert(x+a[i]);
                if(x+a[i]==s/2)return 1;
            }
        }

        return dp.count(s/2);
    }
};
//-----------------------------------------------------------------------------------

//---------------------Using sum DP upto target O(s*n)-------------------------------

class Solution {
public:
    bool canPartition(vector<int>& a) {
        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum & 1) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : a) {
            for (int x = target; x >= num; x--) {
                dp[x] = dp[x] || dp[x - num];
                if(dp[target])return 1;
            }
        }

        return dp[target];
    }
};

