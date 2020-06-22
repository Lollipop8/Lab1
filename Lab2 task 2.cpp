#include <iostream> 
#include <sstream>
#include <windows.h>
using namespace std;
string WordK(const string& S, int K)
{
	string r;
	istringstream iss(S);
	for (int i = 0; i < K && (iss >> r); ++i);
	if (!iss) r.clear();
	cout << r;
	return r;
}
int main( int K1, int K2, int K3)
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	cout << "Введите выражение: ";
	string S;
	getline(cin, S);
	cout << "Введите первое число: ";
	cin >> K1;
	string(*fnc)(const string&, int) = WordK;
	fnc(S, K1);
	cout << endl;
	cout << "Введите второе число: ";
	cin >> K2;
	fnc(S, K2);
	cout << endl;
	cout << "Введите третье число: ";
	cin >> K3;
	fnc(S, K3);
	cout << endl;
	return 0;
}
