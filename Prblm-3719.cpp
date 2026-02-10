class Solution {
public:
    int longestBalanced(vector<int>& a) {
        int ans=0;
        int n=a.size();

        for(int i=0;i<n;i++){
            unordered_set<int> o,e;
            for(int j=i;j<n;j++){
                if(a[j]&1)o.insert(a[j]);
                else e.insert(a[j]);

                if(o.size()==e.size()){
                    ans=max(ans,(j-i+1));
                    if(ans==n) return n;
                }
            }
        }

        return ans;
    }
};
