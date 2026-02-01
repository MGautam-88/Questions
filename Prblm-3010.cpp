class Solution {
public:
    int minimumCost(vector<int>& a) {
        int ans=a[0];

        auto i= min_element(a.begin()+1,a.end());
        ans+=*i;
        *i=51;
        ans+=*min_element(a.begin()+1,a.end());

        return ans;
    }
}; // O(2*N)

//-------------------------------------------------------------

//
