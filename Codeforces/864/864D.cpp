//In The Name of Allah
//Mon 3/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+5;

void Solution();

int n,ans;
int data[M];
int cnt[M];
bool obl[M];
set<int> zers;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i];
		data[i]--;
		cnt[data[i]]++;
	}
	forar(i,n){
		if(cnt[i] == 0){
			zers.insert(i);
		}
	}
	forar(i,n){
		if(cnt[data[i]] > 1){
			if(*(zers.begin()) > data[i] && !obl[data[i]]){
				obl[data[i]] = 1;
				continue;
			}
			cnt[data[i]]--;
			data[i] = *(zers.begin());
			zers.erase(zers.begin());
			cnt[data[i]]++;
			ans++;
		}
	}
	cout << ans << endl;
	forar(i,n){
		cout << data[i]+1 << " ";
	}
}
