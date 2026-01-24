class Solution {
public:
    int minPairSum(vector<int>& a) {
        int n= a.size();
        sort(a.begin(),a.end());
        vector<int> b;
        for(int i=0;i<n/2;i++){
            b.push_back(a[i]+a[n-i-1]);
        }
        int ans=0;
        for(int i=0;i<b.size();i++){
            if(b[i]>ans)ans=b[i];
        }

        return ans;
    }
};
