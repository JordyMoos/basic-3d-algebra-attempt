
#include <iostream>
#include <cmath>
#include <memory>

const float EPSILON = 0.001f;

class Vector3
{
public:
	float x, y, z;

public:
	Vector3();
	Vector3(const Vector3& vec);
	Vector3(float x, float y, float z);

	friend std::ostream& operator<<(std::ostream& os, const Vector3& vec);

public:
	float getLength();
	Vector3& calculateUnit(Vector3& out);
	std::shared_ptr<Vector3> newUnit();
	Vector3 getUnit();

	Vector3 operator + (const Vector3& rhs) const;
	Vector3 operator - (const Vector3& rhs) const;
	Vector3 operator * (float scale) const;
	Vector3 operator / (float scale) const;

	bool operator == (const Vector3& rhs) const;
	bool operator != (const Vector3& rhs) const;

private:
	bool equals(float lhs, float rhs) const;
};

Vector3::Vector3()
	: x(.0f), y(.0f), z(.0f)
{}

Vector3::Vector3(const Vector3& vec)
	: x(vec.x), y(vec.y), z(vec.z)
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
Vector3& Vector3::calculateUnit(Vector3& out)
{
	float magnitude = getLength();

	out.x = x / magnitude;
	out.y = y / magnitude;
	out.z = z / magnitude;

	return out;
}

// Normalize the hard way (should not be here but its fun for test)
std::shared_ptr<Vector3> Vector3::newUnit()
{
	std::shared_ptr<Vector3> unit(new Vector3);
	calculateUnit(*unit);

	return unit;
}

// This version will call the constructor and copy constructor
Vector3 Vector3::getUnit()
{
	Vector3 unit = Vector3(); // Constructor
	calculateUnit(unit);

	return unit; // Copy constructor
}

Vector3 Vector3::operator + (const Vector3& rhs) const
{
	return Vector3( x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3 Vector3::operator - (const Vector3& rhs) const
{
	return Vector3( x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3 Vector3::operator * (float scale) const
{
	return Vector3(x * scale, y * scale, z * scale);
}

Vector3 Vector3::operator / (float scale) const
{
	const float rscale = 1.f / scale;
	return Vector3(x * rscale, y * rscale, z * rscale);
}

bool Vector3::equals(float lhs, float rhs) const
{
	return fabs(lhs - rhs) < EPSILON;
}

bool Vector3::operator == (const Vector3& rhs) const
{
	return equals(x, rhs.x)
		&& equals(y, rhs.y)
		&& equals(z, rhs.z);
}

bool Vector3::operator != (const Vector3& rhs) const
{
	return !operator==(rhs);
}

// Befriended write vector to stream operation
std::ostream& operator<<(std::ostream& os, const Vector3& vec)
{
	os << "(" << vec.x << "," << vec.y << "," << vec.z << ")";

	return os;
}

int main(int argc, char* argv[])
{
	Vector3 vec = Vector3(1, 2, 3);
	Vector3 vec2 = Vector3(2, 3, 4);

	Vector3 vec3 = vec + vec2;

	std::cout << "Vec: " << vec << std::endl;
	std::cout << "Vec2: " << vec2 << std::endl;
	std::cout << "Vec3: " << vec3 << std::endl;
	std::cout << "Vec2: " << (vec3 - vec) << std::endl;
	std::cout << std::endl;

	std::cout << "Vec1 Magnitude: " << vec.getLength() << std::endl;
	std::cout << std::endl;

	Vector3 unit = Vector3();
	vec.calculateUnit(unit);

	std::cout << vec.calculateUnit(unit) << std::endl;
	std::cout << "Unit Magnitude: " << unit.getLength() << std::endl;
	std::cout << std::endl;

	auto unit2 = vec.newUnit();

	std::cout << (*unit2) << std::endl;
	std::cout << "Unit Magnitude: " << unit2->getLength() << std::endl;
	std::cout << std::endl;

	Vector3 unit3 = vec.getUnit();

	std::cout << unit3 << std::endl;
	std::cout << "Unit Magnitude: " << unit3.getLength() << std::endl;
	std::cout << std::endl;

	std::cout << "Equal check:" << std::endl;
	std::cout << "vec==vec2: " << (vec == vec2) << std::endl;
	std::cout << "vec!=vec2: " << (vec != vec2) << std::endl;
	std::cout << "unit==unit3: " << (unit == unit3) << std::endl;
	std::cout << "unit!=unit3: " << (unit != unit3) << std::endl;
	std::cout << std::endl;

	Vector3 vec4 = Vector3(2, 2, 2);
	Vector3 multiplied = vec4 * 2.0f;
	Vector3 divided = multiplied / 2.0f;
	std::cout << "Vec4: " << vec4 << std::endl;
	std::cout << "Vec4 * 2: " << multiplied << std::endl;
	std::cout << "(Vec4 * 2) / 2: " << divided << std::endl;

	system("pause");
}
