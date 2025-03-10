/*Question 1: Given a m x n binary matrix in which 1 represents ‘land’ and 0 represents ‘water’, find the number of islands.
An island is surrounded by water(0s) and is formed by connecting adjacent lands(1s) horizontally or vertically. You may assume all four edges of the given matrix are all surrounded by water.
Input Format:
First line contains two space separated integers m, n that denotes the number of rows and columns in the matrix respectively.
Each of the next m lines contain n space-separated integers representing the matrix.
Constraints:
1 <= m, n <= 150
Output Format:
Print the number of islands.
Sample Input
4 4
1 0 1 0
1 1 0 0
0 0 0 1
1 1 1 1
Sample Output
3
Explanation:
First island consists of following cells : (0, 0), (1, 0), (1,1)
Second island consists of following cells : (0, 2)
Third island consists of following cells : (2, 3)*/

void dfs(int** matrix, int m, int n, int i, int j) {
    
    if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] == 0) {
        return;
    }
    
    
    matrix[i][j] = 0;

   
    dfs(matrix, m, n, i + 1, j); 
    dfs(matrix, m, n, i - 1, j); 
    dfs(matrix, m, n, i, j + 1); 
    dfs(matrix, m, n, i, j - 1); 
}

int countIslands(int** matrix, int m, int n) {
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) { 
                count++;
                dfs(matrix, m, n, i, j); 
            }
        }
    }

    return count;

}


/*Question 2: Given a m x n binary matrix, find the length of the shortest path in the matrix from a given source cell to a destination cell. The path can only be created out of a cell if its value is 1.
If there is no path from a given source cell to a destination cell, return -1.
Note: At any point of time, you can either move horizontally or vertically in the four directions.
Input Format:
First line contains two space separated integers m, n that denotes the number of rows and columns in the matrix respectively.
Each of the next m lines contain n space-separated integers representing the matrix.
Second Last line contains two space separated integers, denoting the position of the source cell.
Last line contains two space separated integers, denoting the position of the destination cell.
Constraints:
1 <= m, n <= 150
Output Format:
Print the length of the shortest path from source to destination.
Sample Input
5 5
0 1 1 1 1
1 1 0 0 1
1 0 0 1 1
1 1 1 1 0
0 1 0 1 0
1 1
3 2
Sample Output
5
Explanation:
The shortest path from (1, 1) to (3, 2) is as follows:
(1, 1) -> (1, 0) -> (2, 0) -> (3, 0) -> (3, 1) -> (3, 2)*/

const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int shortestPath(vector<vector<int> > mat, int srcR, int srcC, int destR, int destC, int m, int n){
    if (srcR < 0 || srcR >= m || srcC < 0 || srcC >= n || mat[srcR][srcC] == 0 ||
        destR < 0 || destR >= m || destC < 0 || destC >= n || mat[destR][destC] == 0) {
        return -1;
    }

    
    queue<pair<int, int>> q;
    q.push({srcR, srcC});

    
    vector<vector<int>> distance(m, vector<int>(n, -1));
    distance[srcR][srcC] = 0;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        
        if (x == destR && y == destC) {
            return distance[x][y];
        }

       
        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && mat[newX][newY] == 1 && distance[newX][newY] == -1) {
                distance[newX][newY] = distance[x][y] + 1; 
                q.push({newX, newY}); 
            }
        }
    }


    return -1;
}