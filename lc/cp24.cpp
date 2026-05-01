#include <bits/stdc++.h>
using namespace std;
int maxScore;
vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void solve(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int score, int cost, int k) {
    int m = grid.size();
    int n = grid[0].size();
    if (x == m - 1 && y == n - 1) {
        if (cost <= k) {
            maxScore = max(maxScore, score);
        }
        return;
    }
    for (auto& dir : directions) {
        int newX = x + dir[0];
        int newY = y + dir[1];
        if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
            visited[newX][newY] = true;
            int newScore = score + (grid[newX][newY] == 1 ? 1 : (grid[newX][newY] == 2 ? 2 : 0));
            int newCost = cost + (grid[newX][newY] == 1 ? 1 : (grid[newX][newY] == 2 ? 1 : 0));
            solve(grid, visited, newX, newY, newScore, newCost, k);
            visited[newX][newY] = false;
        }
    }
}
int maxPathScore(vector<vector<int>>& grid, int k) {
    maxScore = INT_MIN;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int startScore = (grid[0][0] == 1 ? 1 : (grid[0][0] == 2 ? 2 : 0));
    visited[0][0] = true;
    int cost = (grid[0][0] == 1 ? 1 : (grid[0][0] == 2 ? 1 : 0));
    solve(grid, visited, 0, 0, startScore, cost, k);
    return maxScore;
}

int main() {
	// your code goes here
    // [[0, 1],[2, 0]]
    vector<vector<int>> grid = {{0, 1}, {2, 0}};
    int k = 1;
    cout << maxPathScore(grid, k) << endl;
	return 0;
}
