#include <iostream>
using namespace std;



void merge(int arr[],int start,int mid,int end){
    int i=0,j=0,k=0;
    int n1=mid-start+1;
    int n2=end-mid;
    int left[n1];
    int right[n2];
    int a=start;
    int b=mid+1;


    for(int i=0;i<n1;i++){
        left[i]=arr[a++];
    }
     for(j=0;j<n2;j++){
        right[j]=arr[b++];
    }

    i=0;j=0;k=start;

    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
    arr[k]=right[j];
    j++;
    k++;
   }
  

}
void mergesort(int arr[],int start,int end){
    if(start>=end){
        return;
    }

        int mid=start+(end-start)/2;

        mergesort(arr,start,mid);

        mergesort(arr,mid+1,end);

        merge(arr,start,mid,end);
    }




int main(){

    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter elements to sort"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int start=0;
    int end=n-1;
   mergesort(arr,start,end);

   cout<<"Sorted Array"<<endl;
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }

    return 0;
}
