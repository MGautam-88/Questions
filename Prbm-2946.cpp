class Solution {
public:
    bool areSimilar(vector<vector<int>>& a, int k) {
        int m=a.size();
        int n=a[0].size();

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r;
                k%=n; // important , as k can be larger then (j+n)
                if(i&1){
                    r = (j+k)%n;
                }
                else{
                    r=(j-k+n)%n;
                }

                if(a[i][j]!=a[i][r])return 0;
            }
        }

        return 1;
    }
};
