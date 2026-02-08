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
        //or isme har node ke liye height calc kar rahe hein to complexity jyada ho rahi hai 
    }
};
//---------------------------------------------------------------------------------------------------------------------------------
//------------------------we will check if balanced in the same iteration as in calc height =>O(n)---------------------------------

class Solution {
public:
    int cH(TreeNode* x){
        if(x==nullptr)return 0;

        int lh=cH(x->left);
        if(lh==-1)return -1;//early return

        int rh=cH(x->right);
        if(rh==-1)return -1;//early return 

        if(abs(lh-rh)>1)return -1;

        return max(lh,rh)+1;
    }

    bool isBalanced(TreeNode* x) {
        return cH(x)!=-1;
        //ch mein hi check ho ja raha hai saath saath =>O(n)
        //where n is the number of nodes
    }
};
