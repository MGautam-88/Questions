//--------------------------------BRUTE Force O(n^3) and SPACE:O(1)---------------------------------------
class Solution {
public:
    bool ck(string a , int l,int r){
        int n= a.size();
        for(int i=l;i<=(l+r)/2;i++){//as we do n+0)/2
            if(a[i]!=a[r+l-i])return false;// as we do in n+0-i
        }
        return true;
    }

    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ck(s,i,j))ans++;
            }
        }
        return ans;
    }
};

//----------------------------------------------------------------------------------------

//------------------------------------RECURSION O(n^3) , spO(1)------------------------------------
class Solution {
public:
    bool isP(string &s,int l,int r){
        if(l>=r)return true;
        if(s[l]!=s[r]) return false;
        return isP(s,l+1,r-1);
    }

    int countSubstrings(string s) {
        int n=s.size();
        int ct=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isP(s,i,j))ct++;
            }
        }
        return ct;
    }
};
//-----------------------------------------------------------------------------------------

//----------------------------------------DP O(n^2) spO(n^2) or O(n)----------------------------------------
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        //dp[i][j]represents that the string from l to r is palindromic or not 
        int ct=0;

        for(int i=0;i<n;i++){
            dp[i][i]=true;
            ct++;//single elem are always palindrome
        }

        //we fill table acc to interval but not row wise or col wise
        for(int len=2;len<=n;len++){
            for(int l=0;l+len-1<n;l++){//this will check the 1st and last elem of the interval
                int r=l+len-1;
                if(s[l]==s[r]){//cornere elem equal hai 
                    if(len==2 or dp[l+1][r-1]){//len 2 hai ya anadar wali sustring palin hai
                        dp[l][r]=true;
                        ct++;
                    }
                }
            }
        }
        return ct;
    }
};
//------------------------------------------------------------------------------------------

//-------------------------------------2-POINTER O(n^2) space:O(1)--------------------------------------------
//-------------------------------------Best and Simple----------------------------------------------------------
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ct = 0;

        for (int i = 0; i < n; i++) {
            int l=i,r=i;
            //count all odd length palindromes
            while(l>=0 && r<n && s[l]==s[r]){
                ct++;
                l--;
                r++;
            }

            //count all even length palindromes
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                ct++;
                l--;
                r++;
            }
        }

        return ct;
    }
};
