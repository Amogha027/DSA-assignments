#include <bits/stdc++.h>
using namespace std;

#define MOD(x, y) ((((x) - (y)) > 0) ? ((x) - (y)) : ((y) - (x)))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define f_(i, j, k) for (int i = j; i < k; i++)
#define f__(i, j, k) for (int i = j; i >= k; i--)
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pp;

int n, l;
vector<int> a, b;

int main()
{
    cin >> n;

    f_(i, 0, n)
    {
        cin >> l;
        a.push_back(l);
        b.push_back(0);
    }

    vector<pp> arr;
    f_(i, 0, n - 1)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }

    f__(i, n - 1, 1)
    {
        int k = arr[i - 1].second, pos = arr[i - 1].first;
        if (k == 0)
        {
            a[pos] += b[i];
            b[pos] = MAX((a[i] + b[pos]), (b[pos] + b[i]));
        }
        else if (k == 1)
        {
            int temp = MAX((a[pos] + b[i]), (a[i] + b[pos]));
            a[pos] = MAX(temp, (a[pos] + a[i]));
            b[pos] += b[i];
        }
        else
        {
            a[pos] = MAX((a[pos] + b[i]), (a[i] + b[pos]));
            b[pos] += b[i];
        }
    }

    cout << MAX(a[0], b[0]) << endl;
    return 0;
}