#include <fstream>
#include <iostream>
#include <string>
#include "common.hpp"
#include <cstdint>
#include <vector>
#include <climits>

using namespace std;
int solve(vector<pair<int,int>> ranges)
{
    for(auto range : ranges)
    {
        cout << range.first << '-' << range.second << '\n';
    }
    return 0;
}
int main()
{
    ifstream input("src/day2/input.txt");
    cout << "input.txt";
    if(input.is_open())
    {
        cout << "input.txt";
        string line;
        vector<pair<int,int>> ranges;
        while(getline(input, line))
        {
            cout << line;
            int curr_begin = 0;
            int curr_middle = 0;
            int curr_end = INT_MAX;
            int left = 0, right = 0;
            for(size_t i = 0; line.size(); i++)
            {
                if(curr_end != curr_end)
                {
                    curr_begin = i;
                    curr_end = INT_MAX;
                }
                if(line[i] == '-')
                {
                    curr_middle = i;
                }
                else if(line[i] == ',' || line[i] == '\n')
                {
                    curr_end = i-1;
                    pair<int,int> curr_range(curr_begin,curr_end);
                    ranges.push_back(curr_range);
                }
            }
        }
        solve(ranges);
    }

	return 0;
}
