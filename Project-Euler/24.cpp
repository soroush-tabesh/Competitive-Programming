//In The Name of Allah
//Thu 27/2/97
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int32_t main()
{
	Init;
	Solution();
	return 0;
}

ll fac(int i){
	if(i == 0)
		return 1;
	return i * fac(i-1);
}

bool m_next_permutation(int* b,int* e){
	int* t = e-1;
	while(t != b && *t < *(t-1))
		--t;
	reverse(t,e);
	if(t == b)
		return false;
	int* tail = t-1;
	while(*tail >= *t)
		++t;
	swap(*tail,*t);
	return true;
}

inline void Solution(){
	int lst[10] = {0,1,2,3,4,5,6,7,8,9};
	forar(i,1e6 - 1){
		m_next_permutation(lst,lst+10);
	}
	forar(i,10)
		cout << lst[i];
}
