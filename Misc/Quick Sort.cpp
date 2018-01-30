//In The Name of Allah
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

void Solution();

ll n;
ll data[100*1000];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void dbg(){
	forar(i,n){
		cout << data[i] << " ";
	}
	cout << endl;
}

ll m_partition(ll mbegin, ll mend){
	ll i = mbegin+1;
	ll j = mend-1;
	bool is = false;
	while(i<j){
		is = true;
		while(data[i]<data[mbegin] && i < mend)
			i++;
		while(data[j]>data[mbegin] && j > mbegin)
			j--;
		if(i<j){
			swap(data[i],data[j]);
			i++;
			j--;
		}
	}
	if(is)
		i--;
	if(mend - mbegin > 1)
		swap(data[i],data[mbegin]);
	return i;
}

void quickSort(ll mbegin,ll mend){
	if(mend - mbegin <= 1)
		return;
	ll anch = m_partition(mbegin,mend);
	quickSort(mbegin,anch);
	quickSort(anch+1,mend);
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i];
	}
	quickSort(0,n);
	dbg();
}

