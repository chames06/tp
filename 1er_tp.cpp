#include <iostream>
#include <string>

using namespace std;

int main()
{
    string bibliotheque_systeme = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string bibliotheque_utilisateur;
    string mot_de_passe = "";
    int longueur_mot_de_passe;
    bool valide = true;

    cout << "Entrez les caracteres que vous voulez utiliser pour composer votre mot de passe:";
    cin >> bibliotheque_utilisateur;

    // Verifier si chaque caractere de la bibliotheque utilisateur est dans la bibliotheque systeme
    for (char c : bibliotheque_utilisateur) {
        if (bibliotheque_systeme.find(c) == string::npos) {
            valide = false;
            break;
        }
    }

    if (!valide) {
        cout << "Votre bibliotheque contient des caracteres non autorises" << endl;
        return 1;
    }

    cout << "Entrez la longueur du mot de passe a generer: ";
    cin >> longueur_mot_de_passe;

    for (int i = 0; i < longueur_mot_de_passe; i++) {
        int index = (i * 3 + 7) % bibliotheque_utilisateur.length();
        mot_de_passe += bibliotheque_utilisateur[index];
    }

    cout << "Mot de passe genere: " << mot_de_passe << endl;

    return 0;
}
