#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<vector<int>> sort_ranges(vector<vector<int>> ranges) {
    if (ranges.size() <= 1)return ranges;
    vector<int> pivot = ranges[0];
    vector<vector<int>> left, right;
    for (int i = 1; i < ranges.size(); i++) {
        vector<int> currentRange = ranges[i];
        if (pivot[1] < currentRange[1]) {
            left.push_back(currentRange);
        } else {
            right.push_back(currentRange);
        }
    }
    left = sort_ranges(left);
    left.push_back(pivot);
    right = sort_ranges(right);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

int get_range_size(vector<vector<int> > ranges) {
    ranges = sort_ranges(ranges);
    int rangeSize = ranges[0][1] - ranges[0][0];
    for (int i = 1; i < ranges.size(); i++) {
        vector<int> currentRange = ranges[i];
        vector<int> oldRange = ranges[i - 1];
        if (currentRange[1] < oldRange[0]) {
            rangeSize += currentRange[1] - currentRange[0];
        } else {
            if(currentRange[0]<oldRange[0])rangeSize += oldRange[0] - currentRange[0];
            else{
                ranges[i][0]=oldRange[0];
                ranges[i][1]=oldRange[1];
            }
        }
    }
    return rangeSize;
}

int main() {
    vector<vector<int>> ranges = {{1,  4},
                                  {7, 10},
                                  {3,  5},};
    cout << get_range_size(ranges);
    return 0;
}
