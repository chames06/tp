#include <iostream>
#include <string>

using namespace std;

int main() {
    string bibliotheque_systeme = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string bibliotheque_utilisateur;
    string mot_de_passe = "";
    int longueur_mot_de_passe;
    bool valide = false;  // variable de validation générale

    do {
        cout << "Entrez les caracteres (entre 8 et 25, sans espace) que vous voulez utiliser pour composer votre mot de passe: ";
        cin >> bibliotheque_utilisateur;

        // Vérifier la longueur de la bibliothèque utilisateur
        if (bibliotheque_utilisateur.length() < 8 || bibliotheque_utilisateur.length() > 25) {
            cout << "La longueur doit être entre 8 et 25 caracteres." << endl;
            continue;  // recommence la boucle
        }

        // Vérifier l'absence d'espace dans la bibliothèque utilisateur
        if (bibliotheque_utilisateur.find(' ') != string::npos) {
            cout << "Votre chaine ne doit pas contenir d'espaces." << endl;
            continue;  // recommence la boucle
        }

        // Vérifier si chaque caractère de la bibliothèque utilisateur est dans la bibliothèque système
        valide = true;
        for (char c : bibliotheque_utilisateur) {
            if (bibliotheque_systeme.find(c) == string::npos) {
                cout << "Votre bibliotheque contient des caracteres non autorises." << endl;
                valide = false;
                break;  // quitte la boucle `for` en cas de caractère non autorisé
            }
        }

    } while (!valide);  // boucle jusqu'à ce que toutes les conditions soient satisfaites

    cout << "Entrez la longueur du mot de passe a generer: ";
    cin >> longueur_mot_de_passe;

    // Génération du mot de passe
    for (int i = 0; i < longueur_mot_de_passe; i++) {
        int index = (i * 3 + 7) % bibliotheque_utilisateur.length();
        mot_de_passe += bibliotheque_utilisateur[index];
    }

    cout << "Mot de passe genere: " << mot_de_passe << endl;

    return 0;
}
