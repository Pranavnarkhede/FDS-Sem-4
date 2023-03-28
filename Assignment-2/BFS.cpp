#include <bits/stdc++.h>
using namespace std;
void bfs(int **matrix , int n , int start)
{
    vector <bool> visited(n , false) ;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int vis;
    while (!q.empty()) 
    {
        vis = q.front();
        cout << vis << " ";
        q.pop();
        for (int i = 0; i < n; i++) 
        {
            if (matrix[vis][i] == 1 and !visited[i])
            {
                q.push(i);  
                visited[i] = true;
            }
        }
    }
}
int main()
{
    int n ;
    cout << "enter no of verices : ";
    cin >> n;
    int **matrix = new int*[n]; 
    cout << "enter adjacency matrix" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        matrix[i] = new int[n];
        for(int j = 0 ; j < n ; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int start;
    cout << "enter starting vertex : ";
    cin >> start;
    bfs(matrix , n , start);
    cout << endl;
    return 0;
}
