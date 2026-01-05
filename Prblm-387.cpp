class Solution {
public:
    int firstUniqChar(string s) {
        // unordered_map<char,int> mp;

        // for(int i=0;i<s.size();i++){
        //     mp[s[i]]++;
        // }
        // int m=-1;

        // for(int i=0;i<s.size();i++){
        //     if(mp[s[i]]==1){
        //         m=i;
        //         break;
        //     }
        // }

        // return m;
        vector<int> fq(26, 0);

        for(auto x: s) fq[x - 'a']++;

        for(int i = 0 ; i  < s.size(); i++){
            if(fq[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
