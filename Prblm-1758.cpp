class Solution {
public:
    int minOperations(string s) {
        int s0=0,s1=0;

        for(int i=0;i<s.size();i++){
            if(i&1){
                if(s[i]=='1')s1++;//for starting with 1 it should have 0 at odd places 
                else s0++;//for starting with 0 should have 1 at odd places
            }
            else{
                if(s[i]=='0')s1++;
                else s0++;
            }
        }

        return min(s0,s1);
    }
};//O(n)
//---------------------------------------------------------------------------

// We see from observation that if i and ith char both have same parity then we make changes in starting_1 else in starting_0

class Solution {
public:
    int minOperations(string s) {
        int s0=0,s1=0;

        for(int i=0;i<s.size();i++){
            if((i&1) == ((s[i]-'0')&1) )s1++;// we can write s[i] also instead of s[i]-'0' as the ascii val of '0' is 48 which is also even
            else s0++;
        }

        return min(s0,s1);
    }
};// same O(n)

//------------------------------------------------------------------------
// Even smaller and clean code

class Solution {
public:
    int minOperations(string s) {
        int op[2]={0,0};

        for(int i=0;i<s.size();i++){
            op[(i&1) == ((s[i])&1)]++;
            
            // op[(s[i] ^ i) & 1]++;
            // as s[i]^i => will be 0 or any no. which in turn get 0 or 1 after doing & with 1
        }

        return min(op[0],op[1]);
    }
};
