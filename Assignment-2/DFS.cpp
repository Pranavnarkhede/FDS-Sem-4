#include <bits/stdc++.h>
using namespace std;
void dfs(int **matrix , vector<bool>&visited , int start , int n)
{
    visited[start] = true;
    for(int i = 1; i < n ; i++)
    {
        if(matrix[start][i] and !visited[i])
        {
            cout << "edge : " << start << " "<< i << endl;
            dfs(matrix , visited , i , n);
        }
    }
}
void dfsStack(int **matrix , vector<bool>&visited , int start , int n)
{
    stack<int> s;
    s.push(start);
    cout << start << " ";
    visited[start] = true;
    for(int i = 0 ; i < n ; i++)
    {
        if(matrix[start][i] and !visited[i])
        {
            dfsStack( matrix , visited , i , n);
            break;
        }
    }
    while(!s.empty())
    {
        if(!visited[s.top()])
        {
            cout << start << " ";
            visited[start] = true;
        }
        s.pop();
    }
}
int main()
{
    int n ;
    cout << "enter no of verices : ";
    cin >> n;
    int **matrix = new int*[n]; 
    vector <bool> visited(n) ;
    for(int i = 0 ; i < n ; i++)
    {
        visited[i] = false;
    }
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
    //dfs(matrix , visited , start , n);
    dfsStack(matrix , visited , start  , n);
    cout << endl;
    return 0;
}
