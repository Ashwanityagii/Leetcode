

int calculate(char *s) {

    int n = strlen(s);

    long long *stack = (long long *)malloc(sizeof(long long) * (2 * n));
    int top = -1;

    long long result = 0;
    long long number = 0;
    long long sign = 1;

    for (int i = 0; s[i] != '\0'; i++) {

        if (isdigit(s[i])) {

            number = number * 10 + (s[i] - '0');

        } else if (s[i] == '+') {

            result += sign * number;
            number = 0;
            sign = 1;

        } else if (s[i] == '-') {

            result += sign * number;
            number = 0;
            sign = -1;

        } else if (s[i] == '(') {

            stack[++top] = result;
            stack[++top] = sign;

            result = 0;
            number = 0;
            sign = 1;

        } else if (s[i] == ')') {

            result += sign * number;
            number = 0;

            long long prevSign = stack[top--];
            long long prevResult = stack[top--];

            result = prevResult + prevSign * result;
        }
    }

    result += sign * number;

    free(stack);

    return (int)result;
}