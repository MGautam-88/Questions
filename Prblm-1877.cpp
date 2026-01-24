
//-----------------------O(n/2 + n*lgn)----------------------------------

class Solution {
public:
    int minPairSum(vector<int>& a) {
        int n= a.size();
        int ans=0;
        sort(a.begin(),a.end());
        for(int i=0;i<n/2;i++){
            ans=max(ans,(a[i]+a[n-i-1]));
        }

        return ans;
    }
};

//-----------------------O(2*n)----------------------------------

class Solution {
public:
    int minPairSum(vector<int>& a) {
        int mn=INT_MAX, mx=INT_MIN;
        vector<int> fq(100001,0);
        // wahi hai fq ka use kar ke bade chotte ka pair banana hai orr use kar lo to fq--
        for(int i=0;i<a.size();i++){
            if(a[i]<mn)mn=a[i];
            if(a[i]>mx)mx=a[i];
            fq[a[i]]++;
        }
        int ans=0,l=mn,r=mx;
        while(l<=r){
            if(!fq[l])l++;// now consider l and r on a simple number line
            else if(!fq[r])r--;
            else{
                ans=max(ans,(l+r));
                fq[l]--;
                fq[r]--;
            }
        }
        return ans;
    }
};
