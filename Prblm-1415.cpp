class Solution {
public:
    vector<string>ans;
    string s="";
    int n;

    void cons(){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }

        for(char q:{'a','b','c'}){
            if(s.empty()||s.back()!=q){
                s.push_back(q);
                cons();
                s.pop_back();//backtrack
            }
        }
    }

    string getHappyString(int n, int k) {
        this->n=n;

        if(k>(3*pow(2,n-1))) return "";//early exit
        cons();

        sort(ans.begin(),ans.end());
        
        return ans[k-1];
    }
};
