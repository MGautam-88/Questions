class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int prev=0,curr=1;
        int ans=0;

        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])curr++;
            else{
                ans+=min(curr,prev);
                prev=curr;
                curr=1;//jo ith elem hai usse to curr mein kare ge include
            }
        }

        ans+=min(curr,prev);//ast mein agar reh gaya ho to 
        return ans;
    }
};
