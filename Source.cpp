#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	int n, m;
	cin >> n; //считали высоту
	cin >> m; // и ширину
	string dummy;
	string s;
	getline(cin, dummy);

	char **M = (char**)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
		M[i] = (char*)calloc(m, sizeof(char));
	for (int i = 0; i < n; i++) 
	{
		getline(cin, s);
		strcpy(M[i], s.c_str());
	}
	int layers;
	cin >> layers;
	getline(cin, dummy);
	char* str = new char[200];
	string k;
	int *countOfLayer = new int[layers+1];
	char* symbols = new char[layers + 1];
	for (int i = 0; i < layers; i++) 
	{
		cin >> k;
		cin >> countOfLayer[i];
		cin >> symbols[i];
	}

	int full = 0;
	for (int i = 0; i < layers; i++)
	{
		full += countOfLayer[i];
	}
	int cast = 0;
	for (int i = 0; i < n - full - 1; i++) 
	{
		cout << M[i] << endl;
		cast++;
	}
	for (int i = 0; i < layers; i++) 
	{
		for (int j = 0; j < countOfLayer[layers - 1 - i]; j++) 
		{
			for (int h = 0; h < m; h++) 
			{
				if (M[cast][h] == ' ') M[cast][h] = symbols[layers - i - 1];
			}
			cout << M[cast] << endl;
			cast++;
		}
	}
	cout << M[n - 1] << endl;
}


