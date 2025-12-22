#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void solve(vector<vector<int>> banks) 
{
    int total_joltage = 0;
    for(vector<int> bank : banks)
    {
        int max_right = -1;
        int max_joltage = 0;
        for (int i = bank.size() - 1; i >= 0; --i)
        {
            int curr_battery_level = bank[i];
            if(max_right != -1)
            {
                int curr_joltage = max_right + (curr_battery_level*10);
                if(curr_joltage > max_joltage)
                {
                    max_joltage = curr_joltage;
                }
            }
            if(curr_battery_level > max_right)
            {
                max_right = curr_battery_level;
            }
        }
        cerr << max_joltage << '\n';
        total_joltage += max_joltage;
    }
    cout << "Total joltage: " << total_joltage;
}

int main() 
{
    ifstream input("src/day3/input.txt");
    if (input.is_open()) 
    {
        string line;
        vector<vector<int>> banks;
        while (getline(input, line)) 
        {
            if (line.empty())
            {
                continue;
            }
            vector<int> joltages;
            for(auto c : line)
            {
                joltages.push_back(int(c-'0'));
            }
            banks.push_back(joltages);
        }
        solve(banks);
        input.close();
    }
    return 0;
}