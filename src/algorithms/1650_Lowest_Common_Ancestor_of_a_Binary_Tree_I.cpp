/**
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
 * between two nodes p and q as the lowest node in T that has both p and q as descendants 
 * (where we allow a node to be a descendant of itself).”
 * 
 *  Example 1:
        Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
        Output: 3
        Explanation: The LCA of nodes 5 and 1 is 3.

 *  Example 2:
        Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
        Output: 5
        Explanation: The LCA of nodes 5 and 4 is 5. 
        since a node can be a descendant of itself according to the LCA definition.

 * Constraints:
        The number of nodes in the tree is in the range [2, 105].
        -109 <= Node.val <= 109
        All Node.val are unique.
        p != q
        p and q will exist in the tree.
 
 */

struct  TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* ans = nullptr;
bool rec(TreeNode* root, TreeNode* p, TreeNode* q ){
    
    if(ans != nullptr) return false;
    bool left =false , right=false;
    if(root->left){
        left = rec(root->left, p , q);
    }
    if(root->right){
        right = rec(root->right, p , q);
    }
    //cout<< root->val<< "  " << left << "  " <<right << endl;
    if(p->val == root->val || q->val == root->val){
        if(left || right){
            ans = root;
            return false;
        }else{
            return true;
        }
    }
    if(left && right){
        ans = root;
        return false;
    }

    return left || right;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //TreeNode* ans =nullptr ;
        rec(root,p,q);
        return ans;
    }