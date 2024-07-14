/**
 * Given the root of a binary tree, return the lowest common ancestor (LCA) of two given nodes, 
 * p and q. If either node p or q does not exist in the tree, return null. 
 * All values of the nodes in the tree are unique.
 * According to the definition of LCA on Wikipedia: 
 * "The lowest common ancestor of two nodes p and q in a binary tree T is the lowest node
 * that has both p and q as descendants (where we allow a node to be a descendant of itself)". 
 * A descendant of a node x is a node y that is on the path from node x to some leaf node.

 Example 1:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    Output: 3
    Explanation: The LCA of nodes 5 and 1 is 3.

 Example 2:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    Output: 5
    Explanation: The LCA of nodes 5 and 4 is 5.

 Example 3:
    Input: root = [1,2], p = 1, q = 2
    Output: 1

 Example 4:
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 10
    Output: null
    Explanation: Node 10 does not exist in the tree, so return null.

 Constraints:
    The number of nodes in the tree is in the range [1, 10^4].
    -10^9 <= Node.val <= 10^9
    All Node.val are unique.
    p != q
 */


/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
// The algorithm for this problem is a depth-first search (DFS) approach.
// The idea is to traverse the tree from the root node and find p & q in the tree. 
// If the current node is one of p & q, then the we increment the count.
// if left or right child of the current node is p or q, then the count is incremented.
// we recursively traverse the left and right subtrees.
// If the count is 2 and ans is not set, the current node is the lowest common ancestor. 
// We set ans to the current node.
// The time complexity of this approach is O(n), where n is the number of nodes in the tree.

TreeNode* ans = nullptr;
int found(TreeNode* root, TreeNode* p, TreeNode* q ){
        if(root == nullptr) return 0;
        if(ans != nullptr) return 0;
        int count =0;
        if(root == p || root == q) count = 1;
        if(root->left){
            count += found( root->left,  p, q );
        }
        if(root->right){
            count += found( root->right,  p, q );
        }
        if(count == 2 && ans == nullptr) ans = root; 
        return count;
    }
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    found( root,  p, q );
    return ans;
}
