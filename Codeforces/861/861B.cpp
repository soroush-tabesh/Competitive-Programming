//In The Name of Allah
//Sun 26/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e2+5;

void Solution();

int n,m; // 1-indexed
int r2f[110]; // 1-indexed
int ans;
const int N = 105;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >> b;
		r2f[a] = b;
	}
	for(int k = 1;k<=N;k++){
		bool contra = false;
		for(int r = 1;r<=N;r++){
			if(r2f[r] && r2f[r] != (((r-1)/k) + 1)){
				contra = true;
				break;
			}
		}
		if(!contra){
			if(!ans){
				ans = ((n-1)/k)+1;
			}else if(ans != ((n-1)/k)+1){
				ans = -1;
				break;
			}
		}
	}
	cout << ans << endl;
	
}
