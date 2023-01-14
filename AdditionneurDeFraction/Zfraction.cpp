#include<iostream>
#include"Zfraction.h"
using namespace std;

Zfraction::Zfraction():m_numerateur(1),m_denominateur(1)
{

}

Zfraction::Zfraction(int numerateur, int denominateur) :m_numerateur(numerateur), m_denominateur(denominateur)
{

}

int Zfraction::getdeno()const
{
	
	
	
	
	return m_denominateur;
}

int Zfraction::getdenom() const
{
	return m_denominateur;
}

int Zfraction::getnume()const
{
	return m_numerateur;
}


Zfraction& Zfraction::operator+=( Zfraction& fraction)
{
	if((*this).m_denominateur==(*this).m_numerateur)
	
	{
		fraction.m_numerateur += fraction.m_denominateur;
		*this = fraction;
			return *this;
		


	}
	else if ((*this).m_denominateur == (*this).m_numerateur && fraction.m_denominateur == fraction.m_numerateur)
	
	{
		Zfraction azerty(2,1);
		return azerty;


	}

	else if (fraction.m_denominateur == fraction.m_numerateur)
	{


		m_numerateur += m_denominateur;
		return *this;


	}

	else if (( * this).m_denominateur != (fraction).m_denominateur)
	{
		int deno = m_denominateur;
		
		m_numerateur *= fraction.m_denominateur;
		m_denominateur *= fraction.m_denominateur;
		fraction.m_numerateur *= deno;
		fraction.m_denominateur *= deno;
		m_numerateur = m_numerateur + fraction.m_numerateur;
		Zfraction truc(m_numerateur, m_denominateur);
		*this = truc;
		

	}
	else 
	{
		(*this).m_numerateur += fraction.m_numerateur;


	}

	return *this;
}

Zfraction& Zfraction::operator=(Zfraction& fract)
{
	m_denominateur = fract.m_denominateur;
	m_numerateur = fract.m_numerateur;
	return *this;
}




void Zfraction::simplifier()
{
	int nombre = pgcd(m_numerateur, m_denominateur);
	m_numerateur /= nombre;
	m_denominateur /= nombre;

}



std::ostream& operator<<(std::ostream& flux, const Zfraction& Fraction)
{

	flux << Fraction.m_numerateur << "/" << Fraction.m_denominateur;
	return flux;
}

std::istream& operator>>(std::istream& fluxin, Zfraction& Fractionaz)
{
	fluxin >> Fractionaz.m_numerateur; fluxin >> Fractionaz.m_denominateur;
		 
	
	return fluxin;
}

int pgcd(int a, int b)
{
	while(b!=0)
	{
		const int t = b;
		b = a % b;
		a = t;
	}
	
	
	return a;
}


