class Solution {
public:
    int repeatedNTimes(vector<int>& a) {
        int n=a.size();
        for(int i=0;i<n-2;i++){
            if(a[i]==a[i+1] || a[i]==a[i+2]){
                return a[i];//at max we can seprate the (n Freq elem) by keeping 1 elem in b/w them
            }
        }

        return a[n-1];//if not found till a.size()-2 , then 100% it is the last elem
    }
};
