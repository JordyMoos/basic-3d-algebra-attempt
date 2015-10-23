
#include <iostream>
#include <cmath>

class Vector3
{
public:
	float x, y, z;

public:
	Vector3();
	Vector3(float x, float y, float z);

	friend std::ostream& operator<<(std::ostream& os, const Vector3& vec);

public:

	float getLength();
	void calculateUnit(Vector3& out);
};

Vector3::Vector3()
	: x(.0f), y(.0f), z(.0f)
{}

Vector3::Vector3(float x, float y, float z)
	: x(x), y(y), z(z)
{}

// Magnitude
float Vector3::getLength()
{
	return std::sqrt(std::pow(x, 2) +  std::pow(y, 2) + std::pow(z, 2));
}

// Create a normalized version
void Vector3::calculateUnit(Vector3& out)
{
	float magnitude = getLength();

	out.x = x / magnitude;
	out.y = y / magnitude;
	out.z = z / magnitude;
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
	std::cout << std::endl;

	Vector3 unit = Vector3();
	vec.calculateUnit(unit);

	std::cout << unit << std::endl;
	std::cout << "Magnitude: " << unit.getLength() << std::endl;

	system("pause");
}

