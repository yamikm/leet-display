/**
 * Given the root of a binary tree, return the vertical order traversal of its nodes' values. 
 * (i.e., from top to bottom, column by column).
 * If two nodes are in the same row and column, the order should be from left to right.
 *  
 
    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[9],[3,15],[20],[7]]

    Example 2:
    Input: root = [3,9,8,4,0,1,7]   
    Output: [[4],[9],[3,0,1],[8],[7]]

    Example 3:
    Input: root = [3,9,8,4,0,1,7,null,null,null,2,5] 
    Output: [[4],[9,5],[3,0,1],[8,2],[7]]

    Constraints:
    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

*/



// Approach:
// We use a map to store the values of each column with their corresponding row number.
// We traverse the tree in level order and for each node, we find its leftmost and rightmost 
// node in the tree. We then add all the values from the leftmost to the rightmost node to 
// the map.
// Important to note that we use queue and add left first and right second. This is because 
// if two nodes are in the same row and column, the order should be from left to right.
// Finally, we return the values of the map in the order of their keys.

// Intution:
// We use the vertical order traversal to find the order of the nodes in the tree when viewed 
// from top to bottom, column by column. We can find the vertical order by finding the leftmost 
// and rightmost node in each column. We can do this by traversing the tree in level order and 
// finding the leftmost and rightmost node in each level. We then add the values in between the 
// leftmost and rightmost node to the map, with the row number as the key. Finally, we return 
// the values of the map in the order of their keys.

#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;
struct TreeNode {
    int val; // value of the node
    TreeNode *left; // left child of the node
    TreeNode *right; // right child of the node
    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Function to perform vertical traversal of a binary tree
vector<vector<int>> verticalTraversal(TreeNode* root) {
    // Base case: if root is null, return an empty vector
    if(!root) return {};
    
    // Initialize a map to store the values of nodes in each column
    unordered_map<int, vector<int>> mp;
    
    // Initialize a queue to perform level order traversal
    queue<pair<TreeNode*, int>> q;
    
    // Initialize the minimum column value to 0
    int min = 0;
    
    // Enqueue the root node with column value 0
    q.push({root, min});
    
    // Perform level order traversal
    while(!q.empty()){
        
        // Dequeue the front node and its column value
        TreeNode* node = q.front().first;
        int col = q.front().second;
        q.pop();
        
        // Add the value of the node to the corresponding column in the map
        mp[col].push_back(node->val);
        
        // Enqueue the left and right children of the node, with updated column values
        if(node->left) {
            q.push({node->left, col - 1});
            if(col - 1 < min) min = col - 1;
        }
        if(node->right) q.push({node->right, col + 1});
    }

    // Initialize a vector to store the sorted vertical order traversal
    vector<vector<int>> out(mp.size(), vector<int>());
    
    // Fill the vector with the values stored in the map, sorted by column
    for(int i=0; i<mp.size(); i++){
        out[i] = mp[min++];
    }
    
    // Return the sorted vertical order traversal
    return out;
}
