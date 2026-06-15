long long maxTotalValue(int* nums, int numsSize, int k) {
    int mn = nums[0], mx = nums[0];

     for(int i = 1; i <numsSize; i++){
        if(nums[i] < mn) mn = nums[i];
         if(nums[i] > mx) mx = nums[i];
     }
      long long diff = (long long)mx - mn;

      return diff * k;
}