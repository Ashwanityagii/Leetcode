
class Solution {
    public String digitSum(String s, int k) {

        // Repeat until string length becomes <= k
        while (s.length() > k) {

            // Store the new string
            StringBuilder ans = new StringBuilder();

            // Divide string into groups of k characters
            for (int i = 0; i < s.length(); i += k) {

                int sum = 0;

                // Calculate the ending index of current group
                int end = Math.min(i + k, s.length());

                // Calculate sum of digits in current group
                for (int j = i; j < end; j++) {
                    sum += s.charAt(j) - '0';
                }

                // Append sum to the new string
                ans.append(sum);
            }

            // Update original string
            s = ans.toString();
        }

        return s;
    }
}
