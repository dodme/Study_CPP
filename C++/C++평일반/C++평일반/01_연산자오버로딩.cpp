#include <iostream>
using namespace std;

class Vector2D
{
private:
	int x;
	int y;

public:
	Vector2D(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}

	// Vector2D(int _x = 0, int _y = 0) : x(_x), y(_y) {}

	void PrintPosition() const
	{
		cout << "( " << x << ", " << y << " )" << endl;
	}

	// 연산자 오버로딩
	/// > 연산자에 기능을 확장시키는것
	/// > operator
	

	Vector2D operator+(int value)
	{
		return Vector2D(x + value, y + value);
	}

	Vector2D operator+=(int value)
	{
		// int num += 10;
		// int num = num + 10;
		return (*this = *this + value);
	}

	Vector2D operator++()
	{
		return(*this += 1);
	}

	Vector2D operator+(Vector2D ref)
	{
		Vector2D pos(x + ref.x, y + ref.y);
		return pos;
	}

};

int main()
{
	Vector2D point1 = Vector2D(10, 10);
	Vector2D point2 = Vector2D(20, 20);
	//Vector2D* point3 = point1 + 10;
	//		 point3 = point1 + 10;
	Vector2D point3 = point1.operator+(10);
	
	Vector2D point4 = point1.operator+(point2);
	// point4 = point1 + point2;

	point1.PrintPosition();
	point2.PrintPosition();
	point3.PrintPosition();
	point4.PrintPosition();

	int num(0);
	// int num = 0;


	return 0;
}