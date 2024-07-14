/**
 * Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).
 * Each node will have a reference to its parent node. The definition for Node is below:
 
    class Node {
        public int val;
        public Node left;
        public Node right;
        public Node parent;
    }
* According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a 
* tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)."

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5 since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1

Constraints:    
The number of nodes in the tree is in the range [2, 104].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.

*/


/*
 * The approach to this algorithm is to find the path from the root to both nodes, and then compare the paths.
 * If we find a node that is in both paths, then we know it is the lowest common ancestor.
 * We can do this by using a temporary pointer to iterate through the path from the p/q node to the root node.
 * We can do this by moving the temporary pointer up the tree until it reaches the root node.
 * If ptmp is nullptr, it moves ptmp to q . If qtmp is nullptr, it moves qtmp to p. 
 * Once we find the node, we return it as the lowest common ancestor.
 */

/*
 * Method 2:
 * The second method uses a hash table to find the lowest common ancestor of two nodes in a binary tree.
 * The algorithm starts by finding the path from the root to the first node, and adding each node to a hash table.
 * We can do this by traversing the tree and adding each node to the hash table.
 * Once we have the path from the root to the first node, we can find the LCA by traversing the tree from the root to the second node.
 * We can do this by checking if each node in the tree is in the hash table.
 * If it is, we have found the LCA.
 * If it is not, we move on to the parent node.
 * This method runs in O(n) time, where n is the number of nodes between the root node and p or q in the tree.
 */

/*
 * Approach:
 * The approach to this problem is to first find the paths from the two nodes to the root, and we want to find the LCA of.
 * We can do this by either storing the path from the each node to the root in a vector of integers, or by using a hash table.
 * Once we have the paths, we can find the first node that is common in the two paths, which is the LCA.
 * This can be done by iterating through the paths from the end, and finding the first node that is common.
 * This gives us the LCA of the two nodes.
 * 
 */

#include <unordered_set>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

// Method 1:

/**
 * Find the lowest common ancestor of two nodes in a binary tree.
 *
 * @param p The first node.
 * @param q The second node.
 * @return The lowest common ancestor of the two nodes.
 */

Node* lowestCommonAncestor(Node* p, Node * q) {
    // Move the pointers up the tree until they meet
    Node *ptmp = p;
    Node *qtmp = q;
    while(ptmp!= qtmp){
        // If ptmp is nullptr, move it to q
        if(ptmp == nullptr){
            ptmp = q;
        }
        else{
            // Otherwise move it to its parent
            ptmp = ptmp->parent;
        }
        // If qtmp is nullptr, move it to p
        if(qtmp==nullptr){
            qtmp = p;
        }
        else{
            // Otherwise move it to its parent
            qtmp = qtmp->parent;
        }
    }
    // Return the first node that is in both paths
    return qtmp;
}

/**
 * Find the lowest common ancestor of two nodes in a binary tree using a hash table.
 *
 * @param p The first node.
 * @param q The second node.
 * @return The lowest common ancestor of the two nodes.
 */

Node* lowestCommonAncestor(Node* p, Node * q) {
    // Create a hash table to store the nodes from the first node to the root
    unordered_set<int> cache;
    while(p){
        // If p and q have the same value, return p
        if(p ->val == q->val) return p;
        // Otherwise, add p to the cache and move to its parent
        cache.insert(p->val);
        p = p->parent;
    }

    // Traverse the tree from the root to the second node, checking if each node is in the cache
    while(q){
        if(cache.count(q->val) > 0 ){
            // If the node is in the cache, return it
            return q;
        }
        // Otherwise, move to the parent node
        q = q->parent;
    }
    // If no common node is found, return nullptr
    return nullptr; 
}
