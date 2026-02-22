class Solution {
public:
    int binaryGap(int n) {
        int ans=0,p=-1,i=0;
        bool f=false;
        while(n>0){
            int r=n%2;
            if(r){
                if(p==-1)p=i;
                else{
                    ans=max(ans,i-p);
                    p=i;
                }
            }
            n/=2;
            i++;
        }
        return ans;
    }
};
