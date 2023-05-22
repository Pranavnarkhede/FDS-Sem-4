#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int size, int i) {
    int max = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left] > arr[max])
        max = left;
    if (right < size && arr[right] > arr[max])
        max = right;
        
    if(max != i)
    {
        swap(arr[max],arr[i]);
        heapify(arr, size, max);
    }
 }
void heapSort(vector<int> &arr) 
{
    int size = arr.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i > 0; i--) 
    {
        swap(arr[i],arr[0]);
        heapify(arr, i, 0);
    }
}
int main() {
    int n;
    cout<<"Enter size==> "<<endl;
    cin >> n;
    vector<int> arr(n);
    cout<<"Enter the elements==>"<<endl;
    for(auto &x : arr) 
    {
        cin >> x;
    }
    heapSort(arr);

    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
