#include <bits/stdc++.h>
using namespace std;
void RemoveForInc(double *A, int &N) {
	double last = A[0];//запоминаем последний хороший элемент
	double *B;
	int cnt = 1;
	for(int i = 1; i < N; i++) {//проходимся по всему массиву
		if (A[i] >= last) {
			last = A[i];
			cnt++;//считаем количество хороших элементов
		} else A[i] = -1;
	}
	B = new double[cnt];
	int j = 0;
	for(int i = 0; i < N; i++) {//создаем новый массив B, туда копируем лишь хорошие элементы
		if (A[i] != -1) {
			B[j] = A[i];
			j++;
		}
	}
	realloc(A, j * sizeof(double));//далее переустанавливаем память массива А равной памяти массива В
	for(int i = 0; i < j; i++) {
		A[i] = B[i];//копируем массив В в массив А
	}
	N = j;//и размер массива В в размер массива А
	//итого у нас лишь возрастающие элементы в массиве
}
int main() {
	setlocale(LC_ALL,"Rus");
	int N;
	cout << "Введите размер массива A: ";//считаем размер
	cin >> N;
	double *A = new double[N];
	srand(time(0));
	cout << "Введите массив A: " << endl;//считаем массив
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	RemoveForInc(A, N);//вызываем процедуру
	for(int i = 0; i < N; i++) {
		cout << A[i] << " ";//выводим результат
	}
	cout << endl;
	int NB;
	cout << "Введите размер массива B: ";//считаем размер
	cin >> NB;
	double *B = new double[N];
	srand(time(0));
	cout << "Введите массив B: " << endl;//считаем массив
	for(int i = 0; i < NB; i++) {
		cin >> B[i];
	}
	RemoveForInc(B, NB);//вызываем процедуру
	for(int i = 0; i < NB; i++) {
		cout << B[i] << " ";//выводим результат
	}
	cout << endl;
	int NC;
	cout << "Введите размер массива C: ";//считаем размер
	cin >> NC;
	double *C = new double[NC];
	srand(time(0));
	cout << "Введите массив C: " << endl;//считаем массив
	for(int i = 0; i < NC; i++) {
		cin >> C[i];
	}
	RemoveForInc(C, NC);//вызываем процедуру
	for(int i = 0; i < NC; i++) {
		cout << C[i] << " ";//выводим результат
	}
	delete []A;//удаляем выделенную динамическую память
	delete []B;
	delete []C;
	return 0;//программа завершена
}
