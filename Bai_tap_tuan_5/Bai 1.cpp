// Nguyen Kim Linh
// 20233495

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> unit_1(int arr[], int n) {
	vector<vector<int>> q;
	vector<int> v[3];
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) v[0].push_back(0);
		else if (arr[i] == 1) v[1].push_back(1);
		else v[2].push_back(2);
	}
	for (int i = 0; i < 3; i++)
		q.push_back(v[i]);
	return q;
}

void sort(int arr[], int n) {
	for(int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

void sort_3(int arr[], int n) {
	int count[3] = { };
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) count[0]++;
		else if (arr[i] == 1) count[1]++;
		else count[2]++;
	}
	for(int i = 0; i < 3; i++)
	while (count[i]--) cout << i << " ";
}

int main()
{
	int n = 8;
	int arr[] = { 1, 0, 2, 0, 2, 1, 0, 0 };
	/*cout << "Nhap n: "; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];*/

	//Cach 1
	/*vector<vector<int>> result = unit_1(arr, n);
	for (auto x : result)
		for(auto y : x)
			cout << y << " ";*/
	//Cach 2
	/*sort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";*/

	//Cach 3
	sort_3(arr, n);
	return 0;
}
