#include <bits/stdc++.h>
using namespace std;

#define MOD(x, y) ((((x) - (y)) > 0) ? ((x) - (y)) : ((y) - (x)))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)
#define endl '\n'
typedef long long ll;

vector<int> v[100005], w[100005];
int n, m;

void dfs(int u, int *vst1)
{
    vst1[u] = 1;
    for (int i = 0; i < v[u].size(); i++)
    {
        int k = v[u][i];
        if (vst1[k] != 1)
            dfs(k, vst1);
    }
}

void dfs_lite(int u, int *vst2)
{
    vst2[u] = 1;
    for (int i = 0; i < w[u].size(); i++)
    {
        int k = w[u][i];
        if (vst2[k] != 1)
            dfs_lite(k, vst2);
    }
}

void solve()
{
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        w[b].push_back(a);
    }

    int vst1[n + 1] = {}, vst2[n + 1] = {};
    dfs(1, vst1);

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vst1[i] == 1)
            count++;
    }

    if (count == n)
    {
        dfs_lite(1, vst2);
        int c = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vst2[i] == 1)
                c++;
        }

        if (c == n)
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "NO";
    cout << endl;   
}

int main()
{
    // int t;
    // cin >> t;

    // while (t--)
    solve();
    return 0;
}