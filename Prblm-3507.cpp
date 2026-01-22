class Solution {
public:
    int minimumPairRemoval(vector<int>& a) {
        int ct=0;

        while(a.size()>1){
            bool ck=1;
            int s=INT_MAX;
            int k=-1;
            for(int i=0;i<a.size()-1;i++){
                if(a[i]>a[i+1])ck=0;
                if(a[i]+a[i+1]<s){
                    s=a[i]+a[i+1];
                    k=i;
                }
            }
            if(ck){break;}
            a[k]=s;//ith pe jaha chotta sum tha sum ko hi daal diya
            a.erase(a.begin()+k+1);//orr usse next wala element remove kar diya 
            ct++;
        }
        return ct;

    }
};
