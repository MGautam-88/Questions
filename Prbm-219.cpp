// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& a, int k) {
//         int n = a.size();
//         unordered_map<int, vector<int>> mp;

//         for (int i = 0; i < n; i++) {
//             mp[a[i]].push_back(i);
//         }

//         for (auto& e : mp) {
//             vector<int>& ix = e.second;

//             for (int i = 0; i + 1 < ix.size(); i++) {
//                 if (ix[i + 1] - ix[i] <= k) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        if(k==0)return false;
        int n=a.size();
        unordered_set<int> window;
        int l=0;

        for(int i=0;i<n;i++){
            if(i-l>k){
                window.erase(a[l]);//left wala remove
                l++;
            }
            if(window.count(a[i]))return true;
            window.insert(a[i]);
        }
        return false;
    }
};
