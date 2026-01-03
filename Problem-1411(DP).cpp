using ll=long long;
class Solution {
public:
    int numOfWays(int n) {
        // alt -> [RYR, YRY, GRG, RGR, YGY, GYG] -> next we can use 3 alt and 2 unq out of it 
        // unq -> [RGB, RGY, YRG, YGR, GRY, GYR] -> next we can use 2 alt and 2 unq out of it
        const int md=1e9+7;
        ll alt=6,unq=6;

        for(int i=2;i<=n;i++){
            ll alt1=(3*alt + 2*unq)%md;
            ll unq1=(2*alt + 2*unq)%md;
            alt=alt1;
            unq=unq1;
        }

        return (alt +unq)%md;

    }
};
