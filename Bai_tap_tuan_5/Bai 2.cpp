// Nguyen Kim Linh
// 20233495

#include <iostream>
#include <vector>
using namespace std;

int N = 30;
int count_prime = 0, count_blum = 0;
bool check_prime(int num) {
	int count = 0;
	if (num == 1) return false;
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0) return false;
	return true;
}

bool check_blum(int num, int arr_blum[]) {
	for (int i = 0; i < count_blum; i++)
		if (arr_blum[i] == num) return true;
	return false;
}
void create_arr_prime(int arr_prime[]) {
	if (N >= 2) arr_prime[count_prime++] = 2;
	for (int i = 3; i <= N / 2; i = i + 2)
		if (check_prime(i)) arr_prime[count_prime++] = i;
}

void create_arr_blum(int arr_blum[], int arr_prime[]) {
	for (int i = 0; i < count_prime; i++)
		for (int j = i; j < count_prime; j++) {
			int tich = arr_prime[i] * arr_prime[j];
			if (tich < N)
				arr_blum[count_blum++] = tich;
			else break;
		}
}


vector<pair<int, int>> create_pair_blum(int arr_blum[]) {
	vector<pair<int, int>> v;
	for(int i = 0; i < count_blum; i++)
		for (int j = i; j < count_blum; j++) {
			int num = arr_blum[i] + arr_blum[j];
			if (check_blum(num, arr_blum))
				v.push_back({ arr_blum[i], arr_blum[j]});
		}
	return v;
}

int main()
{
	int* arr_prime = new int[N];
	create_arr_prime(arr_prime);
	int* arr_blum = new int[count_prime];
	create_arr_blum(arr_blum, arr_prime);

	// Yeu cau 1
	vector<pair<int, int>> v;
	v = create_pair_blum(arr_blum);
	for (auto x : v)
		cout << x.first << " " << x.second << '\t';

	cout << endl;
	// Yeu cau 2
	int num_blum = 25;
	if (check_blum(num_blum, arr_blum))
		cout << "Ton tai";
	else cout << "Ko ton tai";
	delete[]arr_prime;
	delete[]arr_blum;
}
