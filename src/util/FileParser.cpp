#include "FileParser.h"

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > fileToGrid(const string &filepath) {
    ifstream file(filepath);
    if (!file.is_open()) {
        cerr << "Could not open file " << filepath << endl;
    };
    vector<vector<int> > grid;
    string line;
    while (getline(file, line)) {
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        for (int i = 0; i < line.size(); i++) {
            if (i >= grid.size()) {
                grid.resize(i + 1);
            };
            grid[i].push_back(line[i] - '0');
        }
    }
    return grid;
}
