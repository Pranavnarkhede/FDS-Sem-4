// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


int place(int pos,int a[]){
    for(int i=1;i<pos;i++){
        if(a[i] == a[pos]  || abs((a[i]-a[pos])) == abs(i-pos)){
            return 0;
        }
    }
    return 1;
}
void print(int n,int a[]){
   cout<<"Positions of QUEENS"<<endl;
   for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           if(a[i] == j){
               cout<<"Q ";
           }
           cout<<" ";
       }
       cout<<endl;
   }
}
void queen(int n,int a[]){
    int k=1;
    a[k]=0;
    while(k!=n){
        a[k]=a[k]+1;
        while(a[k]<=n  && !place(k,a)){
            a[k]++;
        }
        if(a[k]<=n){
            if(k == n){
                print(n,a);
            }
             else{
            k++;
            a[k]=0;
        }
        }
        else{
            k--;
        }
    }
}

int main() {
      int a[20];
      
      int n;
      cout<<"Enter no of queens==>"<<endl;
      cin>>n;
      queen(n,a);
 

    return 0;
}
