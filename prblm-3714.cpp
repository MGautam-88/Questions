class Solution {
public:
    int single(string &s){
        int ans=0,ct=0;
        int n=s.size();

        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])ct++;
            else ct=0;
            ans=max(ct+1,ans);
        }

        return ans;
    }

    int duo(string &s,char x,char y){
        int n=s.size();
        int ans=0;
        int df=0;
        unordered_map<int,int> firstPos;
        //agar diff kahi par firse wahi  ho raha hai matlab beech ke elem unka count eq hai(+1,-1)

        firstPos[0]=-1;//mp ke agle index se ans calc kare ge 
        //to base case ki 0 se hai apna ans

        for(int i=0;i<n;i++){
            if(s[i]==x)df++;
            else if(s[i]==y)df--;

            else{
                df=0;
                firstPos.clear();
                firstPos[0]=i;//agar aage kahi df 0 hua to iss i se lenge ans
                continue;
            }

            if(firstPos.count(df)){
                ans=max(ans,i-firstPos[df]);//len uske ek aage se le kar i tak
            }
            else{
                firstPos[df]=i;
            }
        }

        return ans;
    }

    int trice(string &s){
        int n=s.size();
        int a=0,b=0,c=0;
        int ans=0;

        // map<vector<int>, int> firstPos;//vector taking more runtime
        map<pair<int,int>, int> firstPos;//({d1,d2},i)
        firstPos[{0,0}]=-1;

        for(int i=0;i<n;i++){
            if(s[i]=='a')a++;
            else if(s[i]=='b')b++;
            else c++;

            int d1=a-b;//we took refrence as char=> 'a'
            int d2=a-c;//+ve if a>b or c else -ve

            // vector<int> chk = {d1,d2};//using map causes more runtime
            pair<int,int> chk = {d1,d2};

            if(firstPos.count(chk)){
                ans=max(ans,i-firstPos[chk]);//matlab ki ye df pehle bhi kahi aaye hein
            }
            else {
                firstPos[chk]=i;
            }
        }

        return ans;
    }

    int longestBalanced(string s) {
        if(s.size()<3)return s.size();
        return max({single(s),duo(s,'a','b'),duo(s,'a','c'),duo(s,'b','c'),trice(s)});
    }
};
