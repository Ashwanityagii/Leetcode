
class Solution {
    public int romanToInt(String s) {

        int ans = 0;

        // Traverse the Roman string
        for (int i = 0; i < s.length(); i++) {

            int curr = 0;
            int next = 0;

            // Get current character value
            switch (s.charAt(i)) {
                case 'I': curr = 1; break;
                case 'V': curr = 5; break;
                case 'X': curr = 10; break;
                case 'L': curr = 50; break;
                case 'C': curr = 100; break;
                case 'D': curr = 500; break;
                case 'M': curr = 1000; break;
            }

            // Get next character value if available
            if (i + 1 < s.length()) {
                switch (s.charAt(i + 1)) {
                    case 'I': next = 1; break;
                    case 'V': next = 5; break;
                    case 'X': next = 10; break;
                    case 'L': next = 50; break;
                    case 'C': next = 100; break;
                    case 'D': next = 500; break;
                    case 'M': next = 1000; break;
                }
            }

            // If current value is smaller, subtract it
            if (curr < next) {
                ans -= curr;
            }
            // Otherwise, add it
            else {
                ans += curr;
            }
        }

        return ans;
    }
}
