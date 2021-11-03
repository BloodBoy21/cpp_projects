//
// Created by death on 05/10/2021.
//
#include <iostream>
#include <vector>
#include <map>
#include <math.h>

#define SET_COL true
#define SET_ROW false
using namespace std;
typedef vector<vector<int>> landMap;
struct coordinates {
    int col;
    int row;
};

int get_distance(int x, int y, int x2, int y2) {
    return sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
}

int *explore(coordinates currentPoint, landMap land) {
    int *nextPoint = new int[2];
    int startShoe = land[currentPoint.col][currentPoint.row];
    int counter = 0;
    auto nextShoe = [&](coordinates nShoe, bool position) {
        if (position) {
            return land[nShoe.col + 1][nShoe.row];
        }
        return land[nShoe.col][nShoe.row + 1];
    };
    auto nodes = [&](coordinates lastNode, coordinates currentNode) {
        int lastShoe = land[lastNode.col][lastNode.row], currentShoe = land[currentNode.col][currentNode.row];
        if (lastShoe == currentShoe) {
            return lastNode;
        }
        return nullptr_t;
    };
    if (currentShoe == nextShoe(currentPoint, SET_COL)) {
        nextPoint[0]++;
        counter++;
    } else if (currentShoe == nextShoe(currentPoint, SET_ROW)) {
        nextPoint[1]++;
        counter++;
    } else if (counter == 0 || counter == 2) {
        while
    }

    return nextPoint;
}

int map_of_land(landMap land) {
    map<int, int> shoes = {{1, 0},
                           {2, 0},
                           {3, 0}};
    int rowN = land[0].size() - 1;
    int colN = land.size() - 1;
    int rowE = 0, colE = 0;
    cout << rowN << "x" << colN << endl;
    while (!(rowE == rowN && colE == colN)) {
        int *coordinates = explore({}, land);
        colE += coordinates[0];
        rowE += coordinates[1];
        int shoe = land[colE][rowE];
        shoes[shoe]++;
        cout << "(" << colE << "," << rowE << ")=" << shoe << endl;
    }
    cout << "---------------------------------\n"
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
    //map_of_land(x);
    return 0;
}