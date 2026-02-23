class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> c2;

        int l=0,r=k-1;
        while(r<s.size()){
            c2.insert(string(s.begin() + l, s.begin() + r + 1));
            if(c2.size()==pow(2,k))return 1;
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

const int N = 1<<20;//2^20
bitset<N> seen;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n= s.size();
        if(n<k)return 0;

        seen.reset();
        unsigned code=0;
        for(int i=0;i<k;i++){//1st k digit bits
            code = (code<<1)+(s[i]-'0');
        }
        int ct=1;//for 1st substring
        seen[code]=1;
        int M =(1<<(k-1))-1;//it is used to remove the MSB bit
        //like k=4 => M=0111 and we will do and opr later that will remove the left bit

        for(int r=k;r<n;r++){
            code&=M;//MSB removed
            code<<=1;//left shift
            code|= (s[r]-'0');//added the lsb for the next sub string
            if(!seen[code])ct++;
            seen[code]=1;
            if(ct==(1<<k))return true;
        }

        return ct==(1<<k);//counts the no. of set bits in seen Bitset
    }
};//O(n + 2^k)
