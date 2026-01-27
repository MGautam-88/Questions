class Solution {
public:
    //kya is val pe rob karna feasible hai
    bool can(vector<int>& a, int k, int x) {
        int ct = 0;
        int n = a.size();

        for (int i = 0; i < n; i++) {
            if (a[i] <= x) {
                ct++;
                i++; // skip adjacent
            }
        }
        return ct >= k;//agar x se chotte non adj min k elem mil gaye to true
    }

    int minCapability(vector<int>& a, int k) { 
        int l = *(min_element(a.begin(),a.end())); 
        int h=*(max_element(a.begin(),a.end()));

        //abb ans to a ke elem mein se hi hoga 
        while(l<h){
            int md= l +(h-l)/2;

            if(can(a,k,md)) h = md;//agar iss threshold par rob kar sakte hein to orr chotta dhundo 
            else l=md+1;//agar ye thershold pe nahi kar paa rahe to val bhadao thodi
        }

        return l;
    }
};
