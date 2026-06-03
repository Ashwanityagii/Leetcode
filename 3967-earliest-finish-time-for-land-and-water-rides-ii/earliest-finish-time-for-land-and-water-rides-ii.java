import java.util.*;

class Solution {

    private long solve(int[] Astart, int[] Adur,
                       int[] Bstart, int[] Bdur) {

        int m = Bstart.length;

        int[][] rides = new int[m][2];
        for (int i = 0; i < m; i++) {
            rides[i][0] = Bstart[i];
            rides[i][1] = Bdur[i];
        }

        Arrays.sort(rides, (a, b) -> Integer.compare(a[0], b[0]));

        int[] starts = new int[m];
        long[] prefMinDur = new long[m];
        long[] suffMinFinish = new long[m];

        for (int i = 0; i < m; i++) {
            starts[i] = rides[i][0];

            if (i == 0)
                prefMinDur[i] = rides[i][1];
            else
                prefMinDur[i] = Math.min(prefMinDur[i - 1], rides[i][1]);
        }

        for (int i = m - 1; i >= 0; i--) {
            long val = (long) rides[i][0] + rides[i][1];

            if (i == m - 1)
                suffMinFinish[i] = val;
            else
                suffMinFinish[i] = Math.min(suffMinFinish[i + 1], val);
        }

        long ans = Long.MAX_VALUE;

        for (int i = 0; i < Astart.length; i++) {
            long t = (long) Astart[i] + Adur[i];

            int idx = upperBound(starts, t);

            long best = Long.MAX_VALUE;

            if (idx > 0)
                best = Math.min(best, t + prefMinDur[idx - 1]);

            if (idx < m)
                best = Math.min(best, suffMinFinish[idx]);

            ans = Math.min(ans, best);
        }

        return ans;
    }

    private int upperBound(int[] arr, long target) {
        int left = 0, right = arr.length;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }

    public int earliestFinishTime(int[] landStartTime,
                                  int[] landDuration,
                                  int[] waterStartTime,
                                  int[] waterDuration) {

        long ans1 = solve(
                landStartTime, landDuration,
                waterStartTime, waterDuration);

        long ans2 = solve(
                waterStartTime, waterDuration,
                landStartTime, landDuration);

        return (int) Math.min(ans1, ans2);
    }
}