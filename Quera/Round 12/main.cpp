#include <bits/stdc++.h>

using namespace std;
void quest1();
void quest2();
void quest3();
void quest4();

int main()
{
    //quest1();
    //quest2();
    //quest3();
    //quest4();
    return 0;
}

void quest1()
{
    int a[2];
    int b[2];
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    if(a[0] >= b[0] && a[1] >= b[1])
        cout << "yes";
    else
        cout << "no";
}

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int dashcount(string s)
{
    int c = 0;
    for(int i = 0; i < s.size();i++)
        if(s.at(i) == '-')
            c++;
    return c;
}

int hasbook(string s){
    vector <string> words = split(s,'-');
    for(vector<string>::iterator it = words.begin();it != words.end();it++){
        if(*it == "the" || *it == "of" || *it == "and")
            return true;
    }
    return false;
}

void quest2()
{
    int c;
    int temp = 0;
    cin >> c;
    for(int i = 0;i < c ;i++){
        string a,b;
        cin >> a >> b;
        transform(a.begin(),a.end(),a.begin(),::tolower);
        transform(b.begin(),b.end(),b.begin(),::tolower);
        bool ais = false,bis = false;
        ais = dashcount(a) >= 3 || hasbook(a);
        bis = dashcount(b) >= 3 || hasbook(b);
        if(ais == bis)
            temp ++;
    }
    cout << temp;
}

void quest3()
{
    double z;
    cin >> z;
    double z2 = (log(z)/log(2));
    if(z == pow(2,floor(z2)) || z == pow(2,ceil(z2)))
        cout << "Yes";
    else
        cout << "No";
}

int minday(vector<int> nums){
    int minim = nums.size();
    while(nums.size() != 0){
        vector<int> day;
        day.push_back(nums[0]);
        nums.erase(nums.begin());
        for(int i = 0;i < nums.size();i++){
            if(day.back() == nums[i])
                continue;
            if(day.back()+1 < nums[i])
                break;
            day.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            i--;
        }
        minim = minim < day.size() ? minim : day.size();
    }
    return minim;
}

void quest4()
{
    int c;
    cin >> c;
    vector<int> nums;
    for(int i = 0;i < c;i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(),nums.end());

    //arrange days
    int minim = c;
    while(nums.size() != 0){
        vector<int> day;
        day.push_back(nums[0]);
        nums.erase(nums.begin());
        for(int i = 0;i < nums.size();i++){
            if(day.back() == nums[i])
                continue;
            if(day.back()+1 < nums[i])
                break;
                /*
            vector<int> t1 (nums.begin() + i,nums.end());
            int a = fmin( minday(t1),day.size());
            t1.erase(t1.begin());
            int b = fmin( minday(t1),day.size()+1);

            if(b>a){*/
                day.push_back(nums[i]);
                nums.erase(nums.begin()+i);
                i--;
            /*} else {
                break;
            }*/
        }
        minim = minim < day.size() ? minim : day.size();
    }
    cout << minim;
}
