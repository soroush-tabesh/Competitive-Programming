#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

void question1A();
void question4A();
void question71A();
void question158A();
void question50A();
void question231A();
void question158B();
void question160A();
void question122A();
void question337A();

int main()
{
    question337A();
    return 0;
}

void question1A(){
    int n,m,a;
    ll ans;
    cin >> n >> m >> a;

    ans = (n / a) + ((n%a == 0) ? 0 : 1);
    ans *= (m / a) + ((m%a == 0) ? 0 : 1);

    cout << ans;
}

void question4A(){
    int w;
    cin >> w;
    if(w > 2 && w % 2 == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
}

void question71A(){
    int c;
    cin >> c;
    vector<string> lines;
    for (int i = 0; i < c; i++){
        string s;
        cin >> s;
        lines.push_back(s);
    }

    for (int i = 0; i < c; i++){
        string s = lines[i];
        if(s.length() > 10){
            cout << s.at(0) << s.length() - 2 << s.at(s.length() - 1);
        }else{
            cout << s;
        }
        cout << endl;
    }
}

void question158A(){
    int n,k;
    int c = 0;
    cin >> n >> k;
    vector<int> nums;

    for(int i = 0;i < n; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    int kth = nums[k-1];

    for(int i = 0;i < n; i++){
        if(nums[i] >= kth &&  nums[i] > 0)
            c++;
    }
    cout << c;
}

void question50A(){
    int a,b;
    cin >> a >> b;
    cout << a*b/2;
}

void question231A(){
    int cnt;
    cin >> cnt;
    int ans = 0;
    for (int i = 0; i < cnt; i++){
        int is = 0;
        for(int j = 1;j <= 3;j++){
            int temp;
            cin >> temp;
            is += temp;
        }
        if(is > 1)
            ans ++;
    }
    cout << ans;
}

void question158B(){
    int n;
    cin >> n;
    int groups[4] = {0,0,0,0};
    int taxi = 0;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        groups[temp-1]++;
    }
    taxi = groups[3];//#4

    taxi += groups[1]/2;//#2
    groups[1] %= 2;

    taxi += groups[2];//#3,1
    groups[0] = groups[0] - groups[2];
    if(groups[0] < 0)
        groups[0] = 0;

    if(groups[1] == 1){
        taxi++;
        groups[1] = 0;
        groups[0] -= 2;
        if(groups[0] < 0)
            groups[0] = 0;
    }
    taxi += (groups[0]+3)/4;

    cout << taxi;

}

void question160A(){
    int c,sum=0;
    cin >> c;
    vector<int> coins;
    for(int i = 0;i < c;i++){
        int temp;
        cin >> temp;
        coins.push_back(temp);
        sum += temp;
    }
    sort(coins.begin(),coins.end());
    reverse(coins.begin(),coins.end());
    int subsum = 0;
    sum /= 2;
    for(int i = 0; i < c ;i++){
        subsum += coins[i];
        if(subsum > sum){
            cout << i + 1 << endl;
            break;
        }
    }
}

bool isLucky(int a){
    do{
        if((a%10) != 4 && (a%10) != 7)
            return false;
        a /= 10;
    }while(a != 0);
    return true;
}

void question122A(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        if(n%i == 0){
            if(isLucky(i)){
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
}

void question337A(){
    int n,m;
    cin >> n >> m;
    vector<int> puzz;
    for (int i = 0;i < m;i++){
        int temp;
        cin >> temp;
        puzz.push_back(temp);
    }
    sort(puzz.begin(),puzz.end());
    reverse(puzz.begin(),puzz.end());
    int minIndex = 0;
    int minVal = abs(puzz[0] - puzz[n-1]);
    for(int i = 1;i <= m-n;i++){
        int diff = abs(puzz[i] - puzz[i+n-1]);
        if(diff < minVal){
            minVal = diff;
            minIndex = i;
        }
    }
    cout << minVal;
}






