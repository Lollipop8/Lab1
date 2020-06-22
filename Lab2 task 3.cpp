#include <iostream> 
using namespace std;
int MaxInt(int A[], int N)
{
	int i = 0, max = A[0];
l1:
	if (max < A[i]) max = A[i];
	i++;
	if (i >= N) goto l2;
	goto l1;
l2:
	cout << max;
	return max;
}
int main( )
{
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите размер массива: ";
	cin >> N;
	if (N <= 10) {
		int* A = new int [N];
		for (int i = 0; i < N; i++) {
			cout << "Введите элемент массива A: ";
			cin >> A[i];
		}
		int(*fnc)(int [], int) = MaxInt;
		fnc(A, N);
		cout << endl;
		int* B = new int[N];
		for (int i = 0; i < N; i++) {
			cout << "Введите элемент массива B: ";
			cin >> B[i];
		}
		fnc(B, N);
		cout << endl;
		int* C = new int[N];
		for (int i = 0; i < N; i++) {
			cout << "Введите элемент массива C: ";
			cin >> C[i];
		}
		fnc(C, N);
	}
	else cout << "ERROR";
	return 0;
}
