//In The Name of Allah
//Tue 28/9/96
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

int n;
int data1[M],data2[M];

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	bool is = true;
	forar(i,n+1){
		cin >> data1[i];
		data2[i] = data1[i];
		if(i && data1[i] > 1 && data1[i-1]>1)
			is = false;
	}
	if(is){
		cout << "perfect" << endl;
		return;
	}
	cout << "ambiguous" << endl;
	cout << 0 << " ";
	int par = 0,cnt = 1;
	fori(i,1,n+1){
		int k = cnt;
		while(data1[i]--){
			cout << par+1 << " ";
			cnt++;
		}
		par = k;
	}
	cout << endl;
	cout << 0 << " ";
	vector<int> lst;
	lst.pb(0);
	int ptr= 0,en=0;
	cnt = 1;
	fori(i,1,n+1){
		while(data2[i]--){
			cout << lst[ptr]+1 << " ";
			lst.pb(cnt++);
			ptr++;
			if(ptr > en)
				ptr = en;
		}
		ptr = en+1;
		en = cnt-1;
	}
	cout << endl;
}
