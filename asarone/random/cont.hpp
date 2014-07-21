#ifndef CONT_HPP
#define CONT_HPP

#include"distrib.hpp"


class ContInt : public Distrib<unsigned int>
{
private:
	static const unsigned int LCA_A = 1103515245;
	static const unsigned int LCA_B = 12345;
	unsigned int last;
public:
	ContInt(unsigned int seed) : last(seed)
	{

	}

	virtual unsigned int get()
	{
		return last = last*LCA_A + LCA_B;
	}
};

#include<ctime>

class Cont : public Distrib<double>
{
private:
	ContInt generator;
	const double NORM_FACTOR;
public:
	Cont() :
		generator(static_cast<unsigned int>(time(nullptr))),
		NORM_FACTOR(1.0/static_cast<double>(0xffffffffu))
	{

	}

	virtual double get()
	{
		return NORM_FACTOR*generator.get();
	}
};

#endif // CONT_HPP
