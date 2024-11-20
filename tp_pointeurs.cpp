#include <iostream>
#include <string>

using namespace std;

int main() {
    // On declare la phrase initialisée
    string phrase_string = "Les optimistes pensent que nous vivons dans le meilleur des mondes possibles, les pessimistes en sont intimement persuades.";
    char phrase_tableau[] = "Les optimistes pensent que nous vivons dans le meilleur des mondes possibles, les pessimistes en sont intimement persuades.";
    const char* phrase_pointeur = "Les optimistes pensent que nous vivons dans le meilleur des mondes possibles, les pessimistes en sont intimement persuades.";

    // On affiche des adresses pour std::string
    cout << "string:" << endl;
    cout << "Adresse de la variable phrase_string: " << &phrase_string << endl;
    for (size_t i = 0; i < phrase_string.size(); ++i) {
        cout << "Adresse de phrase_string[" << i << "]: " << static_cast<const void*>(&phrase_string[i]) << " - Caractère: " << phrase_string[i] << endl;
    }

    // On affiche ls adresses pour le tableau de caractères
    cout << "Tableau de char:" << endl;
    cout << "Adresse de la variable phrase_tableau: " << static_cast<const void*>(phrase_tableau) << endl;
    for (size_t i = 0; i < sizeof(phrase_tableau) - 1; ++i) {
        cout << "Adresse de phrase_tableau[" << i << "]: " << static_cast<const void*>(&phrase_tableau[i]) << " - Caractère: " << phrase_tableau[i] << endl;
    }

    // On affiche les adresses pour le pointeur sur char
    cout << "Pointeur sur char:" << endl;
    cout << "Adresse de la variable phrase_pointeur: " << static_cast<const void*>(phrase_pointeur) << endl;
    for (size_t i = 0; phrase_pointeur[i] != '\0'; ++i) {
        cout << "Adresse de phrase_pointeur[" << i << "]: " << static_cast<const void*>(&phrase_pointeur[i]) << " - Caractère: " << phrase_pointeur[i] << endl;
    }

    return 0;
}
