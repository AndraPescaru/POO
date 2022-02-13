#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

class Angajat{
protected: 
    std :: string nume;
    std :: string departament;
public:
    Angajat(std :: string nume, std :: string departament) : nume (nume), departament(departament) {}
       virtual void afisare() = 0;
       virtual float rentabilitate_angajat() = 0;
       virtual float rentabilitate_angajat2() = 0;

    std :: string get_departament() {
        return this -> departament;
    }
    std :: string get_nume() {
        return this -> nume;
    }
 };

class Salariat : public Angajat {
    private:
        int norma;
        int vechime;
        float salariu_net;
    public:
        Salariat(std :: string nume, std :: string departament, int norma, int vechime, float salariu_net ) : Angajat(nume, departament), norma(norma), vechime(vechime), salariu_net(salariu_net) {}
        void afisare() {
            std :: cout << nume << " " << norma << " " << vechime << " " << salariu_net << '\n';
        } 
        float rentabilitate_angajat() {
            
            if (departament == "IT") {
                return (float) (salariu_net * 12 ) / (1 - 0.35);
            } else {
                return (float) (salariu_net * 12 ) / (1 - 0.45);
            }
        }
        
        float rentabilitate_angajat2() {
            return (float)(norma * 250) / (12 * salariu_net);
        }
        
    
};

class Colaborator : public Angajat {
    private:
        float onorariu;
        float nr_prestari_anuale;
    public:
        Colaborator(std :: string nume, std :: string departament, float onorariu, int nr_prestari_anuale) : Angajat(nume, departament), onorariu(onorariu), nr_prestari_anuale(nr_prestari_anuale) {}
        void afisare() {
            std :: cout << nume << " " << onorariu << " " << nr_prestari_anuale << '\n';
        }
        float rentabilitate_angajat() {
            if (departament == "IT") {
                return (float) (onorariu  * nr_prestari_anuale ) / (1 - 0.35);
            } else {
                return (float) (onorariu  * nr_prestari_anuale ) / (1 - 0.45);
            }
        }
        float rentabilitate_angajat2() {
            return 0;
        }
};

int main() {
    
    int n;
    std :: cin >> n;
    
    int norma1, vechime1, salariu;
    
    std :: string tip, nume, dep;
    
    float onorariu1;
    int prestari;
    
    std :: vector<Angajat *> angajati;
    
    for (int i = 1; i <= n; ++i) {
        std :: cin >> tip >> nume >> dep;
        
        if (tip == "salariat") {
            std :: cin >> norma1 >> vechime1 >> salariu;
            
            angajati.push_back(new Salariat( nume, dep, norma1, vechime1, salariu));
        }
        
        if (tip == "colaborator") {
            std :: cin >> onorariu1;
            std :: cin >> prestari;
            
            angajati.push_back(new Colaborator(nume, dep, onorariu1, prestari));
        }
    }
    
    int comanda;
    
    std :: cin >> comanda;
    
    if (comanda == 1) {
        
        std :: string prima;
        std :: cin >> prima;
        
        for (Angajat *i : angajati) {
            if (i -> get_departament() == prima )
            i -> afisare();
        }
    }
    
    if (comanda == 2) {
        std :: string test;
        std :: cin >> test;
        
        for (Angajat *i : angajati) {
            if (i -> get_nume() == test )
            std :: cout << i -> rentabilitate_angajat() << '\n';
        }
        
    }
    
    if (comanda == 3) {
        float maxi = -1;
        std :: string testul;
        for (Angajat *i : angajati) {
            if (i -> rentabilitate_angajat2()) {
                if (maxi < i -> rentabilitate_angajat2()) {
                    maxi = i -> rentabilitate_angajat2();
                    testul = i -> get_nume();
                }
            }
        }
        
        std :: cout << testul << '\n';
    }
    
    if (comanda == 4) {
        std :: string nume_dep;
        std :: cin >> nume_dep;
        int nr_angajati = 0;
        float suma = 0;
        
        for (Angajat *i : angajati) {
            if (nume_dep == i -> get_departament()) {
                nr_angajati++;
                suma += i -> rentabilitate_angajat();
            }
        }
        std :: cout << (float)suma / nr_angajati;
    }
    
    return 0;
}
