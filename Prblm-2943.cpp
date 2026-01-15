class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        int l1=1,l2=1;

        int c1=1;
        for(int i=1;i<h.size();i++){
            if(h[i]-h[i-1] == 1){c1++;}
            else c1=1;
            l1=max(c1,l1);
        }
        c1=1;
        for(int i=1;i<v.size();i++){
            if(v[i]-v[i-1]==1){c1++;}
            else c1=1;
            l2=max(c1,l2);
        }
        int mn= min(l1+1,l2+1);
        return mn*mn;
    }
};
