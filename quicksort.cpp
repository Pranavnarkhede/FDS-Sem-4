#include<iostream>
using namespace std;


int partition( int arr[], int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right part 
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(int arr[], int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partition
    int p = partition(arr, s, e);

    //left part sort
    quickSort(arr, s, p-1);

    //right part sort
    quickSort(arr, p+1, e);

}

int main() {

   
    int n ;
    cout<<"Enter the number of Element =>"<<endl;
    cin>>n;
    int arr[n];
    cout<<" Enter the element  "<<endl;
    for(int i=0 ; i<n ;i++)
    {
       cin>>arr[i];
    }
    cout<<" Array before Sorting ==>"<<endl;
     for(int i=0 ; i<n ;i++)
    {
       cout<<arr[i]<<" ";
    }  cout<<endl;

    quickSort(arr, 0, n-1);
    
    cout<<"Sorted Array ==>"<<endl;
    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;


    return 0;
}
