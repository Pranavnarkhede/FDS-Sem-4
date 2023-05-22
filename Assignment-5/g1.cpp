#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int n , total = 0 , sum;
    cout << "Size of candidates array : ";
    cin >> n;
    vector<int>selected;
    vector<int>rejected;

    //taking candidates input
    vector<int>candidates(n);
    cout << "Enter candidates array" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> candidates[i];
    }

    cout << "Target sum : ";
    cin >> sum;

    //performing greedy
    for(int i = 0 ; i < n ; i++)
    {
        if(candidates[i] + total <= sum)
        {
            selected.push_back(candidates[i]);
            total = total + candidates[i];
        }
        else
        {
            rejected.push_back(candidates[i]);
        }
    }

    if(total == sum)
    {
        cout << "Selected Candidates : " << endl;
        for(int i = 0 ; i < selected.size() ; i++)
        {
            cout << selected[i] << " ";
        }
        cout << endl;

        cout << "Rejected Candidates : " << endl;
        for(int i = 0 ; i < rejected.size() ; i++)
        {
            cout << rejected[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Solution not possible" << endl;
    }
    return 0;
}
