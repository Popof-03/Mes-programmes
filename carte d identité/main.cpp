#include <iostream>
#include <string>
#include <ctime>



using namespace std;

int main()
{
	string nomPrénomUtilisateur("sans nom");
	char sexe;
	string dateDeNaissance;
	string annee;
	string mois;
	string jour;
	string dateN;
	unsigned long long int tempsEcouleJusquaNaissance;
	





	cout << "veuillez renseigner votre nom puis votre prenom" << endl;
	getline(cin, nomPrénomUtilisateur);

	do
	{
		cout << "veuillez renseigner votre sexe, F pour femme et H pour homme" << endl;
		cin >> sexe;
	} while (sexe != 'F' && sexe != 'H');
	cin.ignore();
	{
		cout << "veuillez renseigner votre date de naissance" << endl;

		getline(cin, jour, '/');
		getline(cin, mois, '/');
		getline(cin, annee);
		//std::cout << jour << " " << mois << " " << annee << endl;
		int jours = std::stoi(jour);
		int nbmois = std::stoi(mois);
		unsigned long long int annees = std::stoi(annee);
		annees *= 31536000;
		nbmois *= 2628000;
		jours *= 86400;
		tempsEcouleJusquaNaissance = nbmois + annees + jours;
		//std::cout << tempsEcouleJusquaNaissance << endl;
		unsigned long long int tempsActuel = time(0) + unsigned long long int(1970) * 31536000;
		//std::cout << tempsActuel << endl;
		unsigned long long int ageEnSeconde = tempsActuel - tempsEcouleJusquaNaissance;
		//std::cout << ageEnSeconde;
		double ageblaBla = ageEnSeconde / 31536000;
		std::cout << "ton age est " << ageblaBla << endl;
		





		




	}

	


	return 0;
};
