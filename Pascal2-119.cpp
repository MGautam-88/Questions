class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)return {1};

        int n = rowIndex + 1;
        vector<int> previous;
        
        while (n--) {
            int ps = previous.size();
            vector<int> current;
            for (int i = 0; i <= ps; i++) {
                if (i == 0 || i == ps) {
                    current.push_back(1);
                } else {
                    current.push_back(previous[i - 1] + previous[i]);
                }
            }

            previous = current;
        }

        return previous;
    }
};
