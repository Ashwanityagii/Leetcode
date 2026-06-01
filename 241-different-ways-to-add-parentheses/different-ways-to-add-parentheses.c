typedef struct {
    int *arr;
    int size;
} Result;

Result solve(char *expression, int start, int end) {
    Result res;
    res.size = 0;

    int capacity = 16;
    res.arr = (int *)malloc(capacity * sizeof(int));

    int isNumber = 1;

    for (int i = start; i <= end; i++) {

        if (expression[i] == '+' ||
            expression[i] == '-' ||
            expression[i] == '*') {

            isNumber = 0;

            Result left = solve(expression, start, i - 1);
            Result right = solve(expression, i + 1, end);

            for (int j = 0; j < left.size; j++) {
                for (int k = 0; k < right.size; k++) {

                    int value;

                    if (expression[i] == '+')
                        value = left.arr[j] + right.arr[k];
                    else if (expression[i] == '-')
                        value = left.arr[j] - right.arr[k];
                    else
                        value = left.arr[j] * right.arr[k];

                    if (res.size == capacity) {
                        capacity *= 2;
                        res.arr = realloc(res.arr,
                                          capacity * sizeof(int));
                    }

                    res.arr[res.size++] = value;
                }
            }

            free(left.arr);
            free(right.arr);
        }
    }

    if (isNumber) {

        int num = 0;

        for (int i = start; i <= end; i++) {
            num = num * 10 + (expression[i] - '0');
        }

        if (res.size == capacity) {
            capacity *= 2;
            res.arr = realloc(res.arr,
                              capacity * sizeof(int));
        }

        res.arr[res.size++] = num;
    }

    return res;
}

int* diffWaysToCompute(char* expression, int* returnSize) {

    Result ans = solve(expression, 0,
                       strlen(expression) - 1);

    *returnSize = ans.size;
    return ans.arr;
}