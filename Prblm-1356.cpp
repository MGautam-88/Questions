class Solution {
public:
    static bool cmp(vector<int>&a , vector<int> &b){
        if(a[1]==b[1])return a[0]<b[0];
        return a[1]<b[1];
    }

    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> s;

        for(int x:arr){
            int y= __builtin_popcount(x);
            s.push_back({x,y});
        }

        sort(s.begin(),s.end(),cmp);

        for(int i=0;i<n;i++){
            arr[i]=s[i][0];
        }

        return arr;
    }
};

//---------------------------------------------------------------------------------------------------------------------------------------------------

// we can apply the same logic for inplace sorting , which will reduce the complexity and hence the runtime 

class Solution {
public:
    static bool cmp(int a , int b){
        int sa=__builtin_popcount(a);
        int sb=__builtin_popcount(b);
        if(sa==sb)return a<b;
        return sa<sb;
    }

    vector<int> sortByBits(vector<int>& a) {
        sort(a.begin(),a.end(),cmp);
        return a;
    }
};
