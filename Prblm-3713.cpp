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
//we will use a fr array of size 26(globally and then learing it after each iteration of i)
class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        int fr[26] = {0};

        for(int i=0;i<n;i++){
            if(n-i<=ans)break;//as ans can't be find in this smaller window further
             
            for(int j=i;j<n;j++){
                fr[s[j]-'a']++;
                bool f=1;
                int val=0;

                for(int k=0;k<26;k++){
                    if(fr[k]>0){
                        if(val==0)val=fr[k];//1st non-zero
                        else if(fr[k]!=val){
                            f=0;
                            break;
                        }
                    }
                }

                if (f) ans = max(ans, j - i + 1);
                if(ans==n)return n;
            }

            for(int k=0;k<26;k++){
                fr[k]=0;
            }
        }

        return ans;
    }
};//O(26* n^2 ) => O(n^2)

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
// we can remove the use of k loop as in worst case-----> n=1000 => (n² / 2 ≈ 500,000)===> 500,000 × 26 ≈ 13 million iterations
class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        int fr[26] = {0};

        for(int i=0;i<n;i++){
            if(n-i<=ans)break;//as ans can't be find in this smaller window further

            int uq=0,mf=0;
            int fr[26] = {0};
             
            for(int j=i;j<n;j++){
                int x=s[j]-'a';
                if(fr[x]==0)uq++;

                fr[x]++;
                if(fr[x]>mf)mf=fr[x];
                
                int cur=j-i+1;
                
                //agar curr len jyada ya kam hai (mf*uq) se to matlab sab elem ki freq equal nahi hai
                if(uq*mf == cur && cur>ans ){
                    ans=cur;
                }
            }
        }

        return ans;
    }
};

//-------------------------------------------Further better , decreasing the arithmetic in hot loop , and early break in jth loop

class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        int fr[26] = {0};

        for(int i=0;i<n;i++){
            if(n-i<=ans)break;//as ans can't be find in this smaller window further

            int uq=0,mf=0,len=0;
            int fr[26] = {0};
             
            for(int j=i;j<n;j++){
                if (n - i <= ans) break;
                int x=s[j]-'a';
                if(fr[x]==0)uq++;

                fr[x]++;
                if(fr[x]>mf)mf=fr[x];
                
                len++;
                
                //agar curr len jyada ya kam hai mf*uq se to matlab sab elem ki freq equal nahi hai
                if(uq*mf == len && len>ans ){
                    ans=len;
                }
            }
        }

        return ans;
    }
};
