#include "GameMap.h"

#include <iostream>
#include <vector>


using namespace std;

int main() {
    GameMap gameMap;
    gameMap.loadMapFromFile("map.json");
    cout << "Test" << endl;

    vector<vector<GridCell>> map = gameMap.getMap();

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            cout << "GridCell at (" << i << ", " << j << ")" << endl;
        }
    }
}