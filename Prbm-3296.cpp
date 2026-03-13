using ll = long long;

class Solution {
public:
    long long minNumberOfSeconds(int h, vector<int>& w) {
        int n = w.size();
        multiset<pair<ll, pair<ll,ll>>> s;

        for(int i = 0; i < n; i++){
            s.insert({w[i], {w[i], 1}});//{future,{start,x}}
        }//O(n*Lg n)

        ll ans = 0;

        while(h > 0){
            auto it = s.begin();

            ll curr = it->first;
            ll base = it->second.first;
            ll x = it->second.second;//upto how much sec this worker is used

            s.erase(it);//O(lg n)

            ans = max(ans, curr);   // track actual completion time here only
                                   //  as we need curr not next time in our ans

            x++;
            ll next = curr + x * base;

            s.insert({next, {base, x}});//O(lg n)
            h--;
        }//O(h*lg n)

        return ans;
    }
}; // O(n*Lg n + h*Lg n)

//-------------------------------------------------------------------------------------------------------------------------

//
