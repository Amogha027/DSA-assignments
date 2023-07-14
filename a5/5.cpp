#include <bits/stdc++.h>
using namespace std;

#define MOD(x, y) ((((x) - (y)) > 0) ? ((x) - (y)) : ((y) - (x)))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)
#define endl '\n'
typedef long long ll;
typedef pair<ll, pair<ll, ll>> pp;

int n;
vector<int> parent(100005), size(100005);

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (size[a] < size[b])
        {
            int temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

bool cmpfunc1(pp a, pp b)
{
    pair<ll, ll> x = a.second, y = b.second;
    return (x.first < y.first);
}

bool cmpfunc2(pp a, pp b)
{
    pair<ll, ll> x = a.second, y = b.second;
    return (x.second < y.second);
}

int main()
{
    ll x, y;
    cin >> n;

    vector<pp> v;
    vector<vector<ll>> edge;
    for (int i = 0; i < n; i++)
    {
        make_set(i);
        cin >> x >> y;
        v.push_back({i, {x, y}});
    }

    sort(v.begin(), v.end(), cmpfunc1);
    f_(i, 0, n - 1)
    {
        ll ii = v[i].first, jj = v[i + 1].first;
        pair<ll, ll> a = v[i].second, b = v[i + 1].second;
        x = MOD(a.first, b.first);
        y = MOD(a.second, b.second);
        ll w = MIN(x, y);
        edge.push_back({w, ii, jj});
    }

    sort(v.begin(), v.end(), cmpfunc2);
    f_(i, 0, n - 1)
    {
        ll ii = v[i].first, jj = v[i + 1].first;
        pair<ll, ll> a = v[i].second, b = v[i + 1].second;
        x = MOD(a.first, b.first);
        y = MOD(a.second, b.second);
        ll w = MIN(x, y);
        edge.push_back({w, ii, jj});
    }
    sort(edge.begin(), edge.end());

    ll ans = 0, num = 0;
    for (auto x : edge)
    {
        if (find_set(x[1]) != find_set(x[2]))
        {
            union_sets(x[1], x[2]);
            ans += x[0];
            num++;
        }

        if (num == n - 1)
            break;
    }

    cout << ans << endl;
    return 0;
}
