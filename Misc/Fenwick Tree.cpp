//In The Name of Allah
//Tue 25/7/96
#include <bits/stdc++.h>

#define LSB(x) (x&(-x))
using namespace std;
typedef long long int ll;

const ll M = 1e6;
ll fen[M];

void add(ll x, ll val)
{
    for (ll i = x; i < M; i += LSB(i)) fen[i] += val;
}

ll get(ll x)
{
    ll res = 0;
    for (ll i = x; i > 0; i -= LSB(i)) res += fen[i];
    return res;
}

int main()
{
	add(1,1);
	cout << get(1); // returns 1
	return 0;
}
