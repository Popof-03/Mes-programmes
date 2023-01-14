#ifndef ZFRACTION_H_INCLUDED
#define ZFRACTION_H_INCLUDED
#include <iostream>


class Zfraction
{
public:
	Zfraction();
	Zfraction(int numerateur, int denominateur);
	int getdeno() const;
	int getdenom()const;
	int getnume() const;
	
	Zfraction& operator+=(Zfraction& fraction);
	Zfraction& operator=(Zfraction& fract);
	

	
	 void simplifier();
	
	friend std::ostream& operator<<(std::ostream& flux, const Zfraction& Fraction);
	friend std::istream& operator>>(std::istream& fluxin,Zfraction& Fractionaz);

	
	

protected:
	int m_numerateur=0;
	int m_denominateur=0;
};
int pgcd(int a, int b);



























#endif