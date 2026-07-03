bool canJump(int* nums, int numsSize) {
    int reach = 0;
    for (int i = 0; i < numsSize && i <= reach; i++) {
        if (i + nums[i] > reach)
            reach = i + nums[i];
    }
    return reach >= numsSize - 1;
}