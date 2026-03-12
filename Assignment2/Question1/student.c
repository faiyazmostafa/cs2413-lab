#include <stddef.h>  // NULL

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Search in a Binary Search Tree (BST)
 * Time Complexity: O(h), where h is the tree height.
 * Space Complexity: O(1) for iterative or O(h) for recursive.
 */
struct TreeNode* bstSearch(struct TreeNode* root, int target) {
    // Base case: root is null (not found) or root matches target (found)
    if (root == NULL || root->val == target) {
        return root;
    }

    // If target is smaller than current node, search the left subtree
    if (target < root->val) {
        return bstSearch(root->left, target);
    }

    // If target is larger than current node, search the right subtree
    return bstSearch(root->right, target);
}