 int remainingA = 0;
        for (char c : s) {
            if (c == 'a') remainingA++;
        }

        int bCount = 0;
        int ans = remainingA;

        for (char c : s) {
            if (c == 'a') {
                remainingA--;
            }

            ans = min(ans, bCount + remainingA);

            if (c == 'b') {
                bCount++;
            }
        }

        return ans;
