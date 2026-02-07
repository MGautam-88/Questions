class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> ca(n,0),cb(n,0);
        for(int i=1;i<n;i++){
            if(s[i-1]=='b')cb[i]=cb[i-1]+1;
            else cb[i]=cb[i-1];
        }

        for(int i=n-2;i>=0;i--){
            if(s[i+1]=='a')ca[i]=ca[i+1]+1;
            else ca[i]=ca[i+1];
        }

        for(int i=0;i<n;i++){
            ca[i]+=cb[i];
        }

        return *min_element(ca.begin(),ca.end());
    }
};
