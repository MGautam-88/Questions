const int inf=1e9;
class Solution {
public:
    long long minimumCost(string a, string b, vector<char>& o, vector<char>& nw, vector<int>& cs) {
        int n=a.size();
        int m=o.size();

        vector<vector<int>> dst(26,vector<int> (26,inf));

        for(int i=0;i<26;i++) dst[i][i]=0;

        for(int i=0;i<m;i++){
            int u= o[i]-'a';//for indexing in dst
            int v= nw[i]-'a';
            dst[u][v]=min(dst[u][v],cs[i]);
        }// now dst will contain direct conversion cost from u to v if it exists 

        // Floyd-Warshall for min cost
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dst[i][k]<inf && dst[k][j]<inf){
                        dst[i][j]=min(dst[i][j],(dst[i][k] + dst[k][j]));
                    }
                }
            }
        }

        vector<pair<pair<char,char>,int>> ed;

        for(int u=0;u<26;u++){
            for(int v=0;v<26;v++){
                if(u!=v && dst[u][v]<inf){
                    ed.push_back({{(char)('a'+u),(char)('a'+v)},dst[u][v]});
                    //Bcz we used int u and v in the dst as it was easy for indexing
                }
            }
        }

        // we will create a lookup table to check the pairs of char
        vector<vector<int>> ck(26,vector<int>(26,-1));
        for(auto &e:ed){
            char u = e.first.first;
            char v = e.first.second;
            int c = e.second;
            ck[u-'a'][v-'a']=c;
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            if(a[i]==b[i])continue;

            int u=a[i]-'a';
            int v=b[i]-'a';
            if(ck[u][v]==-1){
                return -1;
            }
            ans+=ck[u][v];
        }
        return ans;
    }
};
// dst Table -> edge -> ck lookup table 
// we can remove the edge and lookup table and directly use the dst table to calc the ans (if dst is not inf then add it to ans)


const int inf=1e9;
class Solution {
public:
    long long minimumCost(string a, string b, vector<char>& o, vector<char>& nw, vector<int>& cs) {
        int n=a.size();
        int m=o.size();

        vector<vector<int>> dst(26,vector<int> (26,inf));

        for(int i=0;i<26;i++) dst[i][i]=0;

        for(int i=0;i<m;i++){
            int u= o[i]-'a';//for indexing in dst
            int v= nw[i]-'a';
            dst[u][v]=min(dst[u][v],cs[i]);
        }// now dst will contain direct conversion cost from u to v if it exists 

        // Floyd-Warshall for min cost
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dst[i][k]<inf && dst[k][j]<inf){
                        dst[i][j]=min(dst[i][j],(dst[i][k] + dst[k][j]));
                    }
                }
            }
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            if(a[i]==b[i])continue;

            int u=a[i]-'a';
            int v=b[i]-'a';
            if(dst[u][v]==inf){
                return -1;
            }
            ans+=dst[u][v];
        }
        return ans;
    }
};
