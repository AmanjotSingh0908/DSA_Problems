#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> largest_undefended_area(int t, vector<tuple<int, int, int, vector<pair<int, int>>>>& test_cases){
    vector<int> results;

    for(auto& test_case : test_cases){
        int w, h ,n;
        vector<pair<int, int>> towers;
        tie(w,h,n, towers) = test_case;

        if (n==0) {
            results.push_back(w * h);
            continue;
        }

        vector<int> x_coords = {0, w + 1};
        vector<int> y_coords = {0, h + 1};

        for(auto& tower : towers){
            x_coords.push_back(tower.first);
            y_coords.push_back(tower.second);
        }

        //sort
        sort(x_coords.begin(), x_coords.end());
        sort(y_coords.begin(), y_coords.end());

        int max_x_gap = 0, max_y_gap = 0;
        int max_x_gap = 0, max_y_gap = 0;
        for (size_t i = 1; i < x_coords.size(); ++i) {
            max_x_gap = max(max_x_gap, x_coords[i] - x_coords[i - 1] - 1);
        }
        for (size_t i = 1; i < y_coords.size(); ++i) {
            max_y_gap = max(max_y_gap, y_coords[i] - y_coords[i - 1] - 1);
        }

        //penalty = (largest rectangle area)
        results.push_back(max_x_gap * max_y_gap);
    }

    return results;
}

//sample input - test_case = {15, 8, 3, {{3, 8}, {11, 2}, {8, 6}}};
