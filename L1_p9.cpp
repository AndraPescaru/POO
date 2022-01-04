/*
 Programmer : Anamaria Andra Pescaru 
 Cerinta : Să se scrie o clasă Carte cu următoarele date membre: titlu, nume_autor, an_lansare, nr_pagini, pret. Se vor instanția maxim 5 obiecte din această clasă folosind un vector cu alocare dinamica de memorie. Se citește de la tastatură numărul de cărți pe care dorim să îl folosim. Ulterior, pentru fiecare carte se vor citi, de pe rânduri diferite datele membre în ordinea enunțată mai sus.

Se va citi o comandă de la tastatură. În funcție de valoarea acesteia se vor executa diferite acțiuni:
Se citește de la tastatură un nume de autor. Se afișează titlurile tuturor cărților scrise de acest autor, separate de virgulă și spațiu. Pentru simplitate, ultimul titlu va fi, de asemenea, urmat de virgulă și spațiu.
Se va afișa cartea cu numărul minim de pagini. 
Se va afișa cartea cel mai recent lansată. 
Prin afișarea cărții se înțelege afișarea tuturor datelor membre ale cărții, fiecare pe un rând nou.
*/
#include <iostream>
#include <string.h>
#include <iomanip>
#include <cmath>

class Carte {
    private:
    std :: string titlu, nume_autor;
    int an_lansare, nr_pagini;
    float pret;

    public : Carte(){}
    public:

    Carte(std :: string titlu, std :: string nume_autor, int an_lansare, int nr_pagini, float pret) {
        this -> titlu = titlu;
        this -> nume_autor = nume_autor;
        this -> an_lansare = an_lansare;
        this -> nr_pagini = nr_pagini;
        this -> pret = pret;
    }

    void set_titlu(std :: string titlu) {
        this -> titlu = titlu;
    }
    std :: string get_titlu() {
        return this -> titlu;
    }
    void set_nume_autor(std :: string nume_autor) {
        this -> nume_autor = nume_autor;
    }
    std :: string get_nume_autor() {
        return this -> nume_autor;
    }
    void set_an_lansare(int an_lansare) {
        this -> an_lansare = an_lansare;
    }
    float get_an_lansare() {
        return this -> an_lansare;
    }
    void set_nr_pagini(int nr_pagini) {
        this -> nr_pagini = nr_pagini;
    }
    float get_nr_pagini() {
        return this -> nr_pagini;
    }
    void set_pret(float pret) {
        this -> pret = pret;
    }
    float get_pret() {
        return this -> pret;
    }
    
    void display() {
        std :: cout << this -> titlu << std :: endl;
        std :: cout << this -> nume_autor << std :: endl;
        std :: cout << this -> an_lansare << std :: endl;
        std :: cout << this -> nr_pagini << std :: endl;
        std :: cout << this -> pret << std :: endl;
    }
};

int main() {
    
    Carte *v[10];
    
    int nr_carti;
    std :: string v_titlu, v_nume_autor;
    int v_an_lansare, v_nr_pagini;
    float v_pret;
    std :: cin >> nr_carti;
    
    for (int i = 1; i <= nr_carti; ++i) {
        getchar();
        std :: getline(std :: cin, v_titlu);
        std :: getline(std :: cin, v_nume_autor);
        std :: cin >> v_an_lansare;
        std :: cin >> v_nr_pagini;
        std :: cin >> v_pret;
        
        v[i] = new Carte(v_titlu, v_nume_autor, v_an_lansare, v_nr_pagini, v_pret);
    }
    
    int comanda;
    std :: cin >> comanda;
    
    if (comanda == 1) {
        getchar();
        std :: getline(std :: cin, v_nume_autor);
        std :: cout << v_nume_autor << std :: endl;
        for (int i = 1; i <= nr_carti; ++i) {
            if (v[i] -> get_nume_autor() == v_nume_autor) {
                std :: cout << v[i] -> get_titlu() <<", ";
            }
        }
    }
    
    if (comanda == 2) {
        int minim = v[1] -> get_nr_pagini();
        int pozitie = 1;
        for (int i = 2; i <= nr_carti; ++i) {
            if (minim > v[i] -> get_nr_pagini()){
                minim = v[i] -> get_nr_pagini();
                pozitie = i;
            }
        }
        
        v[pozitie] -> display();
        
    }
    
    if (comanda == 3) {
        int maxim = v[1] -> get_an_lansare();
        int pozitie = 1;
        for (int i = 1; i <= nr_carti; ++i) {
            if (maxim < v[i] -> get_an_lansare()) {
                maxim = v[i] -> get_an_lansare();
                pozitie = i;
            }
        }
        
        v[pozitie] -> display();
    }

    return 0;
    
}
