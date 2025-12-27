#include "bits/stdc++.h"
#include <iostream>

using namespace std;

void solve(const vector<pair<long long,long long>> &ranges, const vector<long long> ids)
{
    int i = 0;
    set<long long> fresh_ids;
    for(auto id : ids)
    {
        for(auto r : ranges)
        {
            long long first = r.first;
            long long last = r.second;
            if(id >= first && id <= last)
            {
                fresh_ids.emplace(id);
            }
        }
    }
    cout << "Number of fresh ids in list: " << fresh_ids.size() << endl;
}

void solve2(vector<pair<long long,long long>> ranges)
{
    long long number_of_fresh_ids = 0;
    vector<pair<long long, long long>> merged_ranges;
    sort(ranges.begin(),ranges.end());
    merged_ranges.push_back({ranges[0].first, ranges[0].second});
    for(size_t i = 1; i < ranges.size(); i++)
    {
        long long first = ranges[i].first;
        long long last = ranges[i].second;
        if(merged_ranges.back().second >= first)
        {
            merged_ranges.back().second = max(merged_ranges.back().second,last);
        }
        else
        {
            merged_ranges.push_back({first,last});
        }
    }
    for(auto r : merged_ranges)
    {
        number_of_fresh_ids += r.second - r.first + 1;
    }
    cout << "Number of fresh ids in ranges: " << number_of_fresh_ids << endl;
}

int main()
{
    ifstream input("src/day5/input.txt");
    if(input.is_open())
    {
        string line;
        bool processing_ranges = true;
        vector<pair<long long,long long>> ranges;
        vector<long long> ids;
        while(getline(input,line))
        {
            if(line.empty())
            {
                processing_ranges = false;
                continue;
            }
            size_t middle = line.find('-');
            if (middle != string::npos) 
            {
                string start = line.substr(0, middle);
                string end = line.substr(middle + 1);
                ranges.push_back({stoll(start), stoll(end)});
            }
            else if(false == processing_ranges)
            {
                ids.push_back(stoll(line));
            }
        }
        solve(ranges, ids);
        solve2(ranges);
    }
    else
    {
        cerr << "Failed to open input.txt";
    }
    return 0;
}