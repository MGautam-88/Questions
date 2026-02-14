//❌❌❌❌This one is wrong as the water in lower glasses will not be distributed equally  8888at a given point of time****
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
};//❌❌❌❌This one is wrong as the water in lower glasses will not be distributed equally  8888at a given point of time****

//---------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    double champagneTower(int q, int r, int c) {
        // vector<vector<double>> status(101,vector<double>(101,0.0));
        vector<vector<double>> status(r+1,vector<double>(r+1,0.0));//won't affect much but stilll

        status[0][0]=q;

        for(int i=0;i<r;i++){
            for(int j=0;j<=i;j++){
                if(status[i][j]>1){
                    double extra = (status[i][j]-1)/2.0;//uska ek rakh liya baaki de diya
                    status[i+1][j]+=extra;//left down mein extra add kar diya 
                    status[i+1][j+1]+=extra;//right down
                    status[i][j]=1;//last mein iske paas 1 hi bacche ga
                }
            }
        }

        return min(1.0,status[r][c]);
    }
};//O(row^2)

//------------------------------------------------------------------------------------------------------------------------------------------

//
