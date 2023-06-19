#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool sortcol(const vector<int> &v1, const vector<int> &v2)
    {
        return v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> non_overlaped;
        vector<int> interval;
        sort(intervals.begin(), intervals.end(), sortcol);

        int start = intervals[0][0], end = intervals[0][1];
        for (size_t i = 0; i < intervals.size() - 1; ++i)
        {
            if (end >= intervals[i + 1][0] && end <= intervals[i + 1][1])
            {
                end = intervals[i + 1][1];
                if (intervals[i + 1][0] < start)
                {
                    start = intervals[i + 1][0];
                }
            }
            else if (end >= intervals[i + 1][0] && end >= intervals[i + 1][1])
            {
                if(intervals[i][0]>intervals[i+1][1]){
                    interval.push_back(start);
                    interval.push_back(end);
                    non_overlaped.push_back(interval);
                    interval.clear();
                    start = intervals[i + 1][0];
                    end = intervals[i + 1][1];
                }
                else if (intervals[i][0] > intervals[i + 1][0]){
                    start = intervals[i+1][0];
                }
            }
            else
            {
                interval.push_back(start);
                interval.push_back(end);
                non_overlaped.push_back(interval);
                interval.clear();
                start = intervals[i + 1][0];
                end = intervals[i + 1][1];
            }
        }
        interval.push_back(start);
        interval.push_back(end);
        non_overlaped.push_back(interval);
        return non_overlaped;
    }
};

int main()
{
    vector<vector<int>> input = {
        {1, 4},
        {0, 0},{0,2}};
    
    // cin >> input;
    Solution sol;
    vector<vector<int>> matrix = sol.merge(input);
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        cout << matrix[i][0] << " " << matrix[i][matrix[i].size() - 1] << endl;
    }
    return 0;
}