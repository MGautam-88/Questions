class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;

        for(auto x:s){
            mp[x]++;
        }
        int ct=0;
        bool od=0;

        for(auto x:mp){
            int v=x.second;
            if(!od && v&1)od=1;
            ct+=(v-(v&1?1:0));
        }
        return od?ct+1:ct;
    }
};
