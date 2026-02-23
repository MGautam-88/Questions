class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> c2;

        int l=0,r=k-1;
        while(r<s.size()){
            string t(s.begin()+l,s.begin()+r+1);//o(k)
            c2.insert(t);
            l++;
            r++;
        }

        if(c2.size()<pow(2,k))return false;
        return true;
    }
};// O(nk + 2^k)
//---------------------------------------------------------------------------------------------------------------------------------------------

//Single contiguous block of memory ,No hashing ,No dynamic node allocation ,Excellent cache locality
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<bool> seen(pow(2,k),0);

        int l=0,r=k-1;
        while(r<s.size()){//o(n-k)
            string t(s.begin()+l,s.begin()+r+1);
            int idx=stoi(t,nullptr,2);//O(k)
            seen[idx]=1;
            l++;
            r++;
        }//overall =>O(n*k) max(10^7)

        for(auto x:seen){
            if(x==0)return false;
        }//O(2^k) max(10^6)

        return true;
    }
}; //O(10^7)

// ---------------------------------------------------------------------------------------------------------------------------------------------------
