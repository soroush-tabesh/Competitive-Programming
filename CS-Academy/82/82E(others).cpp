#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct union_find
{
    vector<int> p;

    union_find(int n) : p(n, -1) {}

    bool join(int u, int v)
    {
        if ((u = root(u)) == (v = root(v)))
            return false;
        if (p[u] > p[v])
            swap(u, v);
        p[u] += p[v];
        p[v] = u;
        return true;
    }

    int root(int u)
    {
        return p[u] < 0 ? u : p[u] = root(p[u]);
    }
};

struct edge
{
    int u, v; ll w;

    bool operator<(const edge &r) const
    {
        if (w != r.w) return w < r.w;
        return v < r.v;
        
    }
};

int main()
{
    //freopen("a.txt", "r", stdin);
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<edge> m, m2;
        for (int i = 0, x; i < n; ++i)
        {
            cin >> x;
            m.push_back({ i, n, x });
        }

        for (int i = 0, x; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                cin >> x;
                if (i < j)
                    m2.push_back({ i, j, x });
            }

        sort(m2.begin(), m2.end());
        union_find uf2(n+1);
        for (auto &i : m2)
            if (uf2.join(i.u, i.v))
                m.push_back(i);

        function<pair<ll, int>(ll)> calc = [&](ll md)
        {
            auto e = m;
            for (int i = 0; i < n; ++i)
                e[i].w += md;

            sort(e.begin(), e.end());

            union_find uf(n+1);
            ll ans = 0; int c = 0;
            for (auto &i : e)
            {
                if (uf.join(i.u, i.v))
                {
                    ans += i.w;
                    if (i.v == n) ++c;
                }
            }
            cout << "Log : " << c << endl;
            return make_pair(ans - k*md, c);
        };

        ll b = -1, e = 1e2;
        while (e-b > 1)
        {
            ll md = (b+e)/2;
            if (calc(md).second > k)
                b = md;
            else
                e = md;
        }

        cout << calc(e).first << endl;
    }

    return 0;
}
