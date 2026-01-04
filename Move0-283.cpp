class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n=a.size();
        int l=0;

        // while(l<n && a[l]!=0)l++;//l is where 1st 0
        // if(l==n)return ;

        // for(int r=l+1;r<n;r++){
        //     if(a[r]!=0){
        //         swap(a[r],a[l]);
        //         l++;
        //     }
        // }

        //now l is 1st non-zero
        for(int i=0;i<n;i++){
            if(a[i]!=0){
                swap(a[i],a[l]);//bass starting mien non-0 lagate raho
                l++;
            }
        }
    }
};
