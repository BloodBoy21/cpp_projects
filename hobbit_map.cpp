//
// Created by death on 05/10/2021.
//
#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;
typedef vector<vector<int>> landMap;

int get_distance(int x, int y, int x2, int y2) {
    return sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
}

int *explore(int col, int row, landMap land) {
    int *coordinates = new int[2];
    int maxCol = land[0].size(), maxRow = land.size();
    bool down = false, right = false;
    if (col >= maxCol || row >= maxRow)return coordinates;
    int currentShoe = land[col][row];
    if (currentShoe == land[col + 1][row] && col < maxCol - 1) {
        right = true;
        coordinates[0]++;
    };
    if (currentShoe == land[col][row + 1] && row < maxRow - 1) {
        down = true;
        coordinates[1]++;
    };
    if ((right && down) || (!right && !down)) {
        auto compareWay = [&](int col2, int row2) {
            int nextShoe = land[col2][row2];
            int shoeRight = land[col2+1][row2];
            int shoeDown = land[col2][row2+1];
            if((shoeRight==nextShoe||shoeRight==currentShoe)||(shoeDown==nextShoe||shoeDown==currentShoe))return true;
            return false;
        };
        if(compareWay(col+1,row))coordinates[0]++;
        else coordinates[1]++;
    }
    return coordinates;
}

int map_of_land(landMap land) {
    map<int, int> shoes = {{1, 0},
                           {2, 0},
                           {3, 0}};
    int rowN = land[0].size() - 1;
    int colN = land.size() - 1;
    int rowE = 0, colE = 0;
    cout << rowN << " " << colN << endl;
    while (!(rowE == rowN && colE == colN)) {
        int *coordinates = explore(colE, rowE, land);
        colE += coordinates[0];
        rowE += coordinates[1];
        int shoe = land[colE][rowE];
        shoes[shoe]++;
        cout << "(" << colE << "," << rowE << ")=" << shoe << endl;
    }
    for (auto &shoe: shoes) {
        cout << shoe.first << ":" << shoe.second << endl;
    }
    return 0;
}

int main() {
    vector<vector<int>> x = {{2, 2, 3, 3},
                             {2, 3, 3, 3},
                             {1, 2, 2, 3},
                             {1, 1, 2, 3},
    };
    map_of_land(x);
    return 0;
}