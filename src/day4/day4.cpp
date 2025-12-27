#include <bits/stdc++.h>
using namespace std;

using coordinates2D = pair<int, int>;

void solve(const map<coordinates2D,vector<coordinates2D>> &adj)
{
    int result = 0;
    for (const auto& [coord, neighbors] : adj) {
        if (neighbors.size() < 4) {
            result++;
        }
    }
    cout << result;
}

void addEdges(map<coordinates2D,vector<coordinates2D>> &adj, int r, int c, const vector<vector<char>> &diagram)
{
    /*
    0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
    0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
    0 , 0 , TL, T , TR, 0 , 0 , 0 ,
    0 , 0 , L , IJ, R , 0 , 0 , 0 ,
    0 , 0 , BL, B , BR, 0 , 0 , 0 ,
    0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
    0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
    0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,

    Member = delta row, delta column
    TL = -1, -1
    T  = -1,  0
    TR = -1,  1
    L  =  0, -1
    IJ =  0,  0 (Skip this lookup)
    R  =  0,  1
    IJ =  1, -1
    B  =  1,  0
    BR =  1,  1
    */
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int i = 0; i < 8; i++)
    {
        int new_r = r + dr[i];
        int new_c = c + dc[i];
        if(new_r >= 0 && new_r < diagram.size() && new_c >= 0 && new_c < diagram[0].size())
        {
            if(diagram[new_r][new_c] == '@')
            {
                adj[{r,c}].push_back({new_r,new_c});
            }
        }
    }
}
void createAdjencyListFromDiagram(const vector<vector<char>> &diagram, map<coordinates2D,vector<coordinates2D>> &adj)
{
    for(size_t i = 0; i < diagram.size(); i++)
    {
        for(size_t j = 0; j < diagram[i].size(); j++)
        {
            if(diagram[i][j] == '@')
            {
                addEdges(adj, i, j, diagram);
            }
        }
    }
}

int main()
{
    ifstream input("src/day4/input.txt");
    if (input.is_open()) 
    {
        vector<vector<char>> diagram;
        
        string line;
        while (getline(input, line))
        {
            if (line.empty())
            {
                continue;
            }
            vector<char> row;
            for(char member : line)
            {
                row.push_back(member);
            }
            diagram.push_back(row);
        }
        map<coordinates2D,vector<coordinates2D>> adj;
        createAdjencyListFromDiagram(diagram, adj);
        solve(adj);
        input.close();
    }
    return 0;
}