#include <bits/stdc++.h>
using namespace std;

#define MOD(x, y) ((((x) - (y)) > 0) ? ((x) - (y)) : ((y) - (x)))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)
#define endl '\n'
typedef long long ll;

vector<pair<int, int>> arr[105];
set<int> ss;
int n, m, t;

void recur(int w, int v, int *vst, int k)
{
    vst[w] = 1;
    if (w == v)
    {
        ss.insert(k);
        return;
    }

    if (arr[w].size() == 0)
        return;

    int z, val;
    for (int i = 0; i < arr[w].size(); i++)
    {
        z = arr[w][i].first;
        val = arr[w][i].second;
        if (vst[z] == 0 && val == k)
            recur(z, v, vst, k);
    }
    return;
}

int fun(int u, int v)
{
    int w, k;
    for (int i = 0; i < arr[u].size(); i++)
    {
        int vst[105] = {};
        vst[u] = 1;
        w = arr[u][i].first;
        k = arr[u][i].second;
        recur(w, v, vst, k);
    }
    return ss.size();
}

void solve()
{
    // int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        arr[a].push_back(make_pair(b, c));
        arr[b].push_back(make_pair(a, c));
    }

    // int t;
    cin >> t;

    while (t--)
    {
        int u, v;
        cin >> u >> v;

        if (arr[u].size() > 0 && arr[v].size() > 0)
            fun(u, v);

        cout << ss.size() << endl;
        ss.clear();
    }
}

int main()
{
    solve();
    return 0;
}