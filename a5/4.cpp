#include <bits/stdc++.h>
using namespace std;

#define INF LONG_MAX
#define MOD(x, y) ((((x) - (y)) > 0) ? ((x) - (y)) : ((y) - (x)))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, l;
    cin >> n >> m >> k;

    vector<ll> dist(n + 1, INF);
    priority_queue<pp, vector<pp>, greater<pp>> pq; // min heap

    for (int i = 0; i < k; i++)
    {
        cin >> l;
        dist[l] = 0;
        pq.push({0, l});
    }

    vector<pp> v[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    while (!pq.empty())
    {
        pp temp = pq.top();
        pq.pop();

        ll d = temp.first, u = temp.second;
        for (int i = 0; i < v[u].size(); i++)
        {
            ll a = v[u][i].first, b = v[u][i].second;
            if(dist[a] > dist[u] + b)
            {
                dist[a] = MIN(dist[a], d + b);
                pq.push({dist[a], a});
            }
        }
    }

    for (int i = 1; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}