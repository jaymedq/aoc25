#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void solve(vector<vector<long long>> grid, vector<char> operands)
{
    long long result = 0;
    for(size_t i = 0; i < grid[0].size(); i++)
    {
        if(operands[i] == '*')
        {
            long long operation = 1;
            for(size_t j = 0; j < grid.size(); j++)
            {
                operation*=grid[j][i];
            }
            result+=operation;
        }
        else if(operands[i] == '+')
        {
            for(size_t j = 0; j < grid.size(); j++)
            {
                result+=grid[j][i];
            }
        }
    }
    cout << "Result part 1: " << result << endl;
}
void solve2(vector<string> lines)
{
    string operands_line = lines[lines.size()-1];
    long long result = 0;
    vector<string> operation_columns;
    for(int j = lines[0].size()-1 ; j >= 0; --j)
    {
        string column;
        for(size_t i = 0; i < lines.size()-1; i++)
        {
            if(isalnum(lines[i][j]))
            {
                column.push_back(lines[i][j]);
            }
        }
        if(!column.empty())
        {
            operation_columns.push_back(column);
        }
        if(operands_line[j] == '+')
        {
            for(size_t i = 0; i < operation_columns.size(); i++)
            {
                result+=stoll(operation_columns[i]);
            }
            operation_columns.clear();
        }
        else if(operands_line[j] == '*')
        {
            long long operation = 1;
            for(size_t i = 0; i < operation_columns.size(); i++)
            {
                operation*=stoll(operation_columns[i]);
            }
            result+=operation;
            operation_columns.clear();
        }
    }
    cout << "Result part 2: " << result << endl;
}
int main()
{
    ifstream input("src/day6/input.txt");
    if(input.is_open())
    {
        string line;
        vector<vector<long long>> grid;
        vector<char> operands;
        while(getline(input,line))
        {
            stringstream ss(line);
            string segment;
            vector<long long> row;
            while (getline(ss, segment, ' '))
            {
                if(segment.empty()) continue;
                if(segment == "+" || segment == "*")
                {
                    operands.push_back(segment[0]);
                    continue;
                }
                row.push_back(stoll(segment));
            }
            if(row.empty()) continue;
            grid.push_back(row);
        }
        solve(grid,operands);
        // Part 2:
        vector<string> lines;
        vector<long long> cols;
        input.clear();
        input.seekg(0, ios::beg);
        while(getline(input,line))
        {
            lines.push_back(line);
        }
        solve2(lines);
    }    
    return 0;
}