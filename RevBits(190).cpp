// class Solution {
// public:
//     string itb(int n) {
//         string s;
//         s.reserve(32);
//         for (int i = 31; i >= 0; i--) {
//           s.push_back((n & (1 << i)) ? '1' : '0');
//         }
//         return s;
//     }

//     int bti(string s){
//         int x=0;
//         for(int i=0;i<32;i++){
//             if(s[i]=='1'){x += pow(2,31-i);}
//         }
//         return x;
//     }

//     int reverseBits(int n) {
//         string a=itb(n);
//         reverse(a.begin(),a.end());
//         n=bti(a);
//         return n;
//     }
// };


class Solution {
public:
    int reverseBits(int n) {
        int ans=0;

        for(int i=31;i>=0;i--){
            if(n==0)break;//early detection
            if(n&1){
                ans+=(1<<i);
            }
            n>>=1;
        }

        return ans;
    }
};
