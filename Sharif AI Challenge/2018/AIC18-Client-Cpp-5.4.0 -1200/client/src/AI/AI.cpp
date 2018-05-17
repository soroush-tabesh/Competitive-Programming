#include "AI.h"

#include <cstdlib>
#include <bits/stdc++.h>

#define rand() m_ddst(m_eng)

using namespace std;

const int MN=100;
int tow_sight[MN][MN];
int g[MN][MN];

int num[MN][MN];
bool mark[MN][MN];
bool burst;
int burst_cnt;
int light_unit_count,heavy_unit_count,archer_tower_cnt,cannon_tower_cnt;
int mxhealth,mxstorm;
uniform_int_distribution<> m_ddst;mt19937 m_eng;
World* wold;
bool in(int x,int y){
    return x>=0 && x<int(wold->get_defence_map().get_width()) && y>=0 && y<int(wold->get_defence_map().get_height());
}
bool cmp(int a,int b){
    int sum1=0,sum2=0;
    for(auto cell:wold->get_attack_map_paths()[a]->get_road()){
        sum1+=tow_sight[cell->get_location().get_x()][cell->get_location().get_y()];
    }
    for(auto cell:wold->get_attack_map_paths()[b]->get_road()){
        sum2+=tow_sight[cell->get_location().get_x()][cell->get_location().get_y()];
    }
    return sum1<sum2;
}
bool cmp3(int a,int b){
    int sum1=0,sum2=0;
    for(auto cell:wold->get_defence_map_paths()[a]->get_road()){
        sum1+=tow_sight[cell->get_location().get_x()][cell->get_location().get_y()];
    }
    for(auto cell:wold->get_defence_map_paths()[b]->get_road()){
        sum2+=tow_sight[cell->get_location().get_x()][cell->get_location().get_y()];
    }
    return sum1<sum2;
}
bool cmp2(pair<int,int> a,pair<int,int> b){
    return g[a.first][a.second]>g[b.first][b.second];
}
inline int getUnitPrice(int type) {
    return (type ? LightUnit().PRICE_INCREASE * (light_unit_count/60) + LightUnit().INITIAL_PRICE :
            HeavyUnit().PRICE_INCREASE * (heavy_unit_count/15) + HeavyUnit().INITIAL_PRICE);
}
inline int getTowerPrice(int type) {
    return (type ?  ArcherTower().INITIAL_PRICE +archer_tower_cnt*ArcherTower().INITIAL_PRICE_INCREASE
                 :CannonTower().INITIAL_PRICE+cannon_tower_cnt*CannonTower().INITIAL_PRICE_INCREASE);
}

inline int getTowerUpPrice(Tower *t) {
    return lround(pow(t->get_type() ? ArcherTower().PRICE_COEFF : CannonTower().PRICE_COEFF, t->get_level())) *
           (t->get_type() ? ArcherTower().INITIAL_LEVEL_UP_PRICE : CannonTower().INITIAL_LEVEL_UP_PRICE);
}
void simple_attack(int gold) {
    vector<Tower *> vis_tower = wold->get_visible_enemy_towers();
    int bean_cnt = wold->get_my_information().get_beans_left();
    for (int i = 0; i < wold->get_attack_map().get_width(); i++) {
        for (int j = 0; j < wold->get_attack_map().get_height(); j++) {
            tow_sight[i][j] = 1;
        }
    }
    for (auto tow:vis_tower) {
        int x = tow->get_location().get_x(), y = tow->get_location().get_y();
        if (bean_cnt) {
            bean_cnt--;
            wold->plant_bean(x, y);
        } else {
            for (int i = -2; i <= 2; i++) {
                for (int j = -2; j <= 2; j++) {
                    if (abs(i) + abs(j) <= 2 && in(x + i, y + j) && !burst) {
                        tow_sight[x + i][y + j]+=5;
                    }
                }
            }
        }
    }
    vector<int> paths;
    int po = 0;
    for (auto path :wold->get_attack_map_paths()) {
        paths.push_back(po++);
    }
    sort(paths.begin(), paths.end(), cmp);
    int hevnum = min(1+(wold->get_current_turn() - 50 / 150), gold / getUnitPrice(0));
    if (wold->get_current_turn() % 210 == 0 || burst) {
        hevnum = gold / getUnitPrice(0);
    }
    for (int i = 0; i < hevnum; i++) {
        if (gold >= getUnitPrice(0)) {
            gold -= getUnitPrice(0);
            wold->create_heavy_unit(paths[0]);
            heavy_unit_count++;
        }
    }
    for (int i = 0; i < int(wold->get_attack_map_paths().size()); i++) {
        for (int j = 0; j < 3 + (wold->get_current_turn()) / 30; j++) {
            if (gold >= getUnitPrice(1)) {
                gold -= getUnitPrice(1);
                wold->create_light_unit(paths[i]);
                light_unit_count++;
            }
        }
    }
    int max_path=min(5,(int)paths.size());
    po=0;
    while (gold >= getUnitPrice(1)) {
        gold -= getUnitPrice(1);
        wold->create_light_unit(paths[po]);
        light_unit_count++;
        po++;
        po%=max_path;
    }
}
void complex_attack(int gold){
    simple_attack(gold);
}
inline RoadCell* penultimate(vector<RoadCell*>& v){
    return v[max(0,(int)v.size()-1)];
}
int residue=0;
void simple_defence(int gold){
    int gold2=(gold*(wold->get_current_turn()/200))/10;
    gold-=gold2;
    memset(mark,0,sizeof mark);
    //if(wold->get_current_turn()%10==0  || wold->get_current_turn()==1){
    for (int i = 0; i < wold->get_defence_map().get_width(); i++) {
        for (int j = 0; j < wold->get_defence_map().get_height(); j++) {
            tow_sight[i][j] = 0;
        }
    }
    for (auto tow:wold->get_my_towers()) {
        int x = tow->get_location().get_x(), y = tow->get_location().get_y();
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                if (abs(i) + abs(j) <= 2 && in(x + i, y + j)) {
                    tow_sight[x + i][y + j] +=2;
                }
            }
        }
    }
    if(wold->get_current_turn()>500){
        for(auto un:wold->get_enemy_units()){
            int x=un->get_location().get_x(),y=un->get_location().get_y();
            if(un->get_type()) {
                tow_sight[x][y]--;
            }
            else{
                tow_sight[x][y]-=5;
            }
        }
    }
    //<editor-fold desc="Description">
    /*for(auto path:wold->get_defence_map_paths()){
        int sum=0;
        for(auto cell:path->get_road()){
            int x=cell->get_location().get_x(),y=cell->get_location().get_y();
            sum+=tow_sight[x][y];
        }
       while(sum<(6+wold->get_current_turn()/30)){
            int mx=0,x1=-1,y1=-1;
            for(auto cell:path->get_road()){
                int x=cell->get_location().get_x(),y=cell->get_location().get_y();
                for (int i = -2; i <= 2; i++) {
                    for (int j = -2; j <= 2; j++) {
                        if (abs(i) + abs(j) <= 2 && in(x + i, y + j)) {
                            if(!mark[x+i][y+i] && wold->is_tower_constructible(x+i,y+j) && g[x+i][y+j]>mx){
                                mx=g[x+i][y+j];
                                x1=x+i,y1=y+j;
                            }
                        }
                    }
                }
            }
            int typ=rand()%11;
            if(mx!=0 && gold>=getTowerPrice(typ!=0)) {
                if(typ!=0) {
                    wold->create_archer_tower(1, x1, y1);
                    gold -= getTowerPrice(1);
                    archer_tower_cnt++;
                }
                else{
                    wold->create_cannon_tower(1, x1, y1);
                    gold -= getTowerPrice(0);
                    cannon_tower_cnt++;
                }
                mark[x1][y1] = 1;
                for (int i = -2; i <= 2; i++) {
                    for (int j = -2; j <= 2; j++) {
                        if (abs(i) + abs(j) <= 2 && in(x1 + i, y1 + j)) {
                            tow_sight[x1 + i][y1 + j]++;
                        }
                    }
                }
            }
            else{
                break;
            }
            sum=0;
            for(auto cell:path->get_road()){
                int x=cell->get_location().get_x(),y=cell->get_location().get_y();
                sum+=tow_sight[x][y];
            }
        }
    }*/
    //</editor-fold>
    bool nomon=0;
    while(!nomon){
        vector<int> paths;
        int po = 0;
        for (auto path :wold->get_defence_map_paths()) {
            paths.push_back(po++);
        }
        sort(paths.begin(), paths.end(), cmp3);
        po=0;
        while(po<(int)paths.size()) {
            auto path = wold->get_defence_map_paths()[paths[po]];
            int mx = 0, x1 = -1, y1 = -1;
            for (auto cell:path->get_road()) {
                int x = cell->get_location().get_x(), y = cell->get_location().get_y();
                for (int i = -2; i <= 2; i++) {
                    for (int j = -2; j <= 2; j++) {
                        if (abs(i) + abs(j) <= 2 && in(x + i, y + j)) {
                            if (!mark[x + i][y + i] && wold->is_tower_constructible(x + i, y + j) &&
                                g[x + i][y + j] > mx) {
                                mx = g[x + i][y + j];
                                x1 = x + i, y1 = y + j;
                            }
                        }
                    }
                }
            }
            int typ = rand() % 7;
            if(gold<getTowerPrice(typ!=0)){
                nomon=1;
                break;
            }
            if(mx==0){
                po++;
                continue;
            }
            if (typ != 0) {
                wold->create_archer_tower(1, x1, y1);
                gold -= getTowerPrice(1);
                archer_tower_cnt++;
            } else {
                wold->create_cannon_tower(1, x1, y1);
                gold -= getTowerPrice(0);
                cannon_tower_cnt++;
            }
            mark[x1][y1] = 1;
            for (int i = -2; i <= 2; i++) {
                for (int j = -2; j <= 2; j++) {
                    if (abs(i) + abs(j) <= 2 && in(x1 + i, y1 + j)) {
                        tow_sight[x1 + i][y1 + j]++;
                    }
                }
            }
        }
    }
    /*}
    vector<pair<int,int> > v;
    for(int i=0; wold->get_defence_map().get_width() > i; i++) {
        for (int j = 0; j < wold->get_defence_map().get_height(); j++) {
            if(!mark[i][j] && wold->is_tower_constructible(i,j) && g[i][j]>0) {
                v.push_back({i, j});
            }
        }
    }
    sort(v.begin(),v.end(),cmp2);
    memset(num,0, sizeof num);
    for(auto p:v) {
        int x = rand() % 4;
        if (x != 0 && gold>=getTowerPrice(1)) {
            wold->create_archer_tower(1, p.first, p.second);
            gold -= getTowerPrice(1);
            archer_tower_cnt++;
        }
        else if(x==0 && gold>=getTowerPrice(0)){
            wold->create_cannon_tower(1, p.first, p.second);
            cannon_tower_cnt++;
            gold-=getTowerPrice(0);
        }
    }*/
    if(wold->get_current_turn()>200) {
        gold += gold2;
        vector<int> tows;
        int po = 0;
        for (auto tow:wold->get_my_towers()) {
            tows.push_back(po++);
        }
        random_shuffle(tows.begin(), tows.end());
        for (auto i:tows) {
            auto tow = wold->get_my_towers()[i];
            if (gold >= getTowerUpPrice(tow)) {
                gold -= getTowerUpPrice(tow);
                wold->upgrade_tower(tow);
            }
        }
    }
    for(auto un:wold->get_enemy_units()){
        int x=un->get_location().get_x(),y=un->get_location().get_y();
        if(un->get_type()) {
            num[x][y]++;
        }
        else{
            num[x][y]+=5;
        }
    }
    memset(mark,0,sizeof mark);
    int storm=wold->get_my_information().get_storms_left();
    for(auto path:wold->get_defence_map_paths()){
        int x=penultimate(path->get_road())->get_location().get_x(),y=penultimate(path->get_road())->get_location().get_y();
        int x1=path->get_road().back()->get_location().get_x(), y1=path->get_road().back()->get_location().get_y();
        if(mxstorm && !mark[x1][y1] && storm && num[x1][y1]>=5*((mxstorm-storm)/((mxstorm+2)/3))+1+wold->get_current_turn()/300){
            wold->create_storm(x,y);
            storm--;
            for(int i=-2;i<=2;i++){
                for(int j=-2;j<=2;j++){
                    if(abs(i)+abs(j)<=2 && in(x+i,x+j)){
                        mark[x][y]=1;
                    }
                }
            }
        }
    }
    residue=max(0,gold-(wold->get_current_turn()/200)*((gold+2)/3));
}
void complex_defence(int gold){
    simple_defence(gold);
}
int burst_num=500;
void AI::simple_turn(World* world) {
    if(world->get_current_turn() == 1){
        m_eng = mt19937(time(NULL));
    }
    wold = world;
    if (world->get_current_turn() == 1) {
        mxstorm=world->get_my_information().get_storms_left();
        mxhealth=world->get_my_information().get_strength();
        srand(time(0));
        for (auto path:world->get_defence_map_paths()) {
            for (auto cell:path->get_road()) {
                int x = cell->get_location().get_x(), y = cell->get_location().get_y();
                for (int i = -2; i <= 2; i++) {
                    for (int j = -2; j <= 2; j++) {
                        if ((abs(i) + abs(j)) <= 2 && in(x + i, y + j)) {
                            g[x + i][y + j]+=10;
                        }
                    }
                }
            }
        }
        for(auto path:world->get_defence_map_paths()){
            burst_num=max(burst_num,850-HeavyUnit().MOVE_SPEED*(int)path->get_road().size());
        }
    }
    if(wold->get_current_turn()==burst_num) {
        burst = true;
    }
    int money = world->get_my_information().get_money();
    if (!burst) {
        int money1 = residue+(money-residue) * (5 - (world->get_current_turn() +(world->get_current_turn()>burst_num)*(100))/ 400) / 10;
        simple_defence(money1);
        simple_attack(money - money1);
    }
    else if(wold->get_current_turn()<burst_num+100){
        simple_defence(0);
        simple_attack(((world->get_current_turn()%10)==0)*200);
    }
    else{
        simple_defence(0);
        simple_attack(money/(8-burst_cnt));
        burst_cnt++;
    }
    if(burst_cnt==8){
        burst=0;
    }
}
void AI::complex_turn(World* world) {
    simple_turn(world);
}
