#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void solve(const vector<pair<string,string>>& ranges) 
{
    for (const auto& r : ranges) {
        
        cerr << "Range: " << r.first << " to " << r.second << "\n";
    }
}

int main() 
{
    ifstream input("src/day2/input.txt");
    if (input.is_open()) 
    {
        string line;
        vector<pair<string,string>> ranges;
        while (getline(input, line)) 
        {
            if (line.empty())
            {
                continue;
            }
            stringstream ss(line);
            string segment;
            while (getline(ss, segment, ',')) 
            {
                size_t middle = segment.find('-');
                if (middle != string::npos) 
                {
                    string start = segment.substr(0, middle);
                    string end = segment.substr(middle + 1);
                    ranges.push_back({start, end});
                }
            }
        }
        solve(ranges);
        input.close();
    }
    return 0;
}