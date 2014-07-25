#ifndef OP_H
#define OP_H

/* what is faster: with conditions or without? */

/*
 * Redefinitions of standard C/C++ operations
 * which aren't correct for negative values.
 */
template <typename T>
inline T _mod(const T &num, const T &den)
{
	const bool neg = num < 0;
	return ((num + neg) % den) + neg*(den - 1);
	// return (num<0)?(((num+1)%den)+den-1):(num%den);
}
template <typename T>
inline T _div(const T &num, const T &den)
{
	const bool neg = num < 0;
	return ((num + 1)/den) - neg;
	// if(den<0){num=-num;den=-den;}
	// return (num<0)?(((num+1)/den)-1):(num/den);
}
template <typename T>
inline int _divmod(T &num, const T &den)
{
	T ret = _div(num,den);
	num = _mod(num,den);
    return ret;
}

/* min max without conditional */
template <typename T>
inline constexpr T _min(const T &a, const T &b)
{
	return a + (b - a)*(a > b);
}
template <typename T>
inline constexpr T _max(const T &a, const T &b)
{
	return a + (b - a)*(a < b);
}

/* signum operation */
template <typename T>
inline constexpr int _sgn(T arg)
{
	return static_cast<int>(static_cast<T>(0) < arg) - static_cast<int>(arg < static_cast<T>(0));
}



#endif // OP_H
