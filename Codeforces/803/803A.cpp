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

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

void Solution();

bool mat[1001][1001];

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
	int n,k;
	cin >> n >> k;
	fori(i,1,n+1){
		fori(j,i,n+1){
			if(k != 0){
				if(i==j){
					mat[i][j] = 1;
					k--;
				}else if(k > 1){
					mat[i][j] = 1;
					mat[j][i] = 1;
					k -= 2;
				}
			}
		}
	}
	if(k > 0){
		cout << -1;
		return;
	}
	fori(i,1,n+1){
		fori(j,1,n+1){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}