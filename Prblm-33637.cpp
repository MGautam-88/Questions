// pehle p nikal liya check kiya , fir q nikala check kiya , last mein q -> n tak strictly increasing hai to true nahi to pehle hi false kar denge

class Solution {
public:
    bool isTrionic(vector<int>& a) {
        int n=a.size();
        int p=0,q=0;

        for(int i=1;i<n;i++){
            if(a[i]<=a[i-1]){p=i-1;break;}
        }
        if(p<=0)return false;
        for(int i=p+1;i<n;i++){
            if(a[i]>=a[i-1]){q=i-1;break;}
        }
        if(p>=q || q==n-1)return false;
        for(int i=q+1;i<n;i++){
            if(a[i]<=a[i-1])return false;
        }
        return true;
    }
};//o(n)
//----------------------------------------------------------------------------------------------------------------------------------------------------------------

// or we just simply counted the number of sign changes if it is 2 return true else false. ** check a[0]>=a[1] if yes then return false as we need only (inc -> dec -> inc)

class Solution {
public:
    bool isTrionic(vector<int>& a) {
        if(a[0]>=a[1])return 0;
        int ct=0,n=a.size();
        for(int i=1;i<n-1;i++){
            int x=(a[i]-a[i-1]);
            int y=(a[i+1]-a[i]);
            if(x==0 or y==0)return false;
            if(x>0 != y>0)ct++;
        }
        return ct==2;
    }
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
