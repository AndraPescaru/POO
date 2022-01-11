/*
Se va instanția un obiect din clasa Telefon_mobil cu următoarele date, citite de la tastatură, de pe rânduri diferite:
1. o valoare reală, reprezentând tensiunea;
2. o valoare reală, reprezentând intensitatea;
3. un șir de caractere, reprezentând numărul de telefon;
4. un număr întreg, reprezentând procentul de baterie disponibil;

Separat, se vor mai citi următoarele date, de pe linii diferite, pentru a utiliza funcția suna:
5. un șir de caractere, reprezentând numărul apelat;
6. un număr întreg, reprezentând durata apelului, exprimată în minute.

Funcția suna din clasa Telefon primește ca argument un șir de caractere și afișează mesajul "Calling: <numar de telefon transmis ca argument>". Funcția suna din clasa Telefon_mobil primește un argument în plus reprezentând durata apelului în minute și afișează mesajul "Outgoing number: <numar de telefon propriu>", urmat de mesajul funcției cu același nume din clasa Telefon, și reduce bateria direct proporțional cu puterea consumată de dispozitivul electronic. Bateria scade cu <putere>/100 pentru fiecare minut de conversație.

În programul principal se apelează funcția suna cu argumentele citite de la tastatură și se afișează pe ecran, pe un rând separat, procentul de baterie rămas disponibil, după efectuarea apelului
*/
#include <iostream>
#include <string.h>

class Echipament_electronic{
    protected:
        float tensiune;
        float intensitate;
    
    public:
    Echipament_electronic(float tensiune ,float intensitate) : tensiune(tensiune), intensitate(intensitate) {
        
    }
    
};

class Telefon : private Echipament_electronic {
    protected:
        std :: string nr_tel;
    public:

        Telefon(float tensiune ,float intensitate, std :: string nr_tel) : Echipament_electronic(intensitate,tensiune), nr_tel(nr_tel) {
            
        }
        using Echipament_electronic ::  tensiune;
        using Echipament_electronic ::  intensitate;
        void suna_t(std :: string nr) {
            std :: cout << "Calling: " << nr << '\n';
            
        }
};

class Telefon_mobil : protected Telefon {
    private:
        int baterie;
    
    public:
    
    int get_baterie() {
        return this -> baterie;
    }
    
        Telefon_mobil(float tensiune ,float intensitate, std :: string nr_tel, int procent) : Telefon( intensitate,tensiune,nr_tel), baterie(procent) {
            
        }
        
        void suna(std :: string nr, int mini) { 
            suna_t(nr);
            std :: cout << "Outgoing number: ";
            std :: cout << nr_tel << '\n';
            this -> baterie -=  tensiune * intensitate * mini / 100 ;
            
        }
    
};

int main() {
    
    float tensiune;
    std :: cin >> tensiune;
    
    float intensitatea;
    std :: cin >> intensitatea;
    
    getchar();
    std :: string nr_telef;
    std :: getline(std :: cin , nr_telef);
    
    int procent;
    std :: cin >> procent;
    
    Echipament_electronic E(tensiune, intensitatea);
    Telefon Tel(tensiune, intensitatea, nr_telef);
    Telefon_mobil T(tensiune, intensitatea, nr_telef, procent);
    
    std :: string nr_apelat;
    getchar();
    std :: getline(std :: cin, nr_apelat);
    
    int durata;
    std :: cin >> durata;
    
    T.suna(nr_apelat,durata);
    
    if ( T.get_baterie() < 0) 
    std :: cout << 0 << '\n';
    else
    std :: cout << T.get_baterie() << '\n';
    
    
    return 0;
}
