#include <bits/stdc++.h>
using namespace std;
    int ROW, COL;
    vector<vector<int>> timings(ROW, vector<int>(COL, INT_MAX));
    vector<vector<int>> matrix(ROW, vector<int>(COL, 0));
    queue<pair<int, int>>q;
    vector<vector<int>>directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    void createMatrix(vector<vector<int>>& sources, int row, int col){
        for(auto x : sources){
            int srcRw = x[0];
            int srcCl = x[1];
            int color = x[2];
            matrix[srcRw][srcCl] = color;
            timings[srcRw][srcCl] = 0;
            q.push({srcRw, srcCl});
        }
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        ROW = n;
        COL = m;
        timings.assign(ROW, vector<int>(COL, INT_MAX));
        matrix.assign(ROW, vector<int>(COL, 0));
        createMatrix(sources, n, m);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front(); q.pop();
                for(auto direct : directions){
                    int currTime = timings[curr.first][curr.second];
                    int row_ = curr.first + direct[0];
                    int col_ = curr.second + direct[1];
                    if(row_ >= ROW || row_ < 0 || col_ >= COL || col_ < 0) continue;

                    if(matrix[row_][col_] == 0){
                        q.push({row_, col_});
                        timings[row_][col_] = currTime + 1;
                        matrix[row_][col_] = matrix[curr.first][curr.second];
                    }else if(matrix[row_][col_] != 0){
                        if(currTime + 1 < timings[row_][col_]){
                            q.push({row_, col_});
                            timings[row_][col_] = currTime + 1;
                        }else if(currTime == timings[row_][col_]){
                            matrix[row_][col_] = max(matrix[row_][col_], matrix[curr.first][curr.second]);
                        }
                    }
                }
            }
        }
        return matrix;
    }
int main()
{
    // Input: n = 3, m = 3, sources = [[0,0,1],[2,2,2]]
    vector<vector<int>> input = {{0,0,1},{2,2,2}};
    colorGrid(3, 3, input);
    return 0;
}
