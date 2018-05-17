// In the Name of Allah
#include "AI.h"
#include <bits/stdc++.h>

#define Log(x) cout << "Log: " << x << endl;cout.flush();
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

World* world;
vector<vector<map<int,int> > > dptow;// for each cell tells which paths it covers
vector<long double> coveringTowers; // for each path we keep how many cells are being covered
vector<vector<bool> > isinbuildqueue;
vector<vector<bool> > isfilled;
vector<bool> hasBeg;
const int m_range = 2;
int mincover = 2;
int curunit = 0;
int unitperiod = 8;
int light_unit_count,heavy_unit_count;
int archer_tower_count,cannon_tower_count;
int dooml = 600,doomr= 1000;
int burst_cntr,burst_period = 6;
bool isburst;
int shp = -1;
int cannonProb = 8;
int consState = 0;// 0 : begin , 1 : intersections and fill lanes
ld defence_budget,attack_budget,cost_def,cost_att;
ld budget_coef = 0.62; // defence_budget/total_budget
ld ccap = 6;
ld lstmon = 0;
ld income;
bool snd = false;
bool ittbres = true;
mt19937 eng;
uniform_int_distribution<> randomMaker;

pii ways[8] = {{1,  0},
               {-1, 0},
               {0,  1},
               {0,  -1},
               {1,  1},
               {1,  -1},
               {-1, 1},
               {-1, -1}};

bool isInMap(int x,int y){
    return (x>=0 && y >= 0 && x < world->get_defence_map().get_width() && y < world->get_defence_map().get_height());
}

void init() {
    eng = mt19937((unsigned int)(time(NULL)));
    dptow = vector<vector<map<int,int> > > (world->get_defence_map().get_width(), vector<map<int,int> >(world->get_defence_map().get_height()));
    coveringTowers = vector<long double> (world->get_defence_map_paths().size());
    isfilled = vector<vector<bool> >(world->get_defence_map().get_width(),vector<bool>(world->get_attack_map().get_height()));
    isinbuildqueue = vector<vector<bool> >(world->get_defence_map().get_width(),vector<bool>(world->get_attack_map().get_height()));
    hasBeg = vector<bool>(world->get_defence_map_paths().size());
    for (int i = 0;i < world->get_defence_map_paths().size();i++) {
        auto path = world->get_defence_map_paths()[i];
        for (auto cell : path->get_road()) {
            for (int x = -m_range; x <= m_range; ++x) {
                for (int y = -m_range; y <= m_range; ++y) {
                    if (abs(x) + abs(y) > m_range || !isInMap(cell->get_location().get_x() + x,
                                                              cell->get_location().get_y() + y)) {
                        continue;
                    }
                    if (world->is_tower_constructible(cell->get_location().get_x() + x,
                                                      cell->get_location().get_y() + y)) {
                        dptow[cell->get_location().get_x() + x][cell->get_location().get_y() + y][i]++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < world->get_defence_map().get_width(); ++i) {
        for (int j = 0; j < world->get_attack_map().get_height(); ++j) {
            isfilled[i][j] = !(world->is_tower_constructible(i,j));
        }
    }
    /*
    for (auto path : world->get_defence_map_paths()) {
        auto cell = path->get_road().front();
        for (int i = 0; i < 8; ++i) {
            if (cell->get_location().get_x() + ways[i].first >= world->get_defence_map().get_width() ||
                cell->get_location().get_x() + ways[i].first < 0
                || cell->get_location().get_y() + ways[i].second >= world->get_defence_map().get_height() ||
                cell->get_location().get_y() + ways[i].second < 0) {
                continue;
            }
            if (world->is_tower_constructible(cell->get_location().get_x() + ways[i].first,
                                              cell->get_location().get_y() + ways[i].second)) {
                conslist.emplace_back(0, mp(cell->get_location().get_x() + ways[i].first,
                                            cell->get_location().get_y() + ways[i].second));
                break;
            }
        }
    }
    for (auto path : world->get_defence_map_paths()) {
        auto cell = path->get_road().back();
        for (int i = 0; i < 8; ++i) {
            if (cell->get_location().get_x() + ways[i].first >= world->get_defence_map().get_width() ||
                cell->get_location().get_x() + ways[i].first < 0
                || cell->get_location().get_y() + ways[i].second >= world->get_defence_map().get_height() ||
                cell->get_location().get_y() + ways[i].second < 0) {
                continue;
            }
            if (world->is_tower_constructible(cell->get_location().get_x() + ways[i].first,
                                              cell->get_location().get_y() + ways[i].second)) {
                conslist.emplace_back(0, mp(cell->get_location().get_x() + ways[i].first,
                                            cell->get_location().get_y() + ways[i].second));
                break;
            }
        }
    }
    reverse(conslist.begin(), conslist.end());
     */
}

pair<int,pii> getConstruct(){
    if(consState == 0){
        int path = distance(hasBeg.begin(),min_element(hasBeg.begin(),hasBeg.end()));
        if(hasBeg[path] == 1){
            consState = 1;
            return getConstruct();
        }
        hasBeg[path] = 1;
        pii cand = {-1,-1};
        int selcell = -1;
        while (cand == mp(-1,-1) && ++selcell < world->get_defence_map_paths()[path]->get_road().size()) {
            auto cel2 = world->get_defence_map_paths()[path]->get_road()[selcell];
            for (int w = 0; w < 8; ++w) {
                if (!isInMap(cel2->get_location().get_x() + ways[w].first,
                             cel2->get_location().get_y() + ways[w].second))
                    continue;
                if (!isfilled[cel2->get_location().get_x() + ways[w].first][cel2->get_location().get_y() +
                                                                            ways[w].second]
                    && !isinbuildqueue[cel2->get_location().get_x() + ways[w].first][cel2->get_location().get_y() +
                                                                                     ways[w].second]
                    && world->is_tower_constructible(cel2->get_location().get_x() + ways[w].first,
                                                     cel2->get_location().get_y() + ways[w].second)) {
                    cand.first = cel2->get_location().get_x() + ways[w].first;
                    cand.second = cel2->get_location().get_y() + ways[w].second;
                    break;
                }
            }
        }
        if(cand == mp(-1,-1)){
            return mp(-1,mp(-1,-1));
        }else{
            return mp(ARCHER,cand);
        }
    }else {
        int path = min_element(coveringTowers.begin(),coveringTowers.end())-coveringTowers.begin();
        pii cand = {0,0};
        bool is = false;
        for (int i = 0; i < world->get_attack_map().get_width(); ++i) {
            for (int j = 0; j < world->get_attack_map().get_height(); ++j) {
                if(dptow[i][j][path] == 0 || !world->is_tower_constructible(i,j))
                    continue;
                if(!is || dptow[i][j].size() > dptow[cand.first][cand.second].size()){
                    cand.first = i;
                    cand.second = j;
                    is = true;
                }else if(dptow[i][j].size() == dptow[cand.first][cand.second].size()){
                    int a1 = 0;
                    for(auto x : dptow[i][j]){
                        a1 += x.second;
                    }
                    int a2 = 0;
                    for(auto x : dptow[cand.first][cand.second]){
                        a2 += x.second;
                    }
                    if(a1 > a2){
                        cand.first = i;
                        cand.second = j;
                    }
                }
            }
        }
        return mp(randomMaker(eng)%cannonProb != 0,cand);
    }
}

Tower* getUpgrade(){
    int path = min_element(coveringTowers.begin(),coveringTowers.end())-coveringTowers.begin();
    vector<Tower*> cands;
    for (auto x : world->get_my_towers()) {
        if(dptow[x->get_location().get_x()][x->get_location().get_y()][path] != 0)
            cands.pb(x);
    }
    if(cands.size() == 0){
        if(!world->get_my_towers().empty()){
            return world->get_my_towers()[randomMaker(eng) % world->get_my_towers().size()];
        }else{
            return NULL;
        }
    }
    return cands[randomMaker(eng)%cands.size()];
}

bool isThereToBuild(){
    if(!ittbres)
        return false;
    for (int i = 0; i < world->get_defence_map().get_width(); ++i) {
        for (int j = 0; j < world->get_defence_map().get_height(); ++j) {
            if(world->is_tower_constructible(i,j) && !isfilled[i][j] && !isinbuildqueue[i][j]){
                int num = 0;
                for(auto x : dptow[i][j]){
                    num += x.second;
                }
                if(num >= 3)
                    return true;
            }
        }
    }
    return ittbres = false;
}

void revalidateCovering(){
    vector<vector<double> > cov(world->get_defence_map().get_width(),vector<double>(world->get_defence_map().get_height()));
    for(auto x : world->get_my_towers()) {
        for (int i = -2; i <= 2; ++i) {
            for (int j = -2; j < 2; ++j) {
                if (isInMap(x->get_location().get_x()+i,x->get_location().get_y()+j) && abs(i) + abs(j) <= 2){
                    cov[x->get_location().get_x()+i][x->get_location().get_y()+j] += pow(1.4,x->get_level()-1);
                }
            }
        }
    }
    for(int i = 0;i < world->get_defence_map_paths().size();i++){
        ld res = 0;
        auto pth = world->get_defence_map_paths()[i];
        for(auto cell : pth->get_road()){
            res += cov[cell->get_location().get_x()][cell->get_location().get_y()];
        }
        coveringTowers[i] = res;
        cout << res << " ";
    }
    cout << endl;
}

void stormRoutine(){
    for (auto path : world->get_defence_map_paths()) {
        auto cell = *prev(path->get_road().end());
        int damage = 0;
        for (auto u : cell->get_units()) {
            damage += u->get_damage();
        }
        cell = *prev(prev(path->get_road().end()));
        for (auto u : cell->get_units()) {
            damage += u->get_damage();
        }
        cell = *prev(prev(prev(path->get_road().end())));
        for (auto u : cell->get_units()) {
            damage += u->get_damage();
        }
        cell = *prev(prev(path->get_road().end()));
        int storm_thres = 8-world->get_my_information().get_storms_left()*2 +world->get_current_turn()/200;
        if (damage >= storm_thres)
            world->create_storm(cell->get_location().get_x(), cell->get_location().get_y());
    }
}

int getTowerPrice(int type) {
    return (type == ARCHER ? ArcherTower().INITIAL_PRICE + 5*archer_tower_count : CannonTower().INITIAL_PRICE + 5*cannon_tower_count);
}

int getTowerUpgradePrice(Tower *t) {
    return lround(pow(t->get_type() ? ArcherTower().PRICE_COEFF : CannonTower().PRICE_COEFF, t->get_level()-1)) *
           (t->get_type() ? ArcherTower().INITIAL_LEVEL_UP_PRICE : CannonTower().INITIAL_LEVEL_UP_PRICE);
}

bool placeTower(int type,int x,int y){
    if(defence_budget >= getTowerPrice(type) && world->is_tower_constructible(x,y)){
        isinbuildqueue[x][y] = 1;
        isfilled[x][y] = 1;
        defence_budget -= getTowerPrice(type);
        cost_def += getTowerPrice(type);
        if(type)
            world->create_archer_tower(1,x,y),archer_tower_count++;
        else
            world->create_cannon_tower(1,x,y),cannon_tower_count++;
        isfilled[x][y] = 1;
        return true;
    }else{
        return false;
    }
}

bool upgradeTower(Tower* t){
    if(defence_budget >= getTowerUpgradePrice(t)){
        defence_budget -= getTowerUpgradePrice(t);
        cost_def += getTowerUpgradePrice(t);
        world->upgrade_tower(t);
        return true;
    }else{
        return false;
    }
}

int getUnitPrice(int type) {
    return (type == LIGHT ? LightUnit().PRICE_INCREASE * (light_unit_count/LightUnit().LEVEL_UP_THRESHOLD) + LightUnit().INITIAL_PRICE :
            HeavyUnit().PRICE_INCREASE * (heavy_unit_count/HeavyUnit().LEVEL_UP_THRESHOLD) + HeavyUnit().INITIAL_PRICE);
}

bool spawnUnit(int type,int path){
    if(attack_budget >= getUnitPrice(type)){
        attack_budget -= getUnitPrice(type);
        cost_att += getUnitPrice(type);
        if(type == LIGHT){
            world->create_light_unit(path);
            light_unit_count++;
        }
        else{
            world->create_heavy_unit(path);
            heavy_unit_count++;
        }
        return true;
    }else{
        return false;
    }
}

int getShortestPath(){
    if(shp != -1)
        return shp;
    int res = 0;
    int reslen = 10000*1000;
    for (int i = 0; i < world->get_attack_map_paths().size(); ++i) {
        if(world->get_attack_map_paths()[i]->get_road().size() < reslen){
            res = i;
            reslen = world->get_attack_map_paths()[i]->get_road().size();
        }
    }
    return shp = res;
}

void towerCreatedEvent(int x,int y){
    for(auto cell : dptow[x][y]){
        coveringTowers[cell.first] += cell.second;
    }
}

void towerUpgradedEvent(Tower* t){
    ld val = pow(1.4,t->get_level()) - pow(1.4,t->get_level()-1);
    for(auto cell : dptow[t->get_location().get_x()][t->get_location().get_y()]){
        coveringTowers[cell.first] += cell.second*val;
    }
}

void beanRoutine(){
    int cnt = 0;
    while (world->get_my_information().get_beans_left() && cnt < world->get_visible_enemy_towers().size()) {
        world->plant_bean(world->get_visible_enemy_towers()[cnt]->get_location().get_x(),
                          world->get_visible_enemy_towers()[cnt]->get_location().get_y());
        cnt++;
    }
}

void updateBudget() {
    ld bc = budget_coef;
    income = world->get_my_information().get_money() - lstmon + cost_att + cost_def;
    cout << "Money : " << world->get_my_information().get_money() << " ; Last Money : " << lstmon << " ; Income : " << income << " ; Cost : " << cost_def + cost_att << endl;
    cost_def = cost_att = 0;
    lstmon = world->get_my_information().get_money();
    defence_budget += (income * budget_coef);
    attack_budget += income * (1 - budget_coef);
    if(world->get_current_turn() % 200 == 1){
        defence_budget = (world->get_my_information().get_money() * budget_coef);
        attack_budget = (world->get_my_information().get_money() * (1 - budget_coef));
    }
    cout << "Def : " << defence_budget << " ; Att : " << attack_budget << endl;
    budget_coef = bc;
    if(world->get_current_turn() > dooml){
        attack_budget = world->get_my_information().get_money();
    }
}

void defence() {
    if (world->get_current_turn() == 1) {
        init();
    }
    revalidateCovering();
    if (isThereToBuild()) {
        while (defence_budget >= getTowerPrice(CANNON) && ittbres) {
            auto tw = getConstruct();
            ittbres = placeTower(tw.first, tw.second.first, tw.second.second);
            towerCreatedEvent(tw.second.first, tw.second.second);
        }
    } else {
        while (defence_budget >= 100) {
            auto tw = getUpgrade();
            if (tw != NULL) {
                if (defence_budget < getTowerUpgradePrice(tw)) {
                    break;
                }
                upgradeTower(tw);
                towerUpgradedEvent(tw);
            }else{
                break;
            }
        }
    }
    stormRoutine();
}

void attack() {
    beanRoutine();
    if (world->get_current_turn() < dooml) {
        int pc = randomMaker(eng) % world->get_attack_map_paths().size();
        ld cap = ccap;
        if (attack_budget >= cap * getUnitPrice(1) / 2) {
            while (attack_budget >= getUnitPrice(1) && cap > 0) {
                spawnUnit(LIGHT,pc);
                cap--;
            }
        }
    } else {
        if(isburst){
            auto k = getShortestPath();
            int bdg = attack_budget / (burst_period - burst_cntr);
            for(int i = 0;i < bdg/getUnitPrice(HEAVY);i++){
                spawnUnit(HEAVY,k);
            }
            burst_cntr++;
            if(burst_cntr == burst_period){
                burst_cntr = 0;
                isburst = 0;
            }
        }else{
            if(attack_budget >= 80 * world->get_my_information().get_income()){
                isburst = 1;
            }
        }
//        budget_coef = 0.35;
//        if (snd) {
//            snd = false;
//            auto k = getShortestPath();
//            for (int i = 0; i < 10; ++i) {
//                spawnUnit(HEAVY,k);
//            }
//        } else if (attack_budget >= getUnitPrice(0) * 20) {
//            auto k = getShortestPath();
//            for (int i = 0; i < 10; ++i) {
//                spawnUnit(HEAVY,k);
//            }
//            snd = true;
//        }
    }
}

void AI::simple_turn(World *w) {
    world = w;
    cout << "Turn = " << world->get_current_turn() << " Started." << endl;
    updateBudget();
    defence();
    attack();
    cout << "Turn = " << world->get_current_turn() << " Ended." << endl;
}

void AI::complex_turn(World *w) {
    world = w;
    budget_coef -= 0.0015;
    budget_coef = max(budget_coef, (ld) 0.4);
    unitperiod = 8 - world->get_current_turn()/200;
    curunit %= unitperiod;
    simple_turn(w);
    ccap = max((ld)attack_budget / (5*getUnitPrice(1)),(ld)5)+1;
    cout << "ccap : " << ccap << endl;
}
