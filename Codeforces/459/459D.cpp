//In The Name of Allah
//Mon 10/7/96
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

const ll mod = 1e9+7,M = 1e6+5;

void Solution();

int n;
ll ans;
int data[M];
int cnt[M];
int mp[M];
int cnforw[M];
int cnbrw[M];
int comb[2*M][2];
int temp[2*M][2];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void imerge(int mbeg,int mend){
	int mid = (mbeg+mend)/2;
	int pr1 = mbeg;
	int pr2 = mid;
	int prm = 0;
	ll bc = 0;
	for(int i = mbeg;i<mid;i++)
		if(comb[i][1] == 0)
			bc++;
	while(pr1 < mid && pr2 < mend){
		if(comb[pr1][0] > comb[pr2][0]){
			if(comb[pr2][1] == 1)
				ans += bc;
			temp[prm++][0] = comb[pr2++][0];
			temp[prm-1][1] = comb[pr2-1][1];
		}else{
			if(comb[pr1][1] == 0)
				bc--;
			temp[prm++][0] = comb[pr1++][0];
			temp[prm-1][1] = comb[pr1-1][1];
		}
	}
	while(pr1 < mid){
		temp[prm++][0] = comb[pr1++][0];
		temp[prm-1][1] = comb[pr1-1][1];
	}
	while(pr2 < mend){
		temp[prm++][0] = comb[pr2++][0];
		temp[prm-1][1] = comb[pr2-1][1];
	}
	while(prm > 0){
		comb[mbeg + (--prm)][0] = temp[prm][0];
		comb[mbeg + prm][1] = temp[prm][1];
	}
}

void imergesort(int mbeg,int mend){
	if(mend - mbeg < 2)
		return;
	int mid = (mbeg+mend)/2;
	imergesort(mbeg,mid);
	imergesort(mid,mend);
	imerge(mbeg,mend);
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i];
		mp[i] = data[i];
	}
	sort(mp,mp+n);
	int size = unique(mp,mp+n)-mp;
	forar(i,n){
		data[i] = lower_bound(mp,mp+size,data[i]) - mp;
	}
	forar(i,n)
		cnforw[i] = ++cnt[data[i]];
	fill(cnt,cnt+M,0);
	forar(i,n)
		cnbrw[n-i-1] = ++cnt[data[n-i-1]];
	forar(i,n){
		comb[2*i+1][0] = cnforw[i];
		comb[2*i][0] = cnbrw[i];
		comb[2*i+1][1] = 0;
		comb[2*i][1] = 1;
	}
	imergesort(0,2*n);
	cout << ans << endl;
}
