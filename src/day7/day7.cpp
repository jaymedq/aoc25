#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric> // For std::accumulate

using namespace std;

void get_lines_from_input(std::string file_name, std::vector<std::string> &lines)
{
    std::ifstream input(file_name);
    std::string line;
    if(input.is_open())
    {
        while(std::getline(input,line))
        {
            lines.push_back(line);
        }
    }
}

// Your original Part 1 solution (kept for reference)
void solve(vector<string> lines)
{
    size_t original_beam_index = lines.front().find('S');
    long long split_count = 0;
    if (lines.size() > 1) 
    {
        lines[1][original_beam_index] = '|';
    }
    for(int i = 2; i < lines.size(); i++)
    {
        string &line = lines[i];
        for(int j = 0; j < line.size(); j++)
        {
            if(lines[i-1][j] == '|')
            {
                if(line[j] == '^')
                {
                    if(j-1 >= 0)
                    {
                        line[j-1] = '|';
                    }
                    if(j+1 < line.size())
                    {
                        line[j+1] = '|';
                    }
                    split_count++;
                }
                else if (line[j] == '.')
                {
                    line[j] = '|';
                }
            }
        }
    }
    cout << "Split Count (Part 1): " << split_count << endl;
}

void solve2(const vector<string>& lines)
{
    if (!lines.empty())
    {
        int n = lines.size();
        int m = lines[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
    
        size_t s_index = lines[0].find('S');
        if (s_index != string::npos) {
            dp[0][s_index] = 1;
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                long long incoming_timelines = dp[i-1][j];
                
                if (incoming_timelines > 0)
                {
                    char current_char = lines[i][j];
    
                    if (current_char == '.')
                    {
                        dp[i][j] += incoming_timelines;
                    }
                    else if (current_char == '^')
                    {
                        if (j - 1 >= 0) {
                            dp[i][j-1] += incoming_timelines;
                        }
                        if (j + 1 < m) {
                            dp[i][j+1] += incoming_timelines;
                        }
                    }
                }
            }
        }
        long long total_timelines = 0;
        for (long long count : dp[n-1]) {
            total_timelines += count;
        }
        cout << "Total Timelines (Part 2): " << total_timelines << endl;
    }
}

int main()
{
    vector<string> lines;
    get_lines_from_input("src/day7/input.txt", lines);
    
    solve(lines); 
    solve2(lines);
    
    return 0;
}