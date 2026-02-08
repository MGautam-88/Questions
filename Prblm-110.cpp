//------------------------------------Naive Approch O(n^2) , where n is the number of nodes----------------------------------------
class Solution {
public:
    int cH(TreeNode* x){
        if(x==nullptr)return 0;

        return max(cH(x->left),cH(x->right)) + 1;
    }

    bool isBalanced(TreeNode* x) {
        if(x==nullptr)return true;//leaf ka to ho ga hi

        int lh= cH(x->left);
        int rh=cH(x->right);

        if(abs(lh-rh)>1)return 0;

        return isBalanced(x->left) && isBalanced(x->right);
        //pehle pura left wala subtree check hoga fir right wala subtree
    }
};
//---------------------------------------------------------------------------------------------------------------------------------
