#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Liczba
{
private:
	int liczba;
	float bezwzgledna;
	
	friend bool sortowanie(const Liczba& lhs, const Liczba& rhs);

public:
	int getLiczba(){
		return liczba;};
	
	float getBezwzgledna(){
		return bezwzgledna;};

	Liczba(){};

	Liczba(int liczba, float bezwzgledna){
		this->liczba = liczba;
		this->bezwzgledna = bezwzgledna;};

	~Liczba(){};
};

bool sortowanie(const Liczba & lhs, const Liczba & rhs){
	return lhs.bezwzgledna < rhs.bezwzgledna;}

void fillVector(vector<Liczba>& noweLiczby)
{
	int liczba;
	float srednia;
	float bezwzgledna;
	int rozmiar;
	float suma = 0;
	vector<int>temp;

	int ile_liczb;
	cin >> ile_liczb;

	for (int i = 0; i < ile_liczb; i++)
	{
		cin >> liczba;
		temp.push_back(liczba);
	}

	suma = accumulate(temp.begin(), temp.end(), 0);
	rozmiar = temp.size();
	srednia = suma / rozmiar;
	int liczbav;

	for (int j = 0; j < temp.size(); j++)
	{
		liczbav = temp[j];
		bezwzgledna = fabs(srednia - liczbav);
		Liczba nowaLiczba(liczbav, bezwzgledna);
		noweLiczby.push_back(nowaLiczba);
	}
}

int main()
{
	int ile;
	cin >> ile;

	for (int i = 0; i < ile; i++)
	{
		vector<Liczba>liczby;

		fillVector(liczby);

		sort(liczby.begin(), liczby.end(), sortowanie);
		
		cout << liczby[0].getLiczba() << endl;
	}
	return 0;
}