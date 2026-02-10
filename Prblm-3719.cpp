class Solution {
public:
    int longestBalanced(vector<int>& a) {
        int ans=0;
        int n=a.size();

        for(int i=0;i<n;i++){
            unordered_set<int> o,e;
            for(int j=i;j<n;j++){
                if(a[j]&1)o.insert(a[j]);
                else e.insert(a[j]);

                if(o.size()==e.size()){
                    ans=max(ans,(j-i+1));
                    if(ans==n) return n;
                }
            }
        }

        return ans;
    }
};//Technically, unordered_set operations can degrade to O(n) in pathological hashing cases.
// ==> Worst TC : O(n^3) 

//---------------------------------------------------------------------------------------------------------------------------------------------------------
//as MAX size of elements is known i.e a[i]<=10^5 we can use simply a vector to store freq , This will give a better runtime as compared to unordered_set

class Solution {
public:
    int longestBalanced(vector<int>& a) {
        int ans=0;
        int n=a.size();

        for(int i=0;i<n;i++){
            vector<bool> o(100001, false);
            vector<bool> e(100001, false);
            int oc=0,ec=0;

            for(int j=i;j<n;j++){
                if((a[j]&1)){
                    if(!o[a[j]]){
                        o[a[j]]=1;
                        oc++;
                    }
                }
                else{
                    if(!e[a[j]]){
                        e[a[j]]=1;
                        ec++;
                    }
                }

                if(oc==ec){
                    ans=max(ans,(j-i+1));
                    if(ans==n) return n;
                }
            }
        }

        return ans;
    }
};//O(n²) + O(n × 100001)

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//instead of Repeated vector allocation , we can use a global vector and clear it after use in each iteration

short freq[100001]={0};
class Solution {
public:
    static int longestBalanced(vector<int>& a) {
        int n=a.size();
        int ans=0;
        for(int l=0; l<n; l++){
            int cnt[2]={0};//odd and even counter
            for(int r=l; r<n; r++){
                int x=a[r];
                if (++freq[x]==1) cnt[x&1]++;
                if (cnt[0]==cnt[1]){
                    ans=max(ans, r-l+1);
                }
                    
            }
            for(int i=l; i<n; i++) freq[a[i]]=0;
        }
        return ans;
    }
};//O(n^2) but better as we use one global freq store


//------------------------------------------------------------------------------------------------------------------------------------------------------------------
// this one minimizes work inside the hot loop --> only 1 array , single int tracker(diff) ,  branch removal using arithmetic[(1 - (x&1)*2)] and early break

bool seen[100001]={false};
class Solution {
public:
    static int longestBalanced(vector<int>& a) {
        int n=a.size();
        int ans=0;
        for(int l=0; l<n; l++){
            if (l>n-ans) break;// ans cannot be longer then this current ans
            int diff=0;//shows diff between no. of Even and Odd 
            for(int r=l; r<n; r++){
                int x=a[r];
                if (!seen[x]) {diff+=(1-(x&1)*2), seen[x]=1; }
                //even->+1 and odd->-1

                if (diff==0)ans=max(ans, r-l+1);
            }
            for(int i=l; i<n; i++) seen[a[i]]=0;//reset
        }
        return ans;
    }
};
