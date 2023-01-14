// nombreMystere.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	 int nombreATrouve;
	int nombreTrouve;
	cout << "rentre le nombre que tu veux faire trouver " << endl;
	cin>>nombreATrouve;
	for (int i = 0; i < 200; i++) {

		cout << "ne remonte pas" << endl;
	}
	cout << "rentre le nombre que tu as a trouver" << endl;
	cin >> nombreTrouve;
	while (nombreATrouve != nombreTrouve)
	{
		


		if(nombreATrouve>nombreTrouve){
			cout << "PLUS GRAND" << endl;
			cin >> nombreTrouve;
		}
		else {

			cout << "PLUS PETIT" << endl;
			cin >> nombreTrouve;
		  }
			


	}
	cout << "Bravo t'as gagne" << endl;


}


