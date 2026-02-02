// We split the array into k subarrays --> nums[s1] + nums[s2] + ... + nums[sk] , s1 = 0 (forced) but s2, s3, …, sk are chosen split points

// The constraint is: sk − s2 ≤ dist , That means all of s2, s3, …, sk must lie inside: [s2 , s2 + dist] 

// so we just fix the s1 at 0 and try to pick the k-1 smallest elem from the [1 , dist+1] thats it...... . A window size of dist+1 and find k-1 smallest elem out of it 

// s1=0=>c1=a[0] then make a window of size dist+1 and slide it over [i=1 to i=n-dist] and find the cost as sum of k-1 min elements and then move the window and in this way store the ans = min(ans,cost)
// and *****return ans+a[0]*****.

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------This code worked but got TLE on 678/691 test case------------------------------------------
using ll = long long;
class Solution {
public:
    long long minimumCost(vector<int>& a, int k, int d) {
        int n=a.size();
        ll ans = LLONG_MAX;
        vector<int> tp;

        for(int i=1;i<n-d;i++){
            for(int j=i;j<=i+d;j++){
                tp.push_back(a[j]);
            }

            sort(tp.begin(),tp.end());
            //pick k-1 starting elem from it
            ll cost=0;
            for(int r=0;r<k-1;r++){
                cost+=tp[r];
            }
            ans=min(ans,cost);
            tp.clear();
        }
        return ans +a[0];
    }
};
//-------------------------------------------------------------------------------------------------------------------
