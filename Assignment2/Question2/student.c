#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Helper function to check height, balance, and BST property in one pass.
 * Returns the height of the tree if valid, or -1 if any property is violated.
 */
long long checkAVLRecursive(struct TreeNode* node, long long min, long long max) {
    if (node == NULL) {
        return 0; // Height of NULL is 0 
    }

    // 1. Check strict BST property 
    if (node->val <= min || node->val >= max) {
        return -1;
    }

    // 2. Recursively check left subtree
    long long leftHeight = checkAVLRecursive(node->left, min, node->val);
    if (leftHeight == -1) return -1;

    // 3. Recursively check right subtree
    long long rightHeight = checkAVLRecursive(node->right, node->val, max);
    if (rightHeight == -1) return -1;

    // 4. Check height-balanced property: abs(h1 - h2) <= 1 
    long long diff = leftHeight - rightHeight;
    if (diff < -1 || diff > 1) {
        return -1;
    }

    // 5. Return actual height: 1 + max(leftHeight, rightHeight) 
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool isAVL(struct TreeNode* root) {
    // Use long long for bounds to handle INT_MIN/INT_MAX 
    return checkAVLRecursive(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1) != -1;
}