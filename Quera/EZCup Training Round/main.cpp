#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;
const int test_cases = 20;

using namespace std;

void A();
void B();
void C();
void D();
void E();

int main()
{
	Init;
	//WFile;
	//ForI(i,0,test_cases)

	//A();
	B();
	//C();
	//D();
	//E();

    return 0;
}

void A(){
	ll code,n;
	cin >> code >> n;
	ForI(i,0,n){
		string org;
		cin >> org;
		ll emp;
		cin >> emp;
		ForI(j,0,emp){
			ll codemp;
			cin >> codemp;
			if(code == codemp && codemp != 1){
				cout << org << ' ';
			}
		}
	}
}

bool comp(set<ll> a,set<ll> b){
	return a.size() < b.size();
}

void B(){
	ll n;
	vector<ll> data[3];
	cin >> n;
	ForI(i,0,n){
		char tempc;
		ll temp;
		cin >> tempc >> temp;
		switch(tempc){
			case 'F':
				data[0].push_back(temp);
				break;
			case 'T':
				data[1].push_back(temp);
				break;
			case 'A':
				data[2].push_back(temp);
				break;
		}
	}
	if(data[0].size() == 0 || data[1].size() == 0 || data[2].size() == 0){
		cout << "NO" << endl;
		return;
	}

	for(ll ita = 0;ita < data[0].size();ita++){
		vector<ll>::iterator lb1,ub1,lb2,ub2;
		
		lb1 = data[1].begin();//lower_bound(data[1].begin(),data[1].end(),data[0][ita]+data[2][0]);
		/*if(lb1 < data[1].begin())
			lb1 = data[1].begin();
		if(lb1 >= data[1].end())
			lb1 = --data[1].end();*/
		
		ub1 = ++lower_bound(data[1].begin(),data[1].end(),data[0][ita]+data[2][data[2].size()-1]);
		if(ub1 < data[1].begin())
			ub1 = data[1].begin();
		if(ub1 >= data[1].end())
			ub1 = --data[1].end();
		
		lb2 = data[2].begin();//lower_bound(data[2].begin(),data[2].end(),data[0][ita]+data[1][0]);
		/*if(lb2 < data[2].begin())
			lb2 = data[2].begin();
		if(lb2 >= data[2].end())
			lb2 = --data[2].end();*/
		
		ub2 = ++lower_bound(data[2].begin(),data[2].end(),data[0][ita]+data[1][data[1].size()-1]);
		if(ub2 < data[2].begin())
			ub2 = data[2].begin();
		if(ub2 >= data[2].end())
			ub2 = --data[2].end();
		
		//cout << data[0][ita] << " : " << *lb1 << " , " << *ub1 << " , " << *lb2 << " , " << *ub2 << endl;
		for(vector<ll>::iterator itb = lb1;itb <= ub1;itb++){
			for(vector<ll>::iterator itc = lb2;itc <= ub2;itc++){
				ll a = data[0][ita];
				ll b = *itb;
				ll c = *itc;
				//cout << a << " " << b << " " << c << endl;
				if((a + b > c) && (a + c > b) && (b + c > a)){
					cout << "YES" << endl;
					cout << "F " << a << endl;
					cout << "T " << b << endl;
					cout << "A " << c << endl;
					return;
				}

			}
		}
		
	}
	cout << "NO" << endl;

}

ll gcd(ll a,ll b){
	return b == 0 ? a : gcd(b, a % b);
}

void C(){
	ll n,max=0;
	cin >> n;
	set<ll> data;
	ll lcm = -1,mcnt = 0;

	ForI(i,0,n){
		ll temp;
		cin >> temp;
		if(temp > max){
			max = temp;
			mcnt = 0;
		}else if(temp == max){
			mcnt++;
		}
		data.insert(temp);
	}

	for(set<ll>::iterator it = data.begin();it != data.end();it++){
		if(lcm == -1){
			lcm = (*it);
		}
		if(*it != max || mcnt > 0)
			lcm = lcm * (*it) / gcd(lcm,(*it));
	}
	//cout << lcm << " " << max << endl;
	if(lcm == max)
			cout << "Soal";
		else
			cout << "Tohmat";



}

void E(){
	ll n,cnt=0;
	cin >> n;
	ForI(i,1,n+1){
		bool is = true;
		ll num = i;

		while(num / 10 > 0){
			ll en = (num%10) + ((num/10)%10);
			ll de = abs((num%10) - ((num/10)%10));
			if(de != 0){
				is = is && (en % de == 0);
			}else{
				is = false;
			}
			num /= 10;
		}
		if(is)
			cnt++;
	}
	cout << cnt%mod << endl;
}

