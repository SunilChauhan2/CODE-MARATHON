/*Question 1: Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j iff either j = i + 1 or j = 3i. The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.
Input Format:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains a single line of input which contains an integer, n.
Output Format:
Print the number of edges in the shortest path from 1 to n.
Sample Input
1
9
Sample Output
2
Explanation:
The minimum number of edges from vertex 1 to vertex 9 is 2.*/

int number_of_edges(int n) {
  if (n == 1) return 0;
    
    bool visited[10001]; 
    memset(visited, false, sizeof(visited));
    
    queue<pair<int, int>> q; 
    q.push({1, 0});
    visited[1] = true;
    
    while (!q.empty()) {
        int node = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if (node == n) return depth;
        
        
        if (node + 1 <= 10000 && !visited[node + 1]) {
            visited[node + 1] = true;
            q.push({node + 1, depth + 1});
        }
        
        
        if (3 * node <= 10000 && !visited[3 * node]) {
            visited[3 * node] = true;
            q.push({3 * node, depth + 1});
        }
    }
    return -1;
}


/*Question 2: Given a un-directed graph find out if there is a cycle in it or not.
Note: The given graph may or may not be connected.
Example 1: The following graph contains a cycle
Example 2: The following graph does not contain a cycle
Input Format
The first line contains the Number of vertices, V.
The second line contains the Number of edges, E.
Then E lines follow , containing 2 numbers,x & y, seperated by space denoting an edge from vertex x to y.
Output Format
Print Yes or No depending on graph has cycle or not.
Sample Input
5	// Vertices
5	// Edges
0 1	// Edge from v1 to v2
0 2
1 2
0 3
3 4
Sample Output
Yes 
Explanation:
The graph is having a cycle from vertices 0, 1 and 2*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000;
bool adj[MAX][MAX]; 
bool visited[MAX];

bool bfs_cycle_check(int start, int V) {
    queue<pair<int, int>> q;
    q.push({start, -1});
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        
        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push({i, node});
                } else if (i != parent) {
                    return true; 
                }
            }
        }
    }
    return false;
}

bool has_cycle(int V) {
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (bfs_cycle_check(i, V)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    
    memset(adj, false, sizeof(adj));
    
    for (int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = true;
    }
    
    if (has_cycle(V)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
