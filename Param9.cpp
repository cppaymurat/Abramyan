#include <bits/stdc++.h>
using namespace std;
void RemoveForInc(double *A, int &N) {
	double last = A[0];//���������� ��������� ������� �������
	double *B;
	int cnt = 1;
	for(int i = 1; i < N; i++) {//���������� �� ����� �������
		if (A[i] >= last) {
			last = A[i];
			cnt++;//������� ���������� ������� ���������
		} else A[i] = -1;
	}
	B = new double[cnt];
	int j = 0;
	for(int i = 0; i < N; i++) {//������� ����� ������ B, ���� �������� ���� ������� ��������
		if (A[i] != -1) {
			B[j] = A[i];
			j++;
		}
	}
	realloc(A, j * sizeof(double));//����� ����������������� ������ ������� � ������ ������ ������� �
	for(int i = 0; i < j; i++) {
		A[i] = B[i];//�������� ������ � � ������ �
	}
	N = j;//� ������ ������� � � ������ ������� �
	//����� � ��� ���� ������������ �������� � �������
}
int main() {
	setlocale(LC_ALL,"Rus");
	int N;
	cout << "������� ������ ������� A: ";//������� ������
	cin >> N;
	double *A = new double[N];
	srand(time(0));
	cout << "������� ������ A: " << endl;//������� ������
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	RemoveForInc(A, N);//�������� ���������
	for(int i = 0; i < N; i++) {
		cout << A[i] << " ";//������� ���������
	}
	cout << endl;
	int NB;
	cout << "������� ������ ������� B: ";//������� ������
	cin >> NB;
	double *B = new double[N];
	srand(time(0));
	cout << "������� ������ B: " << endl;//������� ������
	for(int i = 0; i < NB; i++) {
		cin >> B[i];
	}
	RemoveForInc(B, NB);//�������� ���������
	for(int i = 0; i < NB; i++) {
		cout << B[i] << " ";//������� ���������
	}
	cout << endl;
	int NC;
	cout << "������� ������ ������� C: ";//������� ������
	cin >> NC;
	double *C = new double[NC];
	srand(time(0));
	cout << "������� ������ C: " << endl;//������� ������
	for(int i = 0; i < NC; i++) {
		cin >> C[i];
	}
	RemoveForInc(C, NC);//�������� ���������
	for(int i = 0; i < NC; i++) {
		cout << C[i] << " ";//������� ���������
	}
	delete []A;//������� ���������� ������������ ������
	delete []B;
	delete []C;
	return 0;//��������� ���������
}
