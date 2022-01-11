/*
    Programmer : Pescaru Anamaria - Andra
*/
#include <iostream>
#include <string>
#include <cstdlib>

class Produs {
    private:
        std :: string nume;
        float pret;
        int cantitate;

    public:
        Produs() {}
        std :: string get_nume() { return nume;}
        float get_pret() {return pret;}
        int get_cantitate() {return cantitate;}

        void set_nume(const std :: string nume) {this -> nume = nume;}
        void set_pret(const float a_pret) {pret = a_pret;}
        void set_cantitate(const int arg) {cantitate = arg;}

};

class Magazin {
    private:
        Produs produse[10];
        int nr_produse;
    public:
        Magazin(Produs a_produse[10], int nr_produse) {
            this -> nr_produse = nr_produse;
            for (int i = 0; i < nr_produse; ++i) {
                produse[i].set_nume(a_produse[i].get_nume());
                produse[i].set_pret(a_produse[i].get_pret());
                produse[i].set_cantitate(a_produse[i].get_cantitate());
            }
        }

        void afisare_produse() {
            for (int i = 0; i < nr_produse; ++i) {
                if (produse[i].get_cantitate() != 0) {
                    std :: cout << produse[i].get_nume() << '\n';
                    std :: cout << produse[i].get_pret() << '\n';
                    std :: cout << produse[i].get_cantitate() << '\n';
                }
            }
        }

        float get_pret_by_nume(std :: string nume) {
            for (int i = 0; i < nr_produse; ++i) {
                if (produse[i].get_nume() == nume) {
                    return produse[i].get_pret();
                }
            }
            return 0;
        }

        float get_cantitate_by_nume(std :: string nume) {
            for (int i = 0; i < nr_produse; ++i) {
                if (produse[i].get_nume() == nume) {
                    return produse[i].get_cantitate();
                }
            }
            return 0;
        }

};

class Cos_cumparaturi {
    private:
        Produs produse[10];
        int nr_produse;
    public:
        Cos_cumparaturi(Produs a_produse[10], int nr_produse) {
            this -> nr_produse = nr_produse;
            for (int i = 0; i < nr_produse; ++i) {
                produse[i].set_nume(a_produse[i].get_nume());
                produse[i].set_pret(a_produse[i].get_pret());
                produse[i].set_cantitate(a_produse[i].get_cantitate());
            }
        }

        float total_plata() {
            float total = 0;
            for (int i = 0; i < nr_produse; ++i) {
                total += produse[i].get_pret() * produse[i].get_cantitate();
                
            }

            return total;
        }

};

class Reducere {};

int main() {

    std :: string temp_nume;
    float temp_pret;
    int temp_cantitate;
    Produs temp_produse[10];
    int index = 0;
    int comanda;

    while (1) {
        std :: getline(std :: cin , temp_nume);

        if (temp_nume != "STOP") {
            std :: cin >> temp_pret >> temp_cantitate;
            std :: cin.ignore(1000, '\n');
            
            std :: cout << temp_nume << '\n';
            std :: cout << temp_pret << '\n';
            std :: cout << temp_cantitate << '\n';

            temp_produse[index].set_nume(temp_nume);
            temp_produse[index].set_pret(temp_pret);
            temp_produse[index].set_cantitate(temp_cantitate);
            ++index;

        } else {
            break;
        }    
    }
    
    Magazin magazin(temp_produse, index);

    std :: cin >> comanda;
    std :: cin.ignore(1000, '\n');

    switch (comanda)
    {
    
    default:
        break;
    case 1:
        magazin.afisare_produse();
        break;
    case 2: 
        index = 0;
        while (1) {
            std :: getline(std :: cin , temp_nume);

            if (temp_nume != "STOP") {
                std :: cin >> temp_cantitate;
                std :: cin.ignore(1000, '\n');

                if (temp_cantitate  <= magazin.get_cantitate_by_nume(temp_nume)) {
                    temp_produse[index].set_nume(temp_nume);
                    temp_produse[index].set_pret(magazin.get_pret_by_nume(temp_nume));
                    temp_produse[index].set_cantitate(temp_cantitate);
                    ++index;
                } else {
                    std :: cout << "Produsul" << temp_nume << "mai are doar" << magazin.get_cantitate_by_nume(temp_nume) << "bucati in stoc" << '\n';
                    exit(0);
                }

            } else {
                break;
            }    
        }
        Cos_cumparaturi cos_cumparaturi(temp_produse, index);
        std :: cout << "Total de plata" << std :: endl << cos_cumparaturi.total_plata() << std :: endl;

        break;

    }

    return 0;
}
