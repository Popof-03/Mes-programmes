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
		





		//argu time Pointer to an object of type time_t, where the time value is stored.
		//Alternatively, this parameter can be a null pointer, in which case the parameter is not used(the function still returns a value of type time_t with the result).




	}

	//Parameters
	//input	-	the stream to get data from
	//str	-	the string to put the data into
	//delim	-	the delimiter character

	//cout << "renseigner d'abord l'année où vous êtes né" << endl;
			//getline(cin, annee );
			//cout << "le mois où vous êtes né " << endl;
			//getline(cin, mois);
			//cout << "le jour où vous êtes né " << endl;
			//getline(cin,jour);




	//jvais devoir me barrer g une conference a suivre a 19h jvais essayer si ta un pb envoie moi un msg avec le code qui pose pb et l'erreur j'essayerai de repondre jvais essayer de pas deranger ce sra mieux jpense hein
	//cin est un buffer souviens toi donc tu peux juste faire saisir la date  user normalement mais deriere tu recup dans 3 var distinctes ok
	//getline(stream entree,variable,delimitateur (par defaut:\n si tu veux que ca lise jusqu'a un / alors: '/' '))
	//->getline(cin,jour,'/');
	//Extracts characters from is and stores them into str until the delimitation character delim is found (or the newline character, '\n', for (2)).
	//If the delimiter is found, it is extracted and discarded (i.e. it is not stored and the next input operation will begin after it).

	//string tab[tailleTab (nb de case)]
	//tab[0]=premiere case  
	//c comme des variable sauf que au lieu d'un nom on met le nom du tableau et le numero de case bon bah jmy interresserai plus tard en attendant jvais essayer pour getline
	//tu peux passer par des variables normal si tu veux jveux apprendre a decomposer un string ca a l air important comme meca
	//bof de tt facon on bs'en sort toujours apres si tu veux pas faire des getline tu peux regarder la fonction substr qui t'extrait X charactere a partir du X^ieme character   par exemple
	//std::string str="We think in generalities, but we live in details.";
										   // (quoting Alfred N. Whitehead)

	//std::string str2 = str.substr (3,5);     // "think" 3,5 c est ... on prend 5 char a partir du 3eme okay maintenant avec le getline la jmen sors bien pour l instant?
	//le pb avec substr c que si la personne met 02/8 au lieu de 02/08 ben pour le mois tu va vouloir 3,2 et ca va te faire une erreur car ya moins de 5 char 
	//donc getline est mieux au moins t'auras tjrs un truc qui correspond ouais ok est ce que jmen sors bien pour l instant avec le getline
		  //string tab[5];//pourquoi on doit passer par std c est parce qu il veut pas autrement ? les 2 marche c'etait juste pour te montrer que c le type pas une fonction*/'
	//string tab //  c est quoi entre les ] jvois pas comment on peut mettre des string dans un tableau
	//www.cplusplus.com/reference/string/string/getline/



	return 0;
};