#include <bits/stdc++.h>
using namespace std;
float knapsack_max_profit(multimap<float,float,greater<float>>m,int c){
    float total_profit=0,cap_cal=0;
    for(auto x:m){
        if(cap_cal+x.second <= c){
            cap_cal += x.second;
            total_profit += x.first;
        }
        else{
            total_profit += x.first*(c-cap_cal)/x.second;
            break;
        }
    }
    return total_profit;
}
float knapsack_max_pbw(multimap<float,float,greater<float>>m,int c){
    float total_pbw=0,cap_cal=0;
    for(auto x:m){
        if(cap_cal+x.second <= c){
            cap_cal += x.second;
            total_pbw += x.first/x.second;
        }
        else{
            total_pbw += (x.first/x.second)*(c-cap_cal)/x.second;
            break;
        }
    }
    return total_pbw;
}
float knapsack_min_weight(multimap<float,float>o,int c){
    float total_profit=0,cap_cal=0;
    for(auto x:o){
        if(cap_cal+x.first <= c){
            cap_cal += x.first;
            total_profit += x.second;
        }
        else{
            total_profit += x.second*(c-cap_cal)/x.first;
            break;
        }
    }
    return total_profit;
}
int main() {
    int n,c,p,w;
    cout<<"Enter the number of object : ";
    cin>>n;
    cout<<"Enter the capacity : ";
    cin>>c;
    vector<float>x(n,0);
    multimap<float,float,greater<float>>m;
    multimap<float,float>o;
    cout<<"Enter profit  and weight for objects : \n";
    for(int i=0; i<n ; i++){
        cin>>p;
        cin>>w;
        m.insert(pair<float,float>(p,w));
        o.insert(pair<float,float>(w,p));
    }
    cout<<"\nAfter selecting object for max profit \nMax profit = "<<knapsack_max_profit(m,c);
    cout<<"\n\nAfter selecting object for min weight \nMax profit = "<<knapsack_min_weight(o,c);
    cout<<"\n\nAfter selecting object for max profit/weight ratio\nMax profit = "<< knapsack_max_pbw(m,c);
    return 0;
}
/*
n=5

10 2
2 3
12 8
20 3
6 9
*/
