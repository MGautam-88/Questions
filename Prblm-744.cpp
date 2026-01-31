class Solution {
public:
    char nextGreatestLetter(vector<char>& a, char t) {
        // Linear search : O(n)
        // for(char x:a){if(x>t) return x;}return a[0];
        
        //BS:O(lg n)
        int l=0,h=a.size()-1;
        int ans=-1;
        while(l<=h){
            int m = l + (h-l)/2;

            if(a[m]>t){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }

        return ans== -1?a[0]:a[ans];
    }
};
