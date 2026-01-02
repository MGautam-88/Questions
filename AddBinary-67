class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int m=a.size()-1;
        int n=b.size()-1;
        int c=0;
        while(m>=0 || n>=0){
            int s=c;//pichli carry lekar chalege
            if(m>=0) s+=(a[m--]-'0');//mth elem string a ka s mein add kar diya m--
            if(n>=0)s+=(b[n--]-'0');//nth elem string b ka s mein add kar diya orr n--
            c = (s>1)?1:0;
            ans+=(s%2 + '0');//0 for s==0 or s==2 else 1
        }
        if(c)ans.push_back('1');//agar last elem par bhi carry one aayi to usse bhi laga diya
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
