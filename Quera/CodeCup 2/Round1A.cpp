#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

void question1();
void question2();
void question3();
void question4();
void question5();
void question6();
void question7();

int main()
{
    question6();
    return 0;
}

void question1()
{
    int n;
    cin >> n;
    cout << "W";
    for(int i = 0; i < n; i++)
        cout << "o";
    cout << "w!";
}

void question2()
{
	int n,cnt = 0;
	int days[7] = {0};
	for(int i = 1;i <= 3;i++){
		cin >> n;
		for(int j = 0;j < n;j++){
			string temp;
			cin >> temp;
			char first = temp[0];
			switch(first){
				case 's':
					days[0]++;
					break;
				case '1':
					days[1]++;
					break;
				case '2':
					days[2]++;
					break;
				case '3':
					days[3]++;
					break;
				case '4':
					days[4]++;
					break;
				case '5':
					days[5]++;
					break;
				case 'j':
					days[6]++;
					break;
			}
		}
	}

	for(int i = 0;i < 7;i++)
		if(days[i] == 0)
			cnt ++;
	cout << cnt;

}

lli getnumsum(lli x){
	lli sum = 0;
	do{
		sum += x%10;
		x/=10;
	}while(x != 0);
	return sum;
}

void question3()
{
	lli n;
	cin >> n;
	do{
		n = getnumsum(n);
	}while(n/10 != 0);
	cout << n;
}

void question4()
{
    int n,x,y;
    cin >> n >> x >> y;
    bool is = false;
    for(int i = 0; i <= n/x; i++)
    {
        if((n - i*x)%y == 0)
        {
            is = true;
            printf("%d %d",i,(n - i*x)/y);
            break;
        }
    }
    if(!is)
        cout << -1;
}

lli getupper_sum(lli sum ,lli cur){
	return sum - cur - 1;
}

void question5()
{
    float n;
	lli cnt = 0;
    cin >> n;

	for(lli i = ceil(n/2)-1;i >= ceil(n/3);i--){
		lli rest = n - i;
		cnt += (rest/2) - getupper_sum(rest,i);
	}

    cout << cnt;
}

bool comp(int a, int b){
	return (a>b);
}

void question6()
{
	lli n, k, m, x, y, p;
	p = 1000000007;
	cin >> n >> k >> m >> x >> y;
	
	vector<int> data;
	data.push_back(m);
	make_heap(data.begin(),data.end());
	
	if(k <= n-k+1){
		int prev = m;
		for(int i = 1;i < n;i++){
			prev = (prev*x+y)%p;
			data.push_back(prev);
			push_heap(data.begin(),data.end());
			if(data.size() > k){
				pop_heap(data.begin(),data.end());
				data.pop_back();
			}	
		}
		cout << data.front();
	} else {
		k = n-k+1;
		int prev = m;
		for(int i = 1;i < n;i++){
			prev = (prev*x+y)%p;
			data.push_back(prev);
			push_heap(data.begin(),data.end(),comp);
			if(data.size() > k){
				pop_heap(data.begin(),data.end(),comp);
				data.pop_back();
			}	
		}
		cout << data.front();
	}
	
}

void get_next(pair<int,int>* interval){

}

void question7()
{
	int m,n,max=0;
	cin >> n >> m;
	int** table = new int*[n];
	for(int i = 0; i < n; i++){
		table[i] = new int[m];
		for(int j = 0;j < m;j++)
			cin >> table[i][j];
	}
	// search with column limit
	for(int c = 0;c < m;c++){
		if((m-c+1)*n < max)
			break;
		pair<int,int> interval;
		get_next(&interval);
	}

	cout << max;
}
