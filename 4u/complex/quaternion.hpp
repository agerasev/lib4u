#pragma once
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
		data[0] = static_cast<complex<T>>(a);
		data[1] = static_cast<complex<T>>(0);
	}
	template <typename S>
	complex(const S &a, const S &b)
	{
		data[0] = static_cast<complex<T>>(a);
		data[1] = static_cast<complex<T>>(b);
	}
	complex(const T &a, const T &b, const T &c, const T &d)
	{
		data[0] = complex<T>(a,b);
		data[1] = complex<T>(c,d);
	}
	template <typename S>
	complex(const complex<S> &c)
	{
		data[0] = static_cast<complex<T>>(c.data[0]);
		data[1] = static_cast<complex<T>>(c.data[1]);
	}

	T &r()
	{
		return data[0].data[0];
	}
	T &i()
	{
		return data[0].data[1];
	}
	T &j()
	{
		return data[1].data[0];
	}
	T &k()
	{
		return data[1].data[1];
	}
	T r() const
	{
		return data[0].data[0];
	}
	T i() const
	{
		return data[0].data[1];
	}
	T j() const
	{
		return data[1].data[0];
	}
	T k() const
	{
		return data[1].data[1];
	}

	complex<T> &re()
	{
		return data[0];
	}
	complex<T> &im()
	{
		return data[1];
	}
	complex<T> re() const
	{
		return data[0];
	}
	complex<T> im() const
	{
		return data[1];
	}
};

template <typename T>
typedef complex<complex<T>> quaternion<T>;

/* Normalizing operation */
template <typename T>
T abs2(const quaternion<T> &c)
{
	return c.r()*c.r() + c.i()*c.i() + c.j()*c.j() + c.k()*c.k();
}

template <typename T>
T abs(const quaternion<T> &c)
{
	return sqrt(abs2(c));
}

typedef quaternion<double> qdouble;
typedef quaternion<float> qfloat;
typedef quaternion<int> qint;
