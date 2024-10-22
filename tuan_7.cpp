#include <iostream>
using namespace std;

class Population {
public:
	int year;
	int number;
};

Population DS[200];
int Size = 0;

int main() {
	while (true) {
		int y;
		cin >> y;
		DS[Size].year = y;
		if (y == 0) break; //ket thuc nhap mang
		if (y < 1900 || y > 2024) break;
		cin >> DS[Size++].number;
	}

	for (int i = 0; i < Size - 1; i++) {
		int count = 0;
		int v = DS[i].number;
		for (int j = i + 1; j < Size; j++) {
			if (v == DS[j].number) {
				/*if (count == 0)
					cout << DS[i].year << '\t';
				cout << DS[j].year << '\t';*/
				++count;
			}
		}
		if (count) cout << DS[i].number << " nguoi | Co " << count + 1 << " nam" << endl;
	}

	int min = DS[0].number, max = DS[0].number;
	for (int i = 1; i < Size; i++) {
		if (min > DS[i].number) min = DS[i].number;
		if (max < DS[i].number) max = DS[i].number;
	}

	cout << "So luong be nhat: " << min << " | ";
	for (int i = 0; i < Size; i++)
		if (min == DS[i].number)
			cout << DS[i].year << '\t';
	cout << endl;
	cout << "So luong lon nhat: " << max << " | ";
	for (int i = 0; i < Size; i++)
		if (max == DS[i].number)
			cout << DS[i].year << '\t';
}
