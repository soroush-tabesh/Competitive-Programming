//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: spin
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("spin.in","r",stdin),freopen("spin.out","w",stdout)
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

bool wheel[5][360];
int speed[5];
int place[5];
bool temp[360];
int ans;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	forar(i,5){
		cin >> speed[i];
		int a;
		cin >> a;
		forar(j,a){
			int s,d;
			cin >> s >> d;
			forar(k,d+1){
				wheel[i][(s+k)%360] = 1;
			}
		}
	}
	ans = -1;
	forar(sec,400){
		forar(i,360)
			temp[i] = 1;
		forar(i,5){
			forar(j,360){
				temp[j] &= wheel[i][(j-place[i]+360)%360];
			}
			place[i] += speed[i];
			place[i] %= 360;
		}
		forar(i,360){
			if(temp[i]){
				ans = sec;
				break;
			}
		}
		if(ans != -1)
			break;
	}
	
	if(ans == -1){
		cout << "none" << endl;
	}else{
		cout << ans << endl;		
	}
	
}
