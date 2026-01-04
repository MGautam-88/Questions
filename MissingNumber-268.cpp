class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();

        // ------------------O(n+nlgn)----------------------//
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++){
        //     if(i!=nums[i]) return i;
        // }
        // return n;

        //------------------O(n)-------------------------//
        // int ans=0;
        // for(int i=1;i<=n;i++){
        //     ans^=i;
        // }
        // for(int i=0;i<n;i++){
        //     ans^=nums[i];//agar 1 se n tak sab honge to x^x = 0 hi hota hai
        // }
        // return ans;

        //--------------------O(n)----------------------//
        return (n*(n+1))/2 -accumulate(nums.begin(),nums.end(),0);
    }
};
