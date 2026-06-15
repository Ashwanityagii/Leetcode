
void solve(char **ans, int *returnSize, char *s,
           int pos, int open, int close, int n)
{
    if (pos == 2 * n)
    {
        s[pos] = '\0';

        ans[*returnSize] = malloc((2 * n + 1) * sizeof(char));
        strcpy(ans[*returnSize], s);

        (*returnSize)++;
        return;
    }

    if (open < n)
    {
        s[pos] = '(';
        solve(ans, returnSize, s, pos + 1, open + 1, close, n);
    }

    if (close < open)
    {
        s[pos] = ')';
        solve(ans, returnSize, s, pos + 1, open, close + 1, n);
    }
}

char **generateParenthesis(int n, int *returnSize)
{
    char **ans = malloc(15000 * sizeof(char *));
    char *s = malloc((2 * n + 1) * sizeof(char));

    *returnSize = 0;

    solve(ans, returnSize, s, 0, 0, 0, n);

    free(s);
    return ans;
}