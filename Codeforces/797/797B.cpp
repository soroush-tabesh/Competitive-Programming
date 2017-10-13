#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

void Solution();

int n;
set<int> pos;
set<int> neg;
int sum;
int mp = 1e4+1,mn=-1-1e4;
bool ismp = false,ismn = false;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	for(int i = 0;i < n;i++){
		int a;
		cin >> a;
		if(a > 0){
			pos.insert(a);
			sum += a;
			if(abs(a)%2 == 1)
				mp = (int)min(mp,a);
		}else if(a < 0){
			neg.insert(a);
			if(abs(a)%2 == 1)
				mn = (int)max(mn,a);
		}
	}
	if(sum % 2 == 0){
		//Log(mn);
		//Log(mp);
		if(mn+mp > 0)
			sum += mn;
		else{
			sum -= mp;
		}
	}
	cout << sum;
}