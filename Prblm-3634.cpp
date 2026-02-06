class Solution {
public:
    int minRemoval(vector<int>& a, int k) {
        int n= a.size();
        if(n==1)return 0;
        sort(a.begin(),a.end());
        int r=0;
        int ans=n;
        for(int i=0;i<n;i++){
            while(r<n and a[r]<=(1LL * a[i] * k))r++;

            ans=min(ans,n-(r-i));
        }
        return ans;
    }
};
