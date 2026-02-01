class Solution {
public:
    int minimumCost(vector<int>& a) {
        int ans=a[0];

        auto i= min_element(a.begin()+1,a.end());
        ans+=*i;
        *i=51;
        ans+=*min_element(a.begin()+1,a.end());

        return ans;
    }
}; // O(2*N)

//-------------------------------------------------------------

class Solution {
public:
    int minimumCost(vector<int>& a) {
        int x=51,b=51;//as a[i]<=50

        for(int i=1;i<a.size();i++){
            if(a[i]<x){
                b=x;
                x=a[i];
            }
            else if(a[i]<b)b=a[i];
        }

        return a[0]+x+b;
    }
}; // O(N)
