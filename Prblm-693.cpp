class Solution {
public:
    bool hasAlternatingBits(int n) {
        int p,c=n%2;
        n/=2;
        while(n>0){
            p=c;
            c=n%2;
            if(c==p)return false;
            n/=2;
        }
        return true;
    }
};
