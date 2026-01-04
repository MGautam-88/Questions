class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        unordered_set<int>st;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i]==b[j]){
                    st.insert(a[i]);
                    break;
                }
            }
        }

        vector<int> ans;
        for(int y:st){
            ans.push_back(y);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> ans;
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (a[i] == b[j]) {
                if ( ans.empty() ||ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else
                j++;
        }

        return ans;
    }
};
