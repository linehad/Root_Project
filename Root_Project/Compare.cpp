#include <iostream>
#include <Windows.h>
#include <queue>
#include<algorithm>
#include <sstream>
#include "Compare.h"


Vec2D::Vec2D(int x, int y)
{
	this->x = x;
	this->y = y;
}


Compare::Compare(int size)
{
	count = 0;
	m_posSize = 0;
	m_VposSize = 0;
	m_size = size;
	m_Vpos.resize(size * size);
	m_map.resize(size, std::vector<Vec2D>(size));
	//visit = new int* [size];
}

Compare::~Compare()
{
	/*
	for (int i = 0; i < m_size; i++) {
		delete[]visit[i];
	}*/
}

int Compare::Sort(std::string index)
{
	{
		using namespace std;

		int x_pos, y_pos, count = 0;
		string temp;

		bool flag = true;

		// �� ������� ����� ���
		stringstream ss(index);
		while (ss >> temp)
		{
			if (flag)
			{
				flag = false;
				x_pos = stol(temp);

				// x��ǥ ���� size ���� Ŭ �� �����Ƿ� contine;
				if (x_pos >= m_size) {
					continue;
				}
			}
			else
			{
				flag = true;
				y_pos = stol(temp);

				// y��ǥ ���� size ���� Ŭ �� �����Ƿ� contine;
				if (y_pos >= m_size || x_pos >= m_size) {
					cout << "x �Ǵ� y ���� �ʰ� : " << x_pos << ", " << y_pos << endl;
					x_pos = y_pos = 0;
					continue;
				}

				// ���⿡�� vector�� �ִ� ������ x���� �־��� ��� �����ϱ� �����̴�.
				Vec2D vec(x_pos, y_pos);
				m_pos.push_back(vec);
				//m_pos[count][0] = x_pos;
				//m_pos[count][1] = y_pos;
				count++;
			}
		}

		// vector �������� ����

		sort(m_pos.begin(), m_pos.end(), [](Vec2D& l, Vec2D& r) {
			return (l.x + l.y) < (r.x + r.y);
			});

		// �ߺ� �� �� ó��
		m_pos.erase(unique(m_pos.begin(), m_pos.end()), m_pos.end());
		return count;
	}
}

/*
void Compare::Bfs(int x, int y)
{
	using std::cout;
	using std::endl;
	using std::vector;

	visit[x][y] = 1;

	for (int i = 0; i < count; i++) {
		//visit[m_pos[i][0]][m_pos[i][1]] = 3;
	}
	visit[x][y] = 1; // �湮ǥ��
}*/

void Compare::SetMap()
{
	using std::cout;
	using std::endl;

	const int POINT = 2147483647; // POINT : �����ؾ� �ϴ� ������
	const int ROOT = 2147483646; // ROOT : ������ ��
	const int START = 2147483645; // START : ���� ����
	const int END = 2147483644; // END : ���� ����
	const int OVER = 2147483640; // ���� ��� ��� ����

	bool flag = false;
	bool pass = false; // ������ ���� üũ �� bool

	m_posSize = m_pos.size();
	m_VposSize = m_Vpos.size();

	for (int i = 0; i < m_posSize; i++) {
		cout << m_pos[i].x << ", " << m_pos[i].y << endl;
	}
	cout << endl;

	//���� ���Ϳ��� �տ� �ִ� ���͸� ���� ������ ã�´�.
	for (int i = 0; i < (m_posSize -1); i++) {
		m_Vpos[i] = m_pos[i + 1] - m_pos[i];
		cout << m_Vpos[i].x << ", " << m_Vpos[i].y << endl;
	}

	cout << endl << endl;

	//�� �ʿ� ��ǥ�� �Է�
	for (int y = 0; y < m_size; y++) {
		for (int x = 0; x < m_size; x++) {
			Vec2D vec(x, y);
			m_map[y][x] = vec;
		}
	}

	// ��ü ���� ���鼭 �Է� ���� ��ǥ�� POINT�� �ٲٴ� �۾��� �Ѵ�.
	for (int i = 0; i < (m_size); i++)
	{
		for (int j = 0; j < (m_size); j++)
		{
			for (int k = 0; k < m_posSize; k++)
			{
				// ������ ���ϱ�
				if (m_pos[0] == m_map[i][j]) {
					m_map[i][j].x = START;
					m_map[i][j].y = START;
					break;
					//flag = true;
				}

				// �������� ���� Ž������ m_map�� ������ x,y��ǥ�� POINT�� �ٲ۴�.
				else if (m_pos[k] == m_map[i][j]) {
					m_map[i][j].x = POINT;
					m_map[i][j].y = POINT;

					pass = true;
					break;
				}

				// ������ ���ϱ�
				else if (m_pos[m_posSize - 1] == m_map[i][j]) {
					m_map[i][j].x = END;
					m_map[i][j].y = END;
					break;
					flag = true;
				}
			}
			if (pass || flag)
			{
				pass = false;
				break;
			}

		}
		// END�� �Է��ϸ� �ݺ��� ����
		if (flag)
		{
			flag = false;
			break;
		}


		/*
		// flag�� true�� �� �������� �ϴ� ��ǥ �̹Ƿ� �Ķ������� ĥ��
		if (flag) {
			ColorPrint(BLUE);
		}
		// false�� �Ͼ��
		else {
			ColorPrint(WHITE);
		}
		flag = false;

		// i�� 0�� ° �϶��� 0 % m_size �� �Ǿ�����Ƿ� ����ó��
		if (i == 0) {}

		// i�� 0�� °�϶� �ƹ��͵� �������Ƿ� 1�� ���Ͽ� ���
		else if ((i + 1) % m_size == 0) {
			cout << endl;
		}
		*/
	}
}

// ���� ã�� ��� �Լ�
void Compare::Root(int count)
{
	using std::cout;
	using std::endl;
	using std::vector;

	int point_size = 0;
	int tempx, tempy; // ������ �����Ͽ� �켱������ ���� ����
	int vecSize = 0;

	const int POINT = 2147483647; // POINT : �����ؾ� �ϴ� ������
	const int ROOT = 2147483646; // ROOT : ������ ��
	const int START = 2147483645; // START : ���� ����
	const int END = 2147483644; // END : ���� ����
	const int OVER = 2147483640; // ���� ��� ��� ����

	bool endpos = false; // ��ġ�� ���� �����̸� ���� �ݺ���
	bool trueEND = false; // m_pos�� ����� ������ ������ ��� true

	bool searchRX = false; // x�� ������ �̵�
	bool searchLX = false; // x�� ���� �̵�
	bool searchRY = false; // y�� ������ �̵�
	bool searchLY = false; // y�� ���� �̵�

	SetMap();

	// ������, �������� �������� �����ϴ� ���� POINT�� �� �����̴�.
	// ���� ���͸�ŭ �ݺ��Ѵ�.
	for (int i = 0; i < m_VposSize; i++)
	{
		endpos = false;
		if (trueEND) {
			break;
		}
		// ���� ũ�⸸ŭ ���� ã�ƾ� �� �� �ִ�. ���� �� ��üũ�� ��ŭ �ݺ��ϵ� END�� ������ break
		for (int j = 0; j < (m_size * m_size); j++)
		{
			if (endpos || trueEND) {
				break;
			}
			// 0�� ����� ������� ���� ��ȸ�ؾ� �Ѵ� ���� �������� ������ش�.
			// x�� 0���� ���� ��� �����Ѵ�.
			if (m_Vpos[i].y > 0 && m_Vpos[i].x < 0)
			{
				tempx = m_Vpos[i].x * (-1);

				// y�� ������ ��
				if (m_Vpos[i].y < 0)
				{
					tempy = m_Vpos[i].y * (-1);

					// x, y�� �����̰� x�� y���� �����Ƿ� x ��ǥ���� �̵��Ѵ�.
					if (tempx != 0 && (tempx < tempy))
					{
						searchRX = false;
						searchLX = true;
						searchRY = false;
						searchLY = false;
					}

					// x, y�� �����̰� y�� x���� �����Ƿ� y ��ǥ���� �̵��Ѵ�.
					else if (tempy != 0 && (tempx > tempy))
					{
						searchRX = false;
						searchLX = false;
						searchRY = false;
						searchLY = true;

					}

					// ���� ���ٸ� �������� �̵��Ѵ�.
					else
					{
						searchRX = false;
						searchLX = true;
						searchRY = false;
						searchLY = false;
					}
				}

				// y�� 0���� Ŭ ���
				else
				{
					tempy = m_Vpos[i].y;


					// x�� ���� y�� ����̰� x�� ���� �� x ��ǥ���� �̵�
					if (tempx != 0 && (tempx < tempy))
					{
						searchRX = false;
						searchLX = true;
						searchRY = false;
						searchLY = false;
					}

					// x�� ���� y�� ����̰� y�� ���� �� y ��ǥ���� �̵�
					else if (tempy != 0 && (tempx > tempy))
					{
						searchRX = false;
						searchLX = false;
						searchRY = false;
						searchLY = true;

					}

					// ���� ���ٸ� �������� �̵��Ѵ�.
					else
					{
						searchRX = false;
						searchLX = true;
						searchRY = false;
						searchLY = false;
					}
				}
			}

			// y�� ���� x�� ����� ��
			else if (m_Vpos[i].x > 0 && m_Vpos[i].y < 0)
			{
				tempy = m_Vpos[i].y * (-1);


				tempx = m_Vpos[i].x;


				// x�� ����̹Ƿ� x +��ǥ �̵�
				if (tempx != 0 && (tempx < tempy))
				{
					searchRX = true;
					searchLX = false;
					searchRY = false;
					searchLY = false;
				}

				// y�� ���� �̹Ƿ� -��ǥ �̵�
				else if (tempy != 0 && (tempx > tempy))
				{
					searchRX = false;
					searchLX = false;
					searchRY = false;
					searchLY = true;

				}

				// ���� ���ٸ� ���������� �̵��Ѵ�.
				else
				{
					searchRX = true;
					searchLX = false;
					searchRY = false;
					searchLY = false;
				}

			}
			/*
			// y�� 0�̰� x�� �����϶�
			else if (m_Vpos[i].y < 0)
			{
			searchRX = false;
			searchLX = true;
			searchRY = false;
			searchLY = false;
			}

			// x�� 0�̰� y�� �����϶�
			else if (m_Vpos[i].y < 0)
			{
				searchRX = false;
				searchLX = false;
				searchRY = false;
				searchLY = true;
			}*/

			// �Ѵ� ����� x�� ������
			else if ((m_Vpos[i].y != 0) && (m_Vpos[i].x != 0) && (m_Vpos[i].x < m_Vpos[i].y))
			{
				searchRX = true;
				searchLX = false;
				searchRY = false;
				searchLY = false;

			}

			// �Ѵ� ����� y�� ������
			else if ((m_Vpos[i].y != 0) && (m_Vpos[i].x != 0) && (m_Vpos[i].x > m_Vpos[i].y))
			{
				searchRX = false;
				searchLX = false;
				searchRY = true;
				searchLY = false;
			}

			// x�� 0�϶�
			else if (m_Vpos[i].x == 0)
			{
				// y�� 0���� ���� ��
				if (m_Vpos[i].y < 0)
				{
					searchRX = false;
					searchLX = false;
					searchRY = false;
					searchLY = true;
				}
				else
				{
					searchRX = false;
					searchLX = false;
					searchRY = true;
					searchLY = false;
				}
			}

			// y�� 0�϶�
			else if (m_Vpos[i].y == 0)
			{
				// x�� 0���� ���� ��
				if (m_Vpos[i].x < 0)
				{
					searchRX = false;
					searchLX = true;
					searchRY = false;
					searchLY = false;
				}
				else
				{
					searchRX = true;
					searchLX = false;
					searchRY = false;
					searchLY = false;
				}
			}

			// �Ѵ� ����� ���� ��
			else
			{
				searchRX = true;
				searchLX = false;
				searchRY = false;
				searchLY = false;

			}

			static int tx = m_pos[point_size].x; // �Է� ���� x�� static���� ���� �߱� ������ if�� �������� ���� �Ǿ �ʱ�ȭ ���� ����
			static int ty = m_pos[point_size].y; // �Է� ���� y �� static���� ���� �߱� ������ if�� �������� ���� �Ǿ �ʱ�ȭ ���� ����

			while (true)
			{
				if (m_Vpos[vecSize].x == OVER) {
					trueEND = true;
					break;
				}
				// m_map�� x���� START, END, ROOT�� �ƴϰ� searchRX�� ���϶� ����
				if (searchRX && (m_map[ty][tx].x != POINT || m_map[ty][tx].x != END || m_map[ty][tx].x != ROOT))
				{
					// Ž���ϴٰ� ���⺤�Ͱ� ��� 0�̵Ǹ� ����Ʈ�� ���� ���̱� ������ �̸� START�� �ٲ��ش�.
					if (m_Vpos[vecSize].x == 0 && m_Vpos[vecSize].y == 0) {
						endpos = true;
						break;
					}

					else if ((m_Vpos[m_VposSize - 1].x == 0) && (m_Vpos[m_VposSize - 1].y == 0))
					{
						trueEND = true;
						break;
					}

					// x�� �������� ���� ���� ��� ������
					else if (m_Vpos[vecSize].x == 0) {
						searchRX = false;
						break;
					}

					else
					{
						// Ž���ϴٰ� END�� ������ �Է� ������ �� �̱� ������ �ݺ����� ����������.
						if (m_map[ty][++tx].x == END) {
							trueEND = true;
							break;
						}
						m_map[ty][tx].x = ROOT;
						m_map[ty][tx].y = ROOT;
						m_Vpos[vecSize].x -= 1;
					}
				}
				else if (searchLX && (m_map[ty][tx].x != POINT || m_map[ty][tx].x != END || m_map[ty][tx].x != ROOT))
				{
					// Ž���ϴٰ� ���⺤�Ͱ� ��� 0�̵Ǹ� ����Ʈ�� ���� ���̱� ������ �̸� START�� �ٲ��ش�.
					if (m_Vpos[vecSize].x == 0 && m_Vpos[vecSize].y == 0) {
						endpos = true;
						break;
					}

					else if ((m_Vpos[m_VposSize - 1].x == 0) && (m_Vpos[m_VposSize - 1].y == 0))
					{
						trueEND = true;
						break;
					}

					else if (m_Vpos[vecSize].x == 0) {
						searchLX = false;
						break;
					}

					else
					{
						// Ž���ϴٰ� END�� ������ �Է� ������ �� �̱� ������ �ݺ����� ����������.
						if (m_map[ty][--tx].x == END)
						{
							trueEND = true;
							break;
						}
						m_map[ty][tx].x = ROOT;
						m_map[ty][tx].y = ROOT;
						m_Vpos[vecSize].x += 1;
					}
				}
				else if (searchRY && (m_map[ty][tx].y != POINT || m_map[ty][tx].y != END || m_map[ty][tx].y != ROOT))
				{
					// Ž���ϴٰ� ���⺤�Ͱ� ��� 0�̵Ǹ� ����Ʈ�� ���� ���̱� ������ �̸� START�� �ٲ��ش�.
					if (m_Vpos[vecSize].x == 0 && m_Vpos[vecSize].y == 0)
					{
						endpos = true;
						break;
					}

					else if ((m_Vpos[m_VposSize - 1].x == 0) && (m_Vpos[m_VposSize - 1].y == 0))
					{
						trueEND = true;
						break;
					}

					else if (m_Vpos[vecSize].y == 0)
					{
						searchRY = false;
						break;
					}


					else
					{
						// Ž���ϴٰ� END�� ������ �Է� ������ �� �̱� ������ �ݺ����� ����������.
						if (m_map[++ty][tx].x == END) {
							trueEND = true;
							break;
						}
						m_map[ty][tx].x = ROOT;
						m_map[ty][tx].y = ROOT;
						m_Vpos[vecSize].y -= 1;
					}
				}
				else if (searchLY && (m_map[ty][tx].y != POINT || m_map[ty][tx].y != END || m_map[ty][tx].y != ROOT))
				{
					// Ž���ϴٰ� ���⺤�Ͱ� ��� 0�̵Ǹ� ����Ʈ�� ���� ���̱� ������ �̸� START�� �ٲ��ش�.
					if (m_Vpos[vecSize].x == 0 && m_Vpos[vecSize].y == 0)
					{
						endpos = true;
						break;
					}

					else if ((m_Vpos[m_VposSize - 1].x == 0) && (m_Vpos[m_VposSize - 1].y == 0))
					{
						trueEND = true;
						break;
					}

					else if (m_Vpos[vecSize].y == 0)
					{
						searchLY = false;
						break;
					}

					else
					{
						if (m_map[--ty][tx].x == END)
						{
							trueEND = true;
							break;
						}
						m_map[ty][tx].x = ROOT;
						m_map[ty][tx].y = ROOT;
						m_Vpos[vecSize].y += 1;
					}
				}
				else
				{
					cout << "���� ���� ��Ʈ" << endl;
					endpos = true;
				}
				/*if (pass == false) {
					pass = true;
					continue;
				}*/
				if ((m_Vpos[point_size].x == 0) && (m_Vpos[point_size].y == 0)) {
					m_map[ty][tx].x = START;
					m_map[ty][tx].y = START;

					point_size++;
					vecSize++;
					endpos = true;
					break;
				}
				//pass = false;
			}
		}
	}
}




// ���� ���� ��� �Լ�
void Compare::ColorPrint(int color)
{
	char mark;
	using std::cout;
	switch (color)
	{
		// �Է� ���� ���� ���
	case WHITE:
		mark = 88;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (color << 4));
		cout << "| " << mark << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE | BLACK);
		break;

		// ������ ��
	case GREEN:
		mark = 42;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (color << 4));
		cout << "| " << mark << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE | BLACK);
		break;

		// �������� �ϴ� ��ǥ
	case BLUE:
		mark = 79;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (color << 4));
		cout << "| " << mark << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE | BLACK);
		break;

		// �� �������� ���� ����
	case BLACK:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE | BLACK);
		break;

	default:
		break;
	}
}

void Compare::Print()
{
	using std::cout;
	using std::endl;
	const int POINT = 2147483647; // POINT : �����ؾ� �ϴ� ������
	const int ROOT = 2147483646; // ROOT : ������ ��
	const int START = 2147483645; // START : ���� ����
	const int END = 2147483644; // END : ���� ����

	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			if (m_map[i][j].x == START || m_map[i][j].x == POINT || m_map[i][j].x == END) {
				ColorPrint(BLUE);
			}
			else if (m_map[i][j].x == ROOT)
			{
				ColorPrint(GREEN);
			}
			else
			{
				ColorPrint(WHITE);
			}
		}
		cout << endl;
	}
	ColorPrint(BLACK);
}
/*
// ������ ���� ����ü
bool cmp(Vec2D p1, Vec2D p2)
{
	if ((p1.x + p1.y) == (p2.x + p2.y)) {
		return (p1.x + p1.y) < (p2.x + p2.y);
	}

	else if ((p1.x + p1.y) < (p2.x + p2.y))
	{
		return (p1.x + p1.y) < (p2.x + p2.y);
	}

	else if ((p1.x + p1.y) > (p2.x + p2.y))
	{
		return (p1.x + p1.y) > (p2.x + p2.y);
	}

	else
	{
		return (p1.x + p1.y) < (p2.x + p2.y);

	}
}*/