#include <bits/stdc++.h>

#define INTERVAL 10000
using namespace std;

int main()
{
    long long interval, i;
    long double rand_x, rand_y, origin_dist, pi;
    long double circle_points = 0, square_points = 0;
	mt19937 engine(time(NULL));
	uniform_real_distribution<> dist;
    for (i = 0; i < (INTERVAL * INTERVAL); i++) {
        rand_x = dist(engine);
        rand_y = dist(engine);
        origin_dist = rand_x * rand_x + rand_y * rand_y;
        if (origin_dist <= 1)
            circle_points++;
    }
    square_points = (INTERVAL * INTERVAL * 1.0);
    pi = 4 * circle_points / square_points;
    cout << pi;
    return 0;
}
