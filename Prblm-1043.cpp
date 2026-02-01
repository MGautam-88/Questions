//------------------------------------RECURSIVE Fn O(k^n)----------------------------------------------------
class Solution {
public:
    int recursion(vector<int>& a, int k,int i){
        if(i>=a.size())return 0;

        int len=0;
        int mx=0;//this will store the max of a particular partition
        int ans=0;

        for(int j=i; j<min(i+k,(int)a.size());j++){
            len++;
            mx=max(mx,a[j]);//as mx will store the max elem upto now , we only need to 
                                 //compare it with the next coming elem only

            int sum = mx*len + recursion(a,k,j+1);
            ans = max(ans,sum);//as we have checked upto i+len
        }

        return ans;
    }

    int maxSumAfterPartitioning(vector<int>& a, int k) {
        return recursion(a,k,0);
    }
};

//-----------------------------------------------------------------------------------------------------------
