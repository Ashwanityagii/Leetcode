
import java.util.Arrays;

class Solution {
    public int hIndex(int[] citations) {

        // Step 1: Sort the array in ascending order
        Arrays.sort(citations);

        // Total number of research papers
        int n = citations.length;

        // Step 2: Traverse the sorted array
        for (int i = 0; i < n; i++) {

            // Number of papers from current index to the end
            int h = n - i;

            // Step 3: Check if current paper has at least h citations
            if (citations[i] >= h) {

                // Return the maximum valid H-index
                return h;
            }
        }

        // If no valid H-index is found
        return 0;
    }
}
