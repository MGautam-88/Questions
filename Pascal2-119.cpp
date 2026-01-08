class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)return {1};

        int n = rowIndex + 1;
        vector<int> previous;
        
        while (n--) {
            int ps = previous.size();
            vector<int> curr;
            for (int i = 0; i <= ps; i++) {
                if (i == 0 || i == ps) {
                    curr.push_back(1);
                } else {
                    curr.push_back(previous[i - 1] + previous[i]);
                }
            }

            previous = curr;
        }

        return previous;
    }
};
