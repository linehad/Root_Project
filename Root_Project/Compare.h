#pragma once
#include<vector>
#include <string>

/*
알고리즘 전체 구상

1. 배열 크기는 int로 좌표는 string으로 파싱한다.(완료)
2. getline 또는 get을 사용하여 엔터를 칠 경우 입력이 종료되게끔한다.(완료)
3. 입력은 좌표의 전체 크기 만큼 받을 수 있다.(완료 = 중복값이 생길 수도 있다. 중복 벡터 제거 필요)(완료)
4. 입력 받은 좌표가 작은 것부터 가장 가까운 순서대로 정렬한다(완료)
5. 좌표를 표시할 보드에서 입력 받은 좌표를 특정할 수 있는 값으로 만든다.(완료 POINT로 지정함)
6. 정렬 받은 바로 다음 좌표와 현재 좌표를 빼서 방향벡터에 저장한다. 이것은 다음 이동할 좌표의 이정표가 된다.(완료)
7. x좌표와 y좌표를 비교한다. x가 y보다 작다면 x 축으로 먼저 이동한다. 반대로 y가 x보다 작다면 y축으로 먼저 이동한다.(완료)
8. 만약 x와 y가 같다면 x 좌표먼저 탐색한다.(완료)
9. x좌표 먼저 탐색한다고 가정하면 방향 벡터의 x값이 0이 될때까지 +1씩 혹은 -1씩 이동하여 0이 되는 순간 y좌표를 탐색한다.(완료)
10. y좌표 먼저 탐색한다면 위와 반대로 한다.(완료)
11. 좌표를 탐색할 때 마다 방향벡터에 0과 가까운 쪽으로 +1 또는 -1을 가산한다. x, y값 모두 0이 되었다면 목적지에 도달한 것이다.(완료)
12. 목적지에 도달하면 다음 방향벡터가 있는지 검사한다. 다음 벡터가 있다면 현재 목적지를 시작점으로 바꾸고 정렬된 다음 포인트를 도착지로 바꾼다.(완료)
13. 이를 방향 벡터의 다음 값이 없을 때까지 반복한다.(완료)
*/


enum Coler
{
	WHITE = 15, GREEN = 10, BLUE = 9, BLACK = 0
};

// 벡터 객체를 저장하고 좌표를 빼주는 연산을 담당하는 클래스
class Vec2D {

public:
	int x;
	int y;


	Vec2D() { x = 2147483640; y = 2147483640; } // 만약 입력되지 않은 값이 들어 갈 경우 int형 최댓값으로 초기화 하여 정렬시 문제가 없도록 한다.
	Vec2D(int x, int y);
	Vec2D operator -(const Vec2D& other) { return Vec2D(this->x - other.x, this->y - other.y); }
	Vec2D operator +(const Vec2D& other) { return Vec2D(this->x + other.x, this->y + other.y); }
	bool operator <(Vec2D& other) { return this->x < other.x; }
	bool operator >(Vec2D& other) { return this->x > other.x; }
	bool operator ==(Vec2D& other) { return this->x == other.x && this->y == other.y; }
	//bool operator ==(const Vec2D& other) { return bool((this->x == other.x) || (this->y == other.y)); }
	std::ostream& operator <<(const Vec2D& other) { return std::cout << other.x << ", " << other.y; }
};

// Coordinate를 상속받아 입력 받은 좌표를 실제로 계산하는 클래스
class Compare {
private:
	int count; // 입력받은 벡터의 개수
	int m_size; // 벡터의 전체 크기
	int m_posSize; // m_pos의 크기 정렬한 좌표값을 읽을때 쓰인다.
	int m_VposSize; // m_Vpos의 좌표값을 읽을때 쓰인다.

	std::vector<std::vector<Vec2D> > m_map; // 맵이 저장될 벡터
	std::vector<Vec2D> m_pos; // 좌표가 저장될 벡터
	std::vector<Vec2D> m_Vpos; // 좌표끼리 뺄셈하여 방향 및 위치를 알려줄 벡터
public:

	Compare(int size);
	~Compare();
	// size, string 값을 받아 정렬하고 count값을 돌려주는 멤버 함수
	int Sort(std::string);

	void SetMap();
	void Root(int count);
	//void Bfs(int x, int y);
	void ColorPrint(int); // 
	void Print(); // 맵 프린트 함수
};

// 정렬을 위한 비멤버 함수
//bool cmp(Vec2D& p1, Vec2D& p2);