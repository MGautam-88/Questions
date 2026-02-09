class Solution {
public:
    void ITrav(TreeNode* x,vector<int> &inorder){
        //this Fn take cares of the BST properties  l<R<r
        if(x==nullptr)return;
        ITrav(x->left,inorder);
        inorder.push_back(x->val);
        ITrav(x->right,inorder);
    }

    TreeNode* createBST(vector<int> &inorder ,int l,int h){
        if(l>h)return nullptr;
        int mid= l+(h-l)/2;
        // This function constructs a tree using the middle element as root recursively. Hence Balancing the tree

        TreeNode* lt=createBST(inorder,l,mid-1);
        TreeNode* rt=createBST(inorder,mid+1,h);

        return new TreeNode(inorder[mid],lt,rt);
    }

    TreeNode* balanceBST(TreeNode* x) {
        vector<int> inorder;
        ITrav(x,inorder);//pehle treenode se ek array banna li inorder traversal ki
        int n=inorder.size();

        return createBST(inorder,0,n-1);//fir uss inorder traversal AND BST ki prop ka use karke ek tree banna liya 
    }
};
