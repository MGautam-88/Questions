class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        int n= bl.size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x=min(tr[i][0],tr[j][0])-max(bl[i][0],bl[j][0]);
                int y=min(tr[i][1],tr[j][1])-max(bl[i][1],bl[j][1]);

                ans=max(ans,min(x,y));
            }
        }

        return 1LL*ans*ans;
    }
};
