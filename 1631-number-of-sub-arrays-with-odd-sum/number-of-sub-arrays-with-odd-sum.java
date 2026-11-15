
class Solution {
    public int numOfSubarrays(int[] arr) {

        int mod = 1000000007;

        int odd = 0;
        int even = 1;

        int sum = 0;
        int ans = 0;

        for (int num : arr) {

            sum += num;

            if (sum % 2 == 0) {

                // Current sum is even
                // Previous odd prefixes make odd subarrays
                ans = (ans + odd) % mod;
                even++;

            } else {

                // Current sum is odd
                // Previous even prefixes make odd subarrays
                ans = (ans + even) % mod;
                odd++;
            }
        }

        return ans;
    }
}
