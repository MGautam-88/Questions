class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& a) {
        for (int i = 0; i < a.size(); i++) {
            int x=-1;
            int c=1;
            while((a[i]&c)!=0){
                x = a[i]-c;
                c<<=1;
            }
            a[i]=x;
        }
        return a;
    }
};
