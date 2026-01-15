class Solution {
public:
    vector<int> numberOfLines(vector<int>& w, string st) {
        int  a = 1, b = 0;
        for (char g : st) {
            int s = w[g - 'a'];
            if (s + b > 100) {
                a++;
                b=s;
            } else {
                b += s;
            }
        }

        return {a, b};
    }
};
