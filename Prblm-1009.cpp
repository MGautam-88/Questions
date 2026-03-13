class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==1)return 0;
        if(n==0)return 1;
        string s = bitset<32>(n).to_string();
        s = s.substr(s.find('1'));

        for(int i=0;i<s.size();i++){
            s[i]= (s[i]=='0')?'1':'0';
        }

        n=stoi(s,nullptr,2);
        return n;
    }
};//O(1) as every thing is performed around string of size 32 and comes out to be a Const TC

//----------------------------------------------------------------------------------

// if we add the n and n' then we get all bits as 1 in that length , eg n=5 and n'=2 => adding we get 7 having all bits as 1

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int p = log2(n)+1;
        
        return ((pow(2,p)-1)-n);
    }
};//O(1)
