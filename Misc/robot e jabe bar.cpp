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

struct Bot {
	int x;
	int y;
	int hand;
	bool ishand;
};
typedef struct Bot Bot;

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
	cin >> t;
	ll sum = 0;
	mt19937 engine(time(NULL));
	uniform_real_distribution<> dist;
	// test cases
	for(int i = 0 ;i < t;i++){
		Bot bot;
		bot.x = 0;
		bot.y = 0;
		bot.hand = 0;
		bot.ishand = false;
		
		bool is = false;
		pair<int,int> box0 = make_pair(0,1);
		pair<int,int> box1 = make_pair(1,1);
		// robot move
		for(ll m = 1;m <= 100;m++){
			//random moving
			double rnd = dist(engine);
			int r = rnd < 0.5 ? 0 : 1;
			if(bot.x == 0 && bot.y == 0){
				bot.x += r;
				bot.y += 1-r;
			}else if(bot.x == 1 && bot.y == 0){
				bot.x -= r;
				bot.y += 1-r;
			}else if(bot.x == 0 && bot.y == 1){
				bot.x += r;
				bot.y -= 1-r;
			}else {
				bot.x -= r;
				bot.y -= 1-r;
			}
			
			//box moving
			if(bot.ishand){
				if(bot.x == bot.hand && bot.y == 0){
					bot.ishand = false;
					if(bot.hand == 0){
						box0.scnd = 0;
					}else{
						box1.scnd = 0;
					}
				}
			}else{
				if(bot.y == 1){
					if(bot.x == box0.frs && bot.y == box0.scnd){
						bot.ishand = true;
						bot.hand = 0;
					}else if(bot.x == box1.frs && bot.y == box1.scnd){
						bot.ishand = true;
						bot.hand = 1;
					}
					
				}
			}
			// end condition
			if(box0.scnd == 0 && box1.scnd == 0){
				is = true;
				sum += m;
				break;
			}
		}
		//move end
		if(!is)
			sum += 100;
		
	}
	double avg =((double)sum) / ((double)t);
	cout << avg << endl;
	
}

