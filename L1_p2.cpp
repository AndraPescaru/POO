/*
 Programmer : Anamaria Andra Pescaru 
 
 Cerinta : Scrieți o clasă Cutie cu 3 date membre publice: lungime, lățime, înălțime, de tip real și o funcție membră care întoarce volumul cutiei.

Extra: definiți o funcție membră care calculează volumul rămas în cutia inițială dacă în ea se va introduce o altă cutie transmisă ca argument în funcție. Se va verifica, mai întâi, dacă cea de-a doua cutie poate fi introdusă în prima cutie (considerăm că cele 3 dimensiuni respectă aceeași ordine și nu putem roti nicio cutie). În caz contrar, se va afișa volumul cutiei inițiale.

În programul principal se va instanția un obiect de tipul Cutie, se vor citi de la tastatură cele 3 atribute și se va citi o comandă, în funcție de valoarea căreia se vor executa diferite acțiuni:
1. Se afișează pe ecran volumul cutiei.
2. Se instanțiază o a doua cutie, se citesc de la tastatură cele 3 atribute și se afișează pe ecran volumul rămas liber în prima cutie după introducerea celei de-a doua cutii (dacă este posibil).
*/
#include <iostream>
#include <stdlib.h>
#include <iomanip>

class Cutie{
    
    private:
    float lungime, latime, inaltime;
    
    public:
    
    Cutie(float lungime, float latime, float inaltime) {
        this -> lungime = lungime;
        this -> latime = latime;
        this -> inaltime = inaltime;
    }
    
    void set_lungime(float lungime){
        this -> lungime = lungime;
    }
    
    float get_lungime(){
        return this -> lungime;
    }
    
    void set_latime(float latime){
        this -> latime = latime;
    }
    
    float get_latime(){
        return this -> latime;
    }
    
    void set_inaltime(float inaltime){
        this -> inaltime = inaltime;
    }
    
    float get_inaltime(){
        return this -> inaltime;
    }
    
    float Volum() {
        return  get_lungime() * get_latime() * get_inaltime();
    }
    
};

int main() {
    
    float v_lungime, v_latime, v_inaltime;
    int comanda;
    
    std :: cin >> v_lungime;
    std :: cin >> v_latime;
    std :: cin >> v_inaltime;
    std :: cin >> comanda;
    
    Cutie c(v_lungime, v_latime, v_inaltime);
    
    if (comanda == 1){
        std :: cout << std :: fixed;
        std :: cout << std :: setprecision(3);
        std :: cout << c.Volum() << std :: endl;
    } else {
        float m_lungime, m_latime, m_inaltime;
        
        std :: cin >> m_lungime;
        std :: cin >> m_latime;
        std :: cin >> m_inaltime;
        
        Cutie c1(m_lungime, m_latime, m_inaltime);
        
        if ((c.get_lungime() > c1.get_lungime() && c.get_inaltime() > c1.get_inaltime() && c.get_latime() > c1.get_latime())) {
            std :: cout << std :: fixed;
            std :: cout << std :: setprecision(3);
            std :: cout << c.Volum() - c1.Volum() << std :: endl;
        } else {
            std :: cout << std :: fixed;
            std :: cout << std :: setprecision(3);
            std :: cout << c.Volum() << std :: endl;
        }
        
    }
    
    return 0;
}
