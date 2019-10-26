#include "Vector2D.h"

namespace Game
{
	Vector2D::Vector2D()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vector2D::Vector2D(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2D& Vector2D::Add(const Vector2D& vec)
	{
		this->x += vec.x;
		this->y += vec.y;

		return *this;
	}

	Vector2D& Vector2D::Substract(const Vector2D& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;

		return *this;
	}

	Vector2D& Vector2D::Multiply(const Vector2D& vec)
	{
		this->x *= vec.x;
		this->y *= vec.y;

		return *this;
	}

	Vector2D& Vector2D::Divide(const Vector2D& vec)
	{
		this->x /= vec.x;
		this->y /= vec.y;

		return *this;
	}

	Vector2D& Vector2D::operator+=(const Vector2D& vec)
	{
		return this->Add(vec);
	}

	Vector2D& Vector2D::operator-=(const Vector2D& vec)
	{
		return this->Substract(vec);
	}

	Vector2D& Vector2D::operator*=(const Vector2D& vec)
	{
		return this->Multiply(vec);
	}

	Vector2D& Vector2D::operator/=(const Vector2D& vec)
	{
		return this->Divide(vec);
	}

	Vector2D& operator+(Vector2D& v1, const Vector2D& v2)
	{
		return v1.Add(v2);
	}

	Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
	{
		return v1.Substract(v2);
	}

	Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
	{
		return v1.Multiply(v2);
	}

	Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
	{
		return v1.Divide(v2);
	}

	std::ostream& operator<<(std::ostream& stream, const Vector2D& vec)
	{
		return stream << "Vector2D (" << vec.x << "," << vec.y << ")";
	}
}

