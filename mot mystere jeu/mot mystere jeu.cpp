// mot mystere jeu.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include<string>
#include<algorithm>
#include<random>
#include<chrono>
using namespace std;

int main()
{
    string motMystereDevine("sjhqd");
    string motMystere("sjdqskqs");
   
    
   cout << "joueur 1: rentre le mot mystere(a deviner) :"<<endl;
    
   getline(cin, motMystere);
   for (int i = 0; i < 1000; i++) 
   {
       cout<<"ne remonte pas dans la fenetre"<<endl;
   }
   cout << char(7) << endl;
   
   string motMystereMelange = motMystere;
   
    
   unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
   
   std::shuffle(motMystereMelange.begin(), motMystereMelange.end(), std::default_random_engine(seed));
   
    
    for (int i = 0; i < 3; i++)
    {
        cout << "devinez le mot mystere " << motMystereMelange << endl;

        getline(cin, motMystereDevine);

        if (motMystereDevine == motMystere)

        {
            cout << "t'as gagne gg" << endl;
            break;


        }
        else
        {


            cout << "t'as perdus " << endl;
        }

        
  }
    return 0;
}



