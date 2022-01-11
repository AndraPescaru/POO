/*
    Programmer : Pescaru Anamaria - Andra
*/
#include <iostream>
#include <string>
#include <cstdlib>

#define NR_MAX 52
#define NR_AMESTECARI 100

class Carte {

    private:
        // Prima varianta:
        //friend class Pachet;
      
        std :: string culoare;
        std :: string valoare;

    public:
        Carte(){};
        Carte(std :: string culoare, std :: string valoare): culoare(culoare), valoare(valoare) {}
        //A doua varianta:
        std :: string get_culoare() {return culoare;}
        std :: string get_valoare() {return valoare;}
        void set_culoare(std :: string culoare) {this -> culoare = culoare;}
        void set_valoare(std :: string valoare) {this -> valoare = valoare;}

};
class Pachet {

    private:
        Carte *carti[NR_MAX];
        std :: string culori[4] = { "inima rosie", "inima neagra", "trefla", "romb"};
        std :: string valori[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        int carte_curenta;

    public:
        Pachet(std :: string culori[], int dimensine_v_culori, std :: string valori[], int dimensiune_v_valori) : carte_curenta(0) {
            for (int i = 0; i < dimensiune_v_valori; ++i) {
                for (int j = 0; j < dimensine_v_culori; ++j) {
                    carti[i * dimensine_v_culori + j] =  new Carte(culori[j], valori[i]);
                }
            }
        }

        void afisare_pachet() {
            for (int i = 0; i < NR_MAX; ++i) {
                std :: cout << carti[i] -> get_valoare() << " de " << carti[i] -> get_culoare() << '\n';
            }
        }

        void amestecare_pachet() {

            int i, j;
            Carte *aux = nullptr;

            for (int contor = 0; contor < NR_AMESTECARI; ++contor) {
                i = rand() % NR_MAX;
                j = rand() % NR_MAX;

                aux = carti[i];
                carti[i] = carti[j];
                carti[j] = aux;
            }


        }

        Carte *extragere_carte() {
            return carti[carte_curenta++];
        }


};

int main(){

    std :: string culori[4];
    std :: string valori[13];

    for (int i = 0; i < 4; ++i) {
        std :: cin >> culori[i];
    }

    for (int i = 0; i < 13; ++i) {
        std :: cin >> valori[i];
    }

    Pachet pachet(culori, 4, valori, 13);

    Carte *p = nullptr;

    pachet.amestecare_pachet();
    pachet.afisare_pachet();

    std :: cout << std :: endl << std :: endl;
    
    p = pachet.extragere_carte();

    std :: cout << p -> get_valoare() << " de " << p -> get_culoare() << std :: endl;


    return 0;
}
