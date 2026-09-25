class Solution {
public:
    int n;

    vector<vector<bool>> isPalindrome;

    int t[2001][2001];

    int solve(int i, int j, string &s)
    {
        if(i > j)
            return 0;

        if(t[i][j] != -1)
            return t[i][j];

        int minPartition = INT_MAX;

        for(int idx = i; idx <= j; idx++)
        {
            if(isPalindrome[i][idx])
            {
                int partition = solve(idx + 1, j, s);

                if(partition != INT_MAX)
                    minPartition = min(minPartition, 1 + partition);
            }
        }

        return t[i][j] = minPartition;
    }

    int minCut(string s) {
        n = s.size();

        memset(t, -1, sizeof(t));

        isPalindrome.resize(n, vector<bool>(n, false));

        for(int l = 1; l <= n; l++)
        {
            for(int i = 0; i + l - 1 < n; i++)
            {
                int j = i + l - 1;

                if(i == j) 
                    isPalindrome[i][j] = true;

                else if(i + 1 == j) 
                    isPalindrome[i][j] = (s[i] == s[j]);

                else
                    isPalindrome[i][j] =
                        (s[i] == s[j] &&
                         isPalindrome[i + 1][j - 1]);
            }
        }

        return solve(0, n - 1, s) - 1;
    }
};