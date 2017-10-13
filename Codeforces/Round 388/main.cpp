#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;
const int test_cases = 4;

using namespace std;

void A();
void B();
void C();
void D();

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
    WFile;
	//ForI(i,0,test_cases)
	#endif

	//A();
	//B();
	//C();
	D();

    return 0;
}

void A(){
	ll n;
	cin >> n;
	cout << (n/2) << endl;
	ForI(i,0,n/2-1)
		cout << 2 << ' ' ;
	if(n % 2 == 0)
		cout << 2;
	else
		cout << 3;
}

void B(){
	pair<int,int> p[4];
	ForI(i,0,3)
		cin >> p[i].first >> p[i].second;
	vector<pair<int,int> > ans;
	ll s;

	//1
	p[3].first = p[0].first + p[1].first - p[2].first;
	p[3].second = p[0].second + p[1].second - p[2].second;
	ans.push_back(make_pair(p[3].first,p[3].second));

	//2
	p[3].first = p[0].first + p[2].first - p[1].first;
	p[3].second = p[0].second + p[2].second - p[1].second;
	ans.push_back(make_pair(p[3].first,p[3].second));

	//3
	p[3].first = p[1].first + p[2].first - p[0].first;
	p[3].second = p[1].second + p[2].second - p[0].second;
		ans.push_back(make_pair(p[3].first,p[3].second));

	cout << ans.size() << endl;
	ForI(i,0,ans.size())
		cout << ans[i].first << ' ' << ans[i].second << endl;
}

void C(){
	ll n=0,rep=0,dem=0;
	cin >> n;
	string data = "";
	cin >> data;
	ForI(i,0,n){
		if(data[i]=='R')
			rep++;
		else
			dem++;
	}

	// R = +
	// D = -

	ll pos = 0,sum = 0;

	while(rep > 0 && dem > 0){
		char cur = data[pos];

		if(sum > 0){
			if(cur == 'R'){
				sum++;
			}else if(cur == 'D'){
				data[pos] = 'X';
				dem--;
				sum--;
			}
		} else if(sum < 0) {
			if(cur == 'R'){
				data[pos] = 'X';
				rep--;
				sum++;
			}else if(cur == 'D'){
				sum--;
			}
		} else {
			if(cur == 'R'){
				sum++;
			}else if(cur == 'D'){
				sum--;
			}
		}

		pos++;
		pos %= n;

	}

	if(rep > 0)
		cout << "R";
	else if(dem > 0)
		cout << "D";

}

void D(){
	ll c_bidders = 0;
	cin >> c_bidders;

	// Map of bidders => Key:person Data:bids
	// Vector of bids => pair.first:amount pair.second:time
	//map<ll, vector<pair<ll,ll> > > bidders;
	
	// All bids : person ,amount
	vector <pair<ll,ll> > bids;
	
	//maximums : person ,amount
	//map<ll,ll> p_max;

	ForI(i,0,c_bidders){
		ll person,amount;
		cin >> person >> amount;
		//bidders[person].push_back(make_pair(amount,i));
		bids.push_back(make_pair(person,amount));
		//p_max[person] = p_max[person] > amount ? p_max[person] : amount;
	}

	// Questions
	ll queries;
	cin >> queries;
	ForI(i,0,queries){
		
		// Listing absents
		ll c_absents;
		map<ll,int> absents;
		cin >> c_absents;
		ForI(j,0,c_absents){
			ll temp;
			cin >> temp;
			absents[temp] = 1;
		}
		
		// Determine the next winner
		ll winner = 0;
		ll index = 0;
		ForD(j,bids.size()-1,-1){
			if(absents.find(bids[j].first) != absents.end()){
				continue;
			}else{
				winner = bids[j].first;
				index = j;
				break;
			}
		}
		
		// Do we really have a winner ???
		if(winner != 0){
			
			// Looking for bids in a row
			ll j = index;
			j--;
			while(absents.find(bids[j].first) != absents.end()){
				if(bids[j-1].first == winner){
					index = j - 1;
					j--;
				}
				j--;
				if(j<=0) break;
			}
			
			cout << winner << " " << bids[index].second << endl;
			
		} else {
			cout << "0 0" << endl;
			continue;
		}

	}

}

