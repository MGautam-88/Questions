class Solution {
public:
    int minPartitions(string s) {
        int ct=0;

        //overall => O(9*n)
        while(1){
            //O(9) as we can have 9 min digits at max only 
            int n=s.size();
            int mn=9;
            bool f=0;

            for(int i=0;i<n;i++){//O(n)
                if(s[i]!='0'){
                    f=1;//found a non-0 digit
                    mn=min(s[i]-'0',mn);
                }
            }

            if(!f)return ct;//if we didn't found any non-0 digit, then all set return the ct!!

            ct+=mn;

            for(int i=0;i<n;i++){//O(n)
                if(s[i]!='0'){
                    s[i] = ((s[i]-'0')-mn)+'0';
                }
            }

        }
    }
};
//---------O(9*n)------------------------------------------------------------

// Since we are finding the min didgit and deleting it from all other non-0 dgts 
// this id simply the magnitude of MAX elem in the string

class Solution {
public:
    int minPartitions(string s) {
        int mx=0;
        for(int i=0;i<s.size();i++){
            mx=max(mx,s[i]-'0');
        }
        return mx;
    }
};//O(n)

// We can use char  instead in the comparision , which give better runtime (0ms)
//Best

class Solution {
public:
    int minPartitions(string s) {
        char mx=0;
        for(int i=0;i<s.size();i++){
            mx=max(mx,s[i]);
        }
        return mx-'0';
    }
};
