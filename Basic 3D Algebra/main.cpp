
#include <iostream>

class Vector3
{
private:
	float x, y, z;

public:
	Vector3(float x, float y, float z)
		: x(x), y(y), z(z)
	{}

	friend std::ostream& operator<<(std::ostream& os, const Vector3& vec);
};

std::ostream& operator<<(std::ostream& os, const Vector3& vec)
{
	os << "(" << vec.x << "," << vec.y << "," << vec.z << ")";

	return os;
}

int main(int argc, char* argv[])
{
	Vector3 vec = Vector3(1, 2, 3);

	std::cout << vec << std::endl;

	system("pause");
}

