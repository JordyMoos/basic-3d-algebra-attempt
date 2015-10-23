
#include <iostream>
#include <cmath>

class Vector3
{
private:
	float x, y, z;

public:
	Vector3(float x, float y, float z);

	friend std::ostream& operator<<(std::ostream& os, const Vector3& vec);

public:

	float getLength();
};

Vector3::Vector3(float x, float y, float z)
	: x(x), y(y), z(z)
{}

// Magnitude
float Vector3::getLength()
{
	return std::sqrt(std::pow(x, 2) +  std::pow(y, 2) + std::pow(z, 2));
}

std::ostream& operator<<(std::ostream& os, const Vector3& vec)
{
	os << "(" << vec.x << "," << vec.y << "," << vec.z << ")";

	return os;
}

int main(int argc, char* argv[])
{
	Vector3 vec = Vector3(1, 2, 3);

	std::cout << vec << std::endl;
	std::cout << "Magnitude: " << vec.getLength() << std::endl;

	system("pause");
}

