/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int compare(const void *a, const void *b) {
    int *row1 = *(int **)a;
    int *row2 = *(int **)b;

    return row1[0] - row2[0];
}

int** merge(int** intervals, int intervalsSize,
            int* intervalsColSize,
            int* returnSize,
            int** returnColumnSizes) {

    qsort(intervals, intervalsSize, sizeof(int *), compare);

    int **ans = malloc(intervalsSize * sizeof(int *));
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));

    int k = 0;

    ans[0] = malloc(2 * sizeof(int));
    ans[0][0] = intervals[0][0];
    ans[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;

    for (int i = 1; i < intervalsSize; i++) {

        if (intervals[i][0] <= ans[k][1]) {

            if (intervals[i][1] > ans[k][1])
                ans[k][1] = intervals[i][1];

        } else {

            k++;

            ans[k] = malloc(2 * sizeof(int));
            ans[k][0] = intervals[i][0];
            ans[k][1] = intervals[i][1];
            (*returnColumnSizes)[k] = 2;
        }
    }

    *returnSize = k + 1;
    return ans;
}