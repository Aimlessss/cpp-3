#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    bool isSafe(int i, int j)
    {
        if (i >= n || j >= n || i < 0 || j < 0)
            return false;
    }
    vector<vector<int>>direct = {
        {1, 0}, {-1, 0}, {0, -1}, {0, 1}
    };
    void dfs(vector<vector<int>> &grid, set<pair<int, int>> &st, int i, int j)
    {

        if (!isSafe(i, j) || st.find({i, j}) != st.end() || grid[i][j] == 0)
        {
            return;
        }

        st.insert({i, j});

        dfs(grid, st, i + 1, j);
        dfs(grid, st, i - 1, j);
        dfs(grid, st, i, j + 1);
        dfs(grid, st, i, j - 1);
    }

    int bfs(vector<vector<int>> &grid, set<pair<int, int>> st)
    {
        queue<pair<int, int>> q;
        for (auto &x : st)
        {
            q.push({x.first, x.second});
        }
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            int level = 0;
            while (size--)
            {
                auto p = q.front();
                int x = p.first;
                int y = p.second;
                for(auto dirt : direct){
                    int x_ = x + dirt[0];
                    int y_ = y + dirt[1];
                    if(isSafe(x_, y_) && st.find({x_, y_}) != st.end()){
                        if(grid[x_][y_] == 1){
                            return level;
                        }
                        st.insert({x, y});
                        q.push({x, y});
                    }

                }
            }
            level++;
        }
    }

    int shortestBridge(vector<vector<int>> &grid)
    {
        n = grid.size();
        set<pair<int, int>> set;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dfs(grid, set, i, j);
                return bfs(grid, set);
            }
        }
    }
};

// class Solution {
// public:
//     int m, n;
//     vector<vector<int>> directions = {
//                 {-1,0},
//         {0,-1},         {0,1},
//                 {1, 0}
//     };

//     bool isSafe(int i, int j) {
//         return (i < m && i >= 0 && j < n && j >= 0);
//     }

//     void dfs(vector<vector<int>>& grid, int i, int j, set<pair<int, int>>& visitedCell) {
//         if(!isSafe(i, j) || grid[i][j] == 0 || visitedCell.find({i, j}) != visitedCell.end()) {
//             return;
//         }

//         visitedCell.insert({i, j});

//         for(auto &dir : directions) {
//             int i_ = i + dir[0];
//             int j_ = j + dir[1];

//             dfs(grid, i_, j_, visitedCell);
//         }
//     }

//     int bfs(vector<vector<int>>& grid, set<pair<int, int>>& visitedCell) {
//         queue<pair<int, int>> que;

//         for(auto &it : visitedCell) {

//             que.push({it});

//         }

//         int level = 0;

//         while(!que.empty()) {
//             int L = que.size();

//             while(L--) {
//                 pair<int, int> P = que.front();
//                 que.pop();

//                 for(auto &dir : directions) {
//                     int i_ = P.first + dir[0];
//                     int j_ = P.second + dir[1];

//                     if(isSafe(i_, j_) && visitedCell.find({i_, j_}) == visitedCell.end()) {
//                         if(grid[i_][j_] == 1) //found another island
//                             return level;

//                         visitedCell.insert({i_, j_});
//                         que.push({i_, j_});
//                     }
//                 }

//             }
//             level++;
//         }

//         return level;
//     }

//     int shortestBridge(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         set<pair<int, int>> visitedCell;

//         for(int i = 0; i<m; i++) {
//             for(int j = 0; j<n; j++) {

//                 if(grid[i][j] == 1) {
//                     dfs(grid, i, j, visitedCell); //It will mark one island visited
//                     return bfs(grid, visitedCell);
//                 }

//             }
//         }

//         return -1;
//     }
// };

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}};
    cout << s.shortestBridge(grid) << endl;
}