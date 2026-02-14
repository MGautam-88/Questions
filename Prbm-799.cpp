class Solution {
public:
    double champagneTower(int p, int qi, int qj) {
        if(p==0)return 0;
        p-=(qi*(qi+1))/2;
        int fg=2*(qi-1)+2;

        if(qj==0 or qj==qi){
            if((double)p/fg > 1)return 1;
            return (double)p/fg;
        }
        else{
            if(2*(double)p/fg >1)return 1;
            return 2*(double)p/fg;
        }
    }
};
