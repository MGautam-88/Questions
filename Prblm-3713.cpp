class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        map<char,int> fr;//using a single map and clearing it after every iteration

        for(int i=0;i<n;i++){
            if(n-i<=ans)break;//as ans can't be find in this smaller window further
            // map<char,int> fr; 
            for(int j=i;j<n;j++){
                fr[s[j]]++;
                bool f=1;

                if (!fr.empty()) {
                    auto it = fr.begin();
                    int val = it->second;
                    ++it;

                    for (; it != fr.end(); ++it) {
                        if (it->second != val) {
                            f = false;
                            break;
                        }
                    }
                }

                if (f) ans = max(ans, j - i + 1);
                if(ans==n)return n;
            }
            fr.clear();
        }

        return ans;
    }
};//O(n^3)

//------------------------------------------------------------------------------------------------------------------------------------------------
