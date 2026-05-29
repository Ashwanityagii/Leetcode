#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createBST(int* nums, int left, int right) {

    if(left > right) {
        return NULL;
    }

    int mid = (left + right) / 2;

    struct TreeNode* root =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    root->val = nums[mid];

    root->left = createBST(nums, left, mid - 1);

    root->right = createBST(nums, mid + 1, right);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {

    return createBST(nums, 0, numsSize - 1);
}