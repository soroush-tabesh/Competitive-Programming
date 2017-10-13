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

char city[1000][1000];
int m,n;
int tari,tarj,si,sj;

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
	cin >> n >> m;
	forar(i,n){
		forar(j,m){
			cin >> city[i][j];
			if(city[i][j] == 'S'){
				si = i;
				sj = j;
			}
			if(city[i][j] == 'T'){
				tari = i;
				tarj = j;
			}
		}
	}
	bool is = false;
	//check horizontal
	for(int j = 0;j < m;j++){
		bool isi = true;
		if(j <= sj){
			for(int j2 = j;j2 <= sj;j2++){
				if(city[si][j2] == '*')
					isi = false;
			}			
		}else{
			for(int j2 = j;j2 >= sj;j2--){
				if(city[si][j2] == '*')
					isi = false;
			}
		}
		
		if(si <= tari){
			for(int i = si;i <= tari;i++){
				if(city[i][j] == '*')
					isi = false;
			}
		}else{
			for(int i = si;i >= tari;i--){
				if(city[i][j] == '*')
					isi = false;
			}
		}
		
		if(j <= tarj){
			for(int j2 = j;j2 <= tarj;j2++){
				if(city[tari][j2] == '*')
					isi = false;
			}			
		}else{
			for(int j2 = j;j2 >= tarj;j2--){
				if(city[tari][j2] == '*')
					isi = false;
			}
		}
		is |= isi;
	}
	//check vertical
	for(int i = 0;i < n;i++){
		bool isi = true;
		if(i <= si){
			for(int i2 = i;i2 <= si;i2++){
				if(city[i2][sj] == '*')
					isi = false;
			}			
		}else{
			for(int i2 = i;i2 >= si;i2--){
				if(city[i2][sj] == '*')
					isi = false;
			}
		}
		
		if(sj <= tarj){
			for(int j = sj;j <= tarj;j++){
				if(city[i][j] == '*')
					isi = false;
			}
		}else{
			for(int j = sj;j >= tarj;j--){
				if(city[i][j] == '*')
					isi = false;
			}
		}
		
		if(i <= tari){
			for(int i2 = i;i2 <= tari;i2++){
				if(city[i2][tarj] == '*')
					isi = false;
			}			
		}else{
			for(int i2 = i;i2 >= tari;i2--){
				if(city[i2][tarj] == '*')
					isi = false;
			}
		}
		is |= isi;
	}
	cout << (is ? "YES" : "NO");
	
}