/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int dfsSum(TreeNode* x,int curr){
        if(x==NULL)return 0;

        curr = curr*2 + x->val;
        if(x->left ==NULL && x->right==NULL)return curr;

        return dfsSum(x->left,curr) + dfsSum(x->right , curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfsSum(root,0);
    }
};

//----------------------------------------------------------------------------------------------------------------------------------------

//Iterative version

class Solution {
public:
    int sumRootToLeaf(TreeNode* x) {
        if(x==NULL)return 0;

        int sum=0;
        stack<pair<TreeNode* , int>> st;
        st.push({x,0});

        while(!st.empty()){
            auto [node,curr]=st.top();
            st.pop();//LIFO

            curr=curr*2 + node->val;

            if(node->left == NULL && node->right == NULL){
                sum+=curr;
            }

            if(node->right !=NULL){
                st.push({node->right,curr});
            }

            if(node->left !=NULL){
                st.push({node->left,curr});
            }
        }

        return sum;
    }
};
