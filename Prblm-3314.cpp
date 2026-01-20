class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& a) {
        int n=a.size();
        vector<int> b(n,-1);
        for(int i=0;i<n;i++){
            for(int x=1;x<1000;x++){
                if((x | (x+1))==a[i]){b[i]=x;break;}
            }
        }

        return b;
    }
};
