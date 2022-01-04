/*
 Programmer : Anamaria Andra Pescaru 
 Cerinta : Atunci când se definește un constructor cu parametri, constructorul implicit este suprimat și trebuie definit în mod explicit sau încorporat într-un constructor cu parametri sub forma unui constructor cu argumente implicite.

Pentru clasa Pisica cu datele membre nume, vârstă, greutate să se scrie toți constructorii cu parametri posibili. Toate valorile numerice implicite vor fi egale cu 0, iar șirurile de caractere implicite nu vor conține niciun caracter. În programul principal se vor instanția mai întâi un obiect cu niciun parametru, apoi cu un parametru, cu doi parametri, respectiv 3 parametri - parametrii vor fi transmiși în ordinea menționată anterior, fiecare dintre ei fiind citit de pe un rând nou. Pentru fiecare obiect menționat se vor afișa toate datele membre, în ordinea menționată, separate de un spațiu. După fiecare set de date membre aparținând unui obiect se va trece pe următorul rând (caracterul newline).
*/
#include <iostream>
#include <string.h>

class Pisica {
    private:

    std :: string nume;
    int varsta;
    float greutate;

    public:

    Pisica() {
        this -> varsta = 0;
        this -> greutate = 0;
        std :: cout << this -> nume << " " << this -> varsta << " " << this -> greutate << '\n';

    }

    Pisica(std :: string nume) {
        this -> nume = nume;
        this -> varsta = 0;
        this -> greutate = 0;
        std :: cout << this -> nume << " " << this -> varsta << " " << this -> greutate << '\n';
    }

    Pisica(std :: string nume, int varsta) {
        this -> nume = nume;
        this -> varsta = varsta;
        this -> greutate = 0;
        std :: cout << this -> nume << " " << this -> varsta << " " << this -> greutate << '\n';
    }

    Pisica(std :: string nume, int varsta, float greutate) {
        this -> nume = nume;
        this -> varsta = varsta;
        this -> greutate = greutate;
        std :: cout << this -> nume << " " << this -> varsta << " " << this -> greutate << '\n';
    }
};

int main() {
    std :: string v_nume, v1_nume, v2_nume;
    float v_greutate;
    int v_varsta, v1_varsta;

    Pisica r1;

    std :: getline(std :: cin, v_nume);
    Pisica r2(v_nume);

    std :: getline(std :: cin, v_nume);
    std :: cin >> v_varsta;
    Pisica r3(v1_nume);

    std :: getline(std :: cin, v_nume);
    std :: cin >> v1_varsta;
    std :: cin >> v_greutate;
    Pisica r4(v2_nume);

    return 0;
    
}
