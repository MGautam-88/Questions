// We split the array into k subarrays --> nums[s1] + nums[s2] + ... + nums[sk] , s1 = 0 (forced) but s2, s3, …, sk are chosen split points

// The constraint is: sk − s2 ≤ dist , That means all of s2, s3, …, sk must lie inside: [s2 , s2 + dist] 

// so we just fix the s1 at 0 and try to pick the k-1 smallest elem from the [1 , dist+1] thats it...... . A window size of dist+1 and find k-1 smallest elem out of it 

// s1=0=>c1=a[0] then make a window of size dist+1 and slide it over [i=1 to i=n-dist] and find the cost as sum of k-1 min elements and then move the window and in this way store the ans = min(ans,cost)
// and *****return ans+a[0]*****.

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------This code worked but got TLE on 678/691 test case------------------------------------------
using ll = long long;
class Solution {
public:
    long long minimumCost(vector<int>& a, int k, int d) {
        int n=a.size();
        ll ans = LLONG_MAX;
        vector<int> tp;

        for(int i=1;i<n-d;i++){
            for(int j=i;j<=i+d;j++){
                tp.push_back(a[j]);
            }

            sort(tp.begin(),tp.end());
            //pick k-1 starting elem from it
            ll cost=0;
            for(int r=0;r<k-1;r++){
                cost+=tp[r];
            }
            ans=min(ans,cost);
            tp.clear();
        }
        return ans +a[0];
    }
};//O(n * d log d)
//-------------------------------------------------------------------------------------------------------------------

//Now we have to think of some optimall soln , so we will try to solve this issue using *2 MULTI-SETS*
// MultiSet bcz there are duplicate elem also 
// 2 bcz if we use only one we have to iteraate over it to get the k-1 elem , which will again increase the complexity

using ll = long long;
class Solution {
public:
    multiset<int> small, large;
    ll smallSum = 0;
    int need;

    void rebalance() {
        while (small.size() > need) {
            // small mein se last wala bada elem nikalna padega
            auto i =
                --small
                      .end(); // the last elem of the set as end is next to last
            smallSum -= *i;
            large.insert(*i);
            small.erase(i);
        }
        while (small.size() < need) {
            // we will add the starting elem of the large-set
            auto i = large.begin();
            smallSum += *i;
            small.insert(*i);
            large.erase(i);
        }
    }

    void addToSet(int x) {
        if (small.empty() || x <= *small.rbegin()) {
            small.insert(x);
            smallSum += x;
        } else {
            large.insert(x);
        }
        rebalance();
    }

    void removeFrmSet(int x) {
        auto it = small.find(x);
        if (it != small.end()) {
            smallSum -= x;
            small.erase(it);
        } else {
            auto it2 = large.find(x);
            large.erase(it2);
        }
        rebalance();
    }

    long long minimumCost(vector<int>& a, int k, int d) {
        int n = a.size();
        need = k - 1;

        // build first window [1 ... 1+d]
        for (int i = 1; i <= d; i++)
            addToSet(a[i]);

        ll ans = smallSum;

        for (int i = 2; i < n - d; i++) {
            removeFrmSet(a[i - 1]);
            addToSet(a[i + d]);
            ans = min(ans, smallSum);
        }

        return ans + a[0];
    }
};
//-------------------But this still got TLE here so we have to use heap for this problem

using ll = long long;

class Solution {
public:
    priority_queue<int> small;                 // max-heap
    priority_queue<int,vector<int>,greater<int>> large; // min-heap
    unordered_map<int,int> delSmall, delLarge;
    ll sumSmall = 0;
    int need;

    void cleanSmall() {
        while (!small.empty() && delSmall[small.top()]) {
            delSmall[small.top()]--;
            small.pop();
        }
    }
    void cleanLarge() {
        while (!large.empty() && delLarge[large.top()]) {
            delLarge[large.top()]--;
            large.pop();
        }
    }

    void rebalance() {
        cleanSmall();
        cleanLarge();

        while ((int)small.size() > need) {
            cleanSmall();
            int x = small.top(); small.pop();
            sumSmall -= x;
            large.push(x);
        }
        while ((int)small.size() < need) {
            cleanLarge();
            int x = large.top(); large.pop();
            sumSmall += x;
            small.push(x);
        }
    }

    void add(int x) {
        if (small.empty() || x <= small.top()) {
            small.push(x);
            sumSmall += x;
        } else large.push(x);
        rebalance();
    }

    void remove(int x) {
        if (!small.empty() && x <= small.top()) {
            delSmall[x]++;
            sumSmall -= x;
        } else delLarge[x]++;
        rebalance();
    }

    long long minimumCost(vector<int>& a, int k, int d) {
        need = k - 1;
        int n = a.size();

        for (int i = 1; i <= d; i++) add(a[i]);

        ll ans = sumSmall;

        for (int i = 2; i + d < n; i++) {
            remove(a[i-1]);
            add(a[i+d]);
            ans = min(ans, sumSmall);
        }
        return ans + a[0];
    }
};

