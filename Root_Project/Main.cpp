#include <iostream>
#include "Compare.h"

using namespace std;

int main(void) {


	int size, count;
	string index = " ";

	bool flag = true;
	cout << "������ ��ǥ�� �Է��ϼ��� ���͸� ġ�� �Է��� ����˴ϴ�. : ";
	cin >> size;

	getline(cin, index);
	
	while (true)
	{
		if (index.empty()) {
			cin.ignore();
			cout << "�߸��� �Է��Դϴ�." << endl;
			cout << "������ ��ǥ�� �Է��ϼ��� ���͸� ġ�� �Է��� ����˴ϴ�. : ";
			getline(cin, index);
		}
		else {
			break;
		}
	}

	// vector�� ��� ���� 0���� �ʱ�ȭ
	// vector < vector <int> > x(size, vector <int>(size, 0));
	Compare a(size);

	count = a.Sort(index);
	a.Root(count);

	a.Print();

	/*
	// ���� ���� ����
	for (int i = 1; i < index.size(); i++) {
		if (index[i] == ' ') {
			index_size++;
		}
	}

	// index_size�� �������� 0�̸� y��ǥ�� �Է� ���� ���� ���̹Ƿ� �����ع�����.
	if (index_size % 2 == 0) {
		index_size--;
	}

	// string�� size��ŭ �ݺ��ѵ� ���� �߶� ����
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
	cout << "�迭 ũ��, x, y ��ǥ �Է� : ";
	cin >> size;

	PrintSc(size);
	// 2���� ���� �Ҵ� �� �� ���� 10000���� �ʱ�ȭ
	vector < vector <int> > x(size, vector <int>(size, 10000));

	cin >> x_index >> y_index;

	while (x_index != 900)
	{
		// �迭 ũ�� �ʰ�
		if (y_index >= size || x_index >= size) {
			cout << "�߸� �Է�";
			cin.ignore();
		}
		else {
			x[count][0] = x_index;
			x[count][1] = y_index;
			count++;
		}
		cin >> x_index >> y_index;
	}

	//����
	sort(x.begin(), x.end(), Compare);

	for (int i = 0; i < count; i++) {
		cout << x[i][0] << ", " << x[i][1] << endl;
	}
	*/
	cout << endl << "�ƹ��ų� �Է��ϸ� �����մϴ�." << endl;
	cin.ignore();
	return 0;
}