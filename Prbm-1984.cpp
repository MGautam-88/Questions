class Solution {
public:
    int minimumDifference(vector<int>& a, int k) {
        int n= a.size();
        if(n==1||k==1)return 0;
        sort(a.begin(),a.end());
        int l=0,r=k-1,df=INT_MAX;
        while(r<n){
            df=min(df,abs(a[l]-a[r]));
            l++,r++;
        }
        return df;
    }
};
