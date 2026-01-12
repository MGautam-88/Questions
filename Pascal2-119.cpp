class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)return {1};

        int n = rowIndex + 1;
        vector<int> prev;
        
        while (n--) {
            int ps = prev.size();
            vector<int> curr;
            for (int i = 0; i <= ps; i++) {
                if (i == 0 || i == ps) {
                    curr.push_back(1);
                } else {
                    curr.push_back(prev[i - 1] + prev[i]);
                }
            }

            prev = curr;
        }

        return prev;
    }
};
