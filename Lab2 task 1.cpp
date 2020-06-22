#include <iostream> 
using namespace std;
void Sort(int N, float A[]) {
	for (int startIndex = 0; startIndex < N - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < N; ++currentIndex)
		{

			if (A[currentIndex] < A[smallestIndex])
				smallestIndex = currentIndex;
		}
		
		swap(A[startIndex], A[smallestIndex]);
	}
		for (int index = 0; index < N; ++index)
		cout << A[index] << ' ';
	cout << endl;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите размер массива:";
	cin >> N;
	float* A = new float[N];
	for (int i = 0; i < N; i++) {
		cout << "Введите элемент массива A: " << endl;
		cin >> A[i];
	}
	Sort(N, A);
	float* B = new float[N];
	for (int i = 0; i < N; i++) {
		cout << "Введите элемент массива B: " << endl;
		cin >> B[i];
	}
	Sort(N, B);
	float* C = new float[N];
	for (int i = 0; i < N; i++) {
		cout << "Введите элемент массива C: " << endl;
		cin >> C[i];
	}
	Sort(N, C);
	return 0;
	}
