#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string const nomFichier("sheesh");
    ofstream monFlux(nomFichier.c_str());

    if(monFlux)    
    {
        monFlux << "Bonjour, je suis une phrase écrite dans un fichier." << endl;
        monFlux << 42.1337 << endl;
        int age(36);
        monFlux << "J'ai " << age << " ans." << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    return 0;
}