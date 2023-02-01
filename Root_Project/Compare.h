#pragma once
#include<vector>
#include <string>

/*
�˰��� ��ü ����

1. �迭 ũ��� int�� ��ǥ�� string���� �Ľ��Ѵ�.(�Ϸ�)
2. getline �Ǵ� get�� ����Ͽ� ���͸� ĥ ��� �Է��� ����ǰԲ��Ѵ�.(�Ϸ�)
3. �Է��� ��ǥ�� ��ü ũ�� ��ŭ ���� �� �ִ�.(�Ϸ� = �ߺ����� ���� ���� �ִ�. �ߺ� ���� ���� �ʿ�)(�Ϸ�)
4. �Է� ���� ��ǥ�� ���� �ͺ��� ���� ����� ������� �����Ѵ�(�Ϸ�)
5. ��ǥ�� ǥ���� ���忡�� �Է� ���� ��ǥ�� Ư���� �� �ִ� ������ �����.(�Ϸ� POINT�� ������)
6. ���� ���� �ٷ� ���� ��ǥ�� ���� ��ǥ�� ���� ���⺤�Ϳ� �����Ѵ�. �̰��� ���� �̵��� ��ǥ�� ����ǥ�� �ȴ�.(�Ϸ�)
7. x��ǥ�� y��ǥ�� ���Ѵ�. x�� y���� �۴ٸ� x ������ ���� �̵��Ѵ�. �ݴ�� y�� x���� �۴ٸ� y������ ���� �̵��Ѵ�.(�Ϸ�)
8. ���� x�� y�� ���ٸ� x ��ǥ���� Ž���Ѵ�.(�Ϸ�)
9. x��ǥ ���� Ž���Ѵٰ� �����ϸ� ���� ������ x���� 0�� �ɶ����� +1�� Ȥ�� -1�� �̵��Ͽ� 0�� �Ǵ� ���� y��ǥ�� Ž���Ѵ�.(�Ϸ�)
10. y��ǥ ���� Ž���Ѵٸ� ���� �ݴ�� �Ѵ�.(�Ϸ�)
11. ��ǥ�� Ž���� �� ���� ���⺤�Ϳ� 0�� ����� ������ +1 �Ǵ� -1�� �����Ѵ�. x, y�� ��� 0�� �Ǿ��ٸ� �������� ������ ���̴�.(�Ϸ�)
12. �������� �����ϸ� ���� ���⺤�Ͱ� �ִ��� �˻��Ѵ�. ���� ���Ͱ� �ִٸ� ���� �������� ���������� �ٲٰ� ���ĵ� ���� ����Ʈ�� �������� �ٲ۴�.(�Ϸ�)
13. �̸� ���� ������ ���� ���� ���� ������ �ݺ��Ѵ�.(�Ϸ�)
*/


enum Coler
{
	WHITE = 15, GREEN = 10, BLUE = 9, BLACK = 0
};

// ���� ��ü�� �����ϰ� ��ǥ�� ���ִ� ������ ����ϴ� Ŭ����
class Vec2D {

public:
	int x;
	int y;


	Vec2D() { x = 2147483640; y = 2147483640; } // ���� �Էµ��� ���� ���� ��� �� ��� int�� �ִ����� �ʱ�ȭ �Ͽ� ���Ľ� ������ ������ �Ѵ�.
	Vec2D(int x, int y);
	Vec2D operator -(const Vec2D& other) { return Vec2D(this->x - other.x, this->y - other.y); }
	Vec2D operator +(const Vec2D& other) { return Vec2D(this->x + other.x, this->y + other.y); }
	bool operator <(Vec2D& other) { return this->x < other.x; }
	bool operator >(Vec2D& other) { return this->x > other.x; }
	bool operator ==(Vec2D& other) { return this->x == other.x && this->y == other.y; }
	//bool operator ==(const Vec2D& other) { return bool((this->x == other.x) || (this->y == other.y)); }
	std::ostream& operator <<(const Vec2D& other) { return std::cout << other.x << ", " << other.y; }
};

// Coordinate�� ��ӹ޾� �Է� ���� ��ǥ�� ������ ����ϴ� Ŭ����
class Compare {
private:
	int count; // �Է¹��� ������ ����
	int m_size; // ������ ��ü ũ��
	int m_posSize; // m_pos�� ũ�� ������ ��ǥ���� ������ ���δ�.
	int m_VposSize; // m_Vpos�� ��ǥ���� ������ ���δ�.

	std::vector<std::vector<Vec2D> > m_map; // ���� ����� ����
	std::vector<Vec2D> m_pos; // ��ǥ�� ����� ����
	std::vector<Vec2D> m_Vpos; // ��ǥ���� �����Ͽ� ���� �� ��ġ�� �˷��� ����
public:

	Compare(int size);
	~Compare();
	// size, string ���� �޾� �����ϰ� count���� �����ִ� ��� �Լ�
	int Sort(std::string);

	void SetMap();
	void Root(int count);
	//void Bfs(int x, int y);
	void ColorPrint(int); // 
	void Print(); // �� ����Ʈ �Լ�
};

// ������ ���� ���� �Լ�
//bool cmp(Vec2D& p1, Vec2D& p2);