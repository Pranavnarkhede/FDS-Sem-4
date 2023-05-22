#include <iostream>
using namespace std;

void print(int nums[], int i, int j)
{
    for (int k = i; k <= j; k++) {
        cout<<nums[k]<<endl;
    }
}
void elements_sum(int arr[],int sum,int n){
    int st=0;
for(int i=0;i<n;i++){
     st=arr[i];
    if(st == sum){
         cout << "Sum found at indexes " << i << endl;
            return;
    }
    else{
            for (int j = i + 1; j < n; j++) {
                st += arr[j];
                if (st == sum) {
                cout << "Candidates found between index "<< i << " and "<<
                j << endl;
                cout<<"Candidates Accepted"<<endl;
               print(arr,i,j);
                
                    return;
                }
            }
        }
}
    cout << "No subarray found";
    return;
}
int main(){
 
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
   int sum;
   cout<<"Enter the sum you want?"<<endl;
   cin>>sum;

  elements_sum(arr,sum,n);
  return 0;

  }   

