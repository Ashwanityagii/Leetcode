
import java.util.Arrays;

class Solution {
    public int majorityElement(int[] nums) {

        // Step 1: Sort the array
        Arrays.sort(nums);

        // Step 2: Initialize count
        int count = 1;

        // Step 3: Compare current element with previous
        for (int i = 1; i < nums.length; i++) {

            if (nums[i] == nums[i - 1]) {
                count++;
            } 
            else {
                count = 1;
            }

            // Step 4: Check majority element
            if (count > nums.length / 2) {
                return nums[i];
            }
        }

        return nums[0];
    }
}
