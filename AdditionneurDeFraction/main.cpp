

#include <iostream>
#include"Zfraction.h"
using namespace std;


int main()
{
	Zfraction Fraction1;
	Zfraction Fraction2;
	cout << "entrez le numerateur de la fraction 1,appuyer sur entrée, puis entrez le denominateur de la fraction 1 et faites pareil pour la fraction 2" << endl;
	cin >> Fraction1 >> Fraction2;
	int verificationDouble = Fraction2.getdeno();
	int verification = Fraction1.getdeno();
		

	if (verification==0 || verificationDouble == 0) 
	{
		cout << "erreur" << endl;
	}

	
	else 
	{
		cout << Fraction1 << "+" << Fraction2 << endl;
		Fraction1 += Fraction2;
		Fraction1.simplifier();
		cout << (char )(7) << endl;
		cout << "le resultat (simplifier) = " << Fraction1 << endl;
	
	}
	return 0;
}