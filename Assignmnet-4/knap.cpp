#include <bits/stdc++.h>
using namespace std;

class Item 
{
public:
	int profit, weight;

	Item(){}
	Item(int profit, int weight)
	{
		this->profit = profit;
		this->weight = weight;
	}
};

bool cmpProfit(Item a, Item b)
{
	return a.profit > b.profit;
}

bool cmpWeight(Item a, Item b)
{
	return a.weight < b.weight;
}

bool cmpRatio(Item a, Item b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsackBasedOnWeight(int W, struct Item objects[], int N)
{
	sort(objects, objects + N , cmpWeight);

	double finalvalue = 0.0;

	for(int i = 0; i < N; i++) 
    {
		if(objects[i].weight <= W) 
        {
			W = W - objects[i].weight;
			finalvalue = finalvalue + objects[i].profit;
		}
		else 
        {
			finalvalue = finalvalue + objects[i].profit * ((double)W / (double)objects[i].weight);
			break;
		}
	}
	return finalvalue;
}

double fractionalKnapsackBasedOnProfit(int W, struct Item objects[], int N)
{
	sort(objects, objects + N , cmpProfit);

	double finalvalue = 0.0;

	for(int i = 0; i < N; i++) 
    {
		if(objects[i].weight <= W) 
        {
			W = W - objects[i].weight;
			finalvalue = finalvalue + objects[i].profit;
		}
		else 
        {
			finalvalue = finalvalue + objects[i].profit * ((double)W / (double)objects[i].weight);
			break;
		}
	}
	return finalvalue;
}

double fractionalKnapsackBasedOnRatio(int W, struct Item objects[], int N)
{
	sort(objects, objects + N , cmpRatio);

	double finalvalue = 0.0;

	for(int i = 0; i < N; i++) 
    {
		if(objects[i].weight <= W) 
        {
			W = W - objects[i].weight;
			finalvalue = finalvalue + objects[i].profit;
		}
		else 
        {
			finalvalue = finalvalue + objects[i].profit * ((double)W / (double)objects[i].weight);
			break;
		}
	}
	return finalvalue;
}

int main()
{
	int W , n;
	cout << "enter number of objects : ";
	cin >> n;
	cout << "enter capacity : ";
	cin >> W;
	Item objects[n];

	cout << "enter weights and profits" << endl;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> objects[i].weight;
		cin >> objects[i].profit;
	}
	
	cout << "based on weight : " << fractionalKnapsackBasedOnWeight(W, objects, n) << endl;
	cout << "based on profit : " << fractionalKnapsackBasedOnProfit(W, objects, n) << endl;
	cout << "based on ratio : " << fractionalKnapsackBasedOnRatio(W, objects, n) << endl;
	
	return 0;
}
/*

11
10

3 7
3 3
4 8
2 5
1 4
1 6
6 9
6 12
4 10
1 5

*/
