class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n>0){
            if(n%26==0){s.push_back('Z');n--;}
            else {s.push_back(char(n%26 + 64));}
            n=n/26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
