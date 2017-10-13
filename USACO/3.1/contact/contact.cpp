//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: contact
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("contact.in","r",stdin),freopen("contact.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
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
const int M = 100*1000+5;

void Solution();

int a,b,n,cnt;
bool data[200*1000+5];
pii dp[10000]; // cnt,id

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

int getnum(int i , int d){
	int k = 1;
	while(d>0){
		k*=2;
		if(data[i]){
			k++;
		}
		d--;
		i++;
	}
	return k;
}

bool comp(pii l,pii r){
	return l.F > r.F || (l.F == r.F && l.S < r.S);
}

void byteout(int x){
	bool is = false;
	forar(i,15){
		if(is){
			cout << ((x & (1<<(14-i))) ? 1 : 0);
		}
		if(x & (1<<(14-i))){
			is = true;
		}
	}
}

void Solution(){
	cin >> a >> b >> n;
	string line;
	getline(cin,line);
	while(getline(cin,line)){
		forar(i,line.size()){
			if(line[i] == '1'){
				data[cnt] = 1;
			}
			cnt++;
		}
	}
	forar(i,cnt){
		fori(j,a,b+1){
			if(i+j-1 >= cnt)
				continue;
			int v = getnum(i,j);
			dp[v].F++;
			dp[v].S = v;
		}
	}
	sort(dp,dp+10*1000,comp);
	int last = -1;
	int inl = 0;
	int i = -1;
	n++;
	while(n){
		i++;
		if(dp[i].F == 0)
			break;
		if(last == dp[i].F){
			if(inl == 6){
				cout << endl;
				byteout(dp[i].S);
				inl = 1;
			}else{
				cout << " ";
				byteout(dp[i].S);
				inl++;
			}
		}else{
			n--;
			if(n==0)
				continue;
			if(i)
				cout << endl;
			cout << dp[i].F << endl;
			byteout(dp[i].S);
			last = dp[i].F;
			inl = 1;
		}
	}
	cout << endl;
	
}
