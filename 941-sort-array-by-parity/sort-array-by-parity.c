/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int left = 0, right = numsSize - 1;

    while(left < right) {
        // left pe even hai to aage badho
        if(nums[left] % 2 == 0) {
            left++;
        }
        // right pe odd hai to peeche aao
        else if(nums[right] % 2 == 1) {
            right--;
        }
        // swap
        else {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }

    *returnSize = numsSize;
    return nums;
}