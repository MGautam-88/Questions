class Solution {
public:
    int ck(int a){
        int ct=0;
        int s=0;
        for(int i=2;i<=a/2;i++){
            if(a%i==0){
                ct++;
                s+=i;
            }
            if(ct>2)return 0;
        }
        if(ct==2)return s+a+1;
        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(ck(nums[i])){sum+=ck(nums[i]);}
        }

        return sum;
    }
};
