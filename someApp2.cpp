// someApp2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<vector<double>> someArray;
	double input;
	cout << "\nInput 15 double numbers";
	for (size_t i = 0; i < 3; i++)
	{
		cout << endl <<"\Block number "<< i + 1 << "\n";
		someArray.push_back(vector<double>());
		for (size_t j = 0; j < 5; j++)
		{
			cout << j+1 << " - ";
			cin >> input;
			someArray[i].push_back(input);
		}
		cout << endl;
	}
	double res{0};
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 5; j++)
		{
			res += someArray[i][j];
		}
	cout << "The average of you numbers is - " << res/15;
}
