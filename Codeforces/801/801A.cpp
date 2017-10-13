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
	string str;
	cin >> str;
	bool is = 1;
	int cnt = 0;;
	forar(i,str.length()){
		if(str[i] == 'V' && str[i+1] == 'K'){
			cnt++;
		}else if (str[i] == 'V' && str[i+1] == 'V' && i < str.length() - 1 && is){
			if(str[i+2] != 'V' && i < str.length() - 2){
				continue;
			}
			cnt++;
			is = false;
			str[i+1] = 'K';
		}else if (str[i] == 'K' && str[i-1] == 'K' && i > 0 && is){
			if(str[i-2] != 'K' && i > 1){
				continue;
			}
			cnt++;
			is = false;
			str[i-1] = 'V';
		}
	}
	cout << cnt;
}