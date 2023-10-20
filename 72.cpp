#include <bits/stdc++.h>
using namespace std;
// How To Solve Graph Matrix Problems using DFS
// https://leetcode.com/problems/flood-fill/description/


/*
i1, j1 and i2, j2 form an edge only when 
then are up, down, right or left of one  other and they have same color
*/



// void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>>& image){
//     int n = image.size();
//     int m = image[0].size();
//     if(i<0 || j<0) return;
//     if(i>=n || j>= m) return;
//     if(image[i][j] != initialColor) return;

//     image[i][j] = newColor;

//     dfs(i-1,j, initialColor, newColor, image);
//     dfs(i+1,j, initialColor, newColor, image);
//     dfs(i,j-1, initialColor, newColor, image);
//     dfs(i,j+1, initialColor, newColor, image);
// }


// vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//     int initialColor = image[sr][sc];
//     if(initialColor != color)
//         dfs(sr, sc, initialColor, color, image);
//     return image;
// }

// int main() {


//     return 0;
// }





// https://leetcode.com/problems/number-of-islands/description/





void dfs(int i, int j, vector<vector<char>>& grid, int n, int m){

    if(i<0 || j<0) return;
    if(i>=n || j>=m) return;
    if(grid[i][j] == '0') return;

    grid[i][j] = '0';

    dfs(i-1, j, grid, n, m);
    dfs(i+1, j, grid, n, m);
    dfs(i, j-1, grid, n, m);
    dfs(i, j+1, grid, n, m);
}


int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j] == '1'){
                ct++;
                dfs(i, j, grid, n, m);
            }
        }
    }
    return ct;
    
}

int main() {
    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout<<numIslands(grid)<<endl;

    return 0;
}