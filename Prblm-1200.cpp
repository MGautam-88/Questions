class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        int df=INT_MAX;

        for(int i=0;i<n-1;i++){
            if(a[i+1]-a[i]<df){
                df=a[i+1]-a[i];
                ans={};
                ans.push_back({a[i],a[i+1]});
            }
            else if((a[i+1]-a[i])==df){
                ans.push_back({a[i],a[i+1]});
            }
        }

        return ans;
    }
};
