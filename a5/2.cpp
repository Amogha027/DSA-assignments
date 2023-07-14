#include <bits/stdc++.h>
using namespace std;

#define MOD(x, y) ((((x) - (y)) > 0) ? ((x) - (y)) : ((y) - (x)))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)
#define endl '\n'
typedef long long ll;

int n, m, l = 50005, ans = 0;

void dfs(int u, int v, vector<vector<int>> &dp, vector<vector<int>> &arr)
{
    dp[u][0] = 1;
    for (int i = 0; i < arr[u].size(); i++)
    {
        int k = arr[u][i];
        if (k != v)
        {
            dfs(k, u, dp, arr);
            for (int j = 1; j <= m; j++)
                dp[u][j] += dp[k][j - 1];
        }
    }

    ans += dp[u][m];
    int temp = 0;
    for (int i = 0; i < arr[u].size(); i++)
    {
        int k = arr[u][i];
        if (k != v)
        {
            for (int j = 1; j < m; j++)
                temp += dp[k][j - 1] * (dp[u][m - j] - dp[k][m - j - 1]);
        }
    }
    // cout << u << " " << dp[u][m] + (temp / 2) << endl;
    ans += (temp / 2);
}

void solve()
{
    // int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        arr[a].push_back(b);
        arr[b].push_back(a);

        l = MIN(l, a);
        l = MIN(l, b);
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dfs(1, -1, dp, arr);

    cout << ans << endl;
    ans = 0;
    l = 50005;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
    return 0;
}