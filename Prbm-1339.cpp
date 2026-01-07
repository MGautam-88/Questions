/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
struct LeftRightSum {
    long long leftSum;
    long long rightSum;
};

class Solution {
public:
    static constexpr int MOD = 1000000007;
    unordered_map<TreeNode*, LeftRightSum> sums;
    long long result = 0;

    int maxProduct(TreeNode* root) {
        long long totalSum = dfs(root);

        for (const auto& entry : sums) {
            long long l = entry.second.leftSum;
            long long r = entry.second.rightSum;

            result = max(result, max(l * (totalSum - l), r * (totalSum - r)));
        }

        return static_cast<int>(result % MOD);
    }

private:
    long long dfs(TreeNode* node) {
        if (!node)
            return 0;

        long long left = dfs(node->left);
        long long right = dfs(node->right);

        sums[node] = {left, right};

        return node->val + left + right;
    }
};
