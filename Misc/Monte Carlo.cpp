#include <bits/stdc++.h>
#include <random>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

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

inline void Log(string s){
	cout << "Log: " << s << endl;
}

inline void Log(int s){
	cout << "Log: " << s << endl;
}

void Solution(){
	ll t;
	double sum = 0;
	cin >> t;
	mt19937 engine(time(NULL));
	uniform_real_distribution<> dist;
	for(int i = 0 ;i < t;i++){
		double rnd1;
		do{
			rnd1 = ceil(dist(engine) * (double)99);
		}while(rnd1 == 0);
		double rnd2;
		do{
			rnd2 = ceil(dist(engine) * (double)99);
		}while(rnd2 == 0 || rnd1 == rnd2);
		vector<double> data;
		/*data.pb(min(rnd1,rnd2));
		data.pb(abs(rnd2-rnd1));
		data.pb(100 - max(rnd1,rnd2));
		sort(data.begin(),data.end());
		sum += data[1];*/
		sum += max(rnd1,100-rnd1);
	}
	sum /= t;
	cout << sum << endl;
}

