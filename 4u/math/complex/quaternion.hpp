#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include"complex.hpp"

template <typename T>
class complex<complex<T>>
{
private:
	complex<T> data[2];

public:
	complex()
	{

	}
	template <typename S>
	complex(const S &a)
	{
		data[0] = static_cast<T>(a);
		data[1] = static_cast<T>(0);
	}
	template <typename S>
	complex(const S &a, const S &b)
	{
		data[0] = static_cast<T>(a);
		data[1] = static_cast<T>(b);
	}
	template <typename S>
	complex(const complex<S> &c)
	{
		data[0] = static_cast<T>(c.data[0]);
		data[1] = static_cast<T>(c.data[1]);
	}

	inline constexpr T &r()
	{
		return data[0];
	}
	inline constexpr T &i()
	{
		return data[1];
	}
	inline constexpr T &j()
	{
		return data[0];
	}
	inline constexpr T &k()
	{
		return data[1];
	}
};

template <typename T>
typedef complex<comlex<T>> quaternion<T>;

#endif // QUATERNION_HPP
