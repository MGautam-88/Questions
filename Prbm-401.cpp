class Solution {
public:
    const vector<vector<int>> one={{1,0},{2,0},{4,0},{8,0},{16,0},{32,0},{1,1},{2,1},{4,1},{8,1}};//possible values with one bit
    vector<string> ans;

    void make(vector<int> time){
        //make a string out of the given val of min and hr in this vector
        int min = time[0];
        int hr = time[1];
        if (hr > 11 || min > 59) return;

        string m = (min < 10 ? "0" : "") + to_string(min);//as we can have leading 0 in min
        ans.push_back(to_string(hr) + ":" + m);
    }

    //main part of this question is CalcMH
    void CalcMH(int idx,int ct,int min,int hr){
        if(ct==0){make({min,hr});return;}
        if(idx==10)return;
        if(ct+idx>10)return;

        if(one[idx][1]){CalcMH(idx + 1, ct - 1, min, hr + one[idx][0]);}
        else CalcMH(idx + 1, ct - 1, min + one[idx][0], hr);

        CalcMH(idx + 1, ct, min, hr);//don't pick
    }

    vector<string> readBinaryWatch(int p) {
        //if p is btw [1,8] then some ans else return empty string
        if(p<0 || p>8)return ans;
        CalcMH(0,p,0,0);
        return ans;
    }
};
