#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "math.h"

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

void solve2(vector<vector<int>> banks, const int K)
{
    unsigned long long total_joltage = 0; // Use unsigned long long for large sums

    for (vector<int> bank : banks)
    {
        int n = bank.size();
        int drop_count = n - K;
        vector<int> result;
        
        for (int digit : bank)
        {
            while (!result.empty() && result.back() < digit && drop_count > 0)
            {
                result.pop_back();
                drop_count--;
            }
            result.push_back(digit);
        }
        if (result.size() > K) 
        {
            result.resize(K);
        }

        int i = result.size() -1, j = 0;
        long long multiplier = 1;
        long long max_joltage = 0;
        while(i >= 0)
        {
            max_joltage+=result[i]*multiplier;
            j++;
            i--;
            multiplier *= 10;
        }
        total_joltage += max_joltage;
    }

    cout << "Total joltage for k = " << K << ": " << total_joltage << endl;
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
        solve2(banks, 2);
        solve2(banks, 12);
        input.close();
    }
    return 0;
}