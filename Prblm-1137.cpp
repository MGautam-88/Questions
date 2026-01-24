class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1||n==2) return 1;
        int p1=0,p2=1;
        for(int i=2;i<=n;i++){
            int t=p2;
            p2+=p1;
            p1=t;
        }
        return p2;
    }
};
