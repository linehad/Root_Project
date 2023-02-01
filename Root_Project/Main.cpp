#include <iostream>
#include "Compare.h"

using namespace std;

int main(void) {


	int size, count;
	string index = " ";

	bool flag = true;
	cout << "범위와 좌표를 입력하세요 엔터를 치면 입력이 종료됩니다. : ";
	cin >> size;

	getline(cin, index);
	
	while (true)
	{
		if (index.empty()) {
			cin.ignore();
			cout << "잘못된 입력입니다." << endl;
			cout << "범위와 좌표를 입력하세요 엔터를 치면 입력이 종료됩니다. : ";
			getline(cin, index);
		}
		else {
			break;
		}
	}

	// vector의 모든 값을 0으로 초기화
	// vector < vector <int> > x(size, vector <int>(size, 0));
	Compare a(size);

	count = a.Sort(index);
	a.Root(count);

	a.Print();

	/*
	// 공백 개수 세기
	for (int i = 1; i < index.size(); i++) {
		if (index[i] == ' ') {
			index_size++;
		}
	}

	// index_size의 나머지가 0이면 y좌표를 입력 받지 않은 것이므로 무시해버린다.
	if (index_size % 2 == 0) {
		index_size--;
	}

	// string의 size만큼 반복한뒤 값을 잘라서 넣음
	for (int i = 1; i < index_size; i += 2) {

		x_pos = stol(index.substr(i, 1));
		y_pos = stol(index.substr(i + 2, 1));
		cout << x_pos << " " << y_pos << endl;
	}
	*/



	/*
	int size;
	int count = 0;
	int x_index;
	int y_index;
	cout << "배열 크기, x, y 좌표 입력 : ";
	cin >> size;

	PrintSc(size);
	// 2차원 벡터 할당 및 각 값을 10000으로 초기화
	vector < vector <int> > x(size, vector <int>(size, 10000));

	cin >> x_index >> y_index;

	while (x_index != 900)
	{
		// 배열 크기 초과
		if (y_index >= size || x_index >= size) {
			cout << "잘못 입력";
			cin.ignore();
		}
		else {
			x[count][0] = x_index;
			x[count][1] = y_index;
			count++;
		}
		cin >> x_index >> y_index;
	}

	//정렬
	sort(x.begin(), x.end(), Compare);

	for (int i = 0; i < count; i++) {
		cout << x[i][0] << ", " << x[i][1] << endl;
	}
	*/
	cout << endl << "아무거나 입력하면 종료합니다." << endl;
	cin.ignore();
	return 0;
}