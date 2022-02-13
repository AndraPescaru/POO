/*
Pornind de la o clasă de bază Poligon, se vor crea două derivate: Triunghi și Paralelogram. De asemenea, se cunoaște că există funcția virtual float Poligon::aria()=0;
Se citește de la tastatură o valoare întreagă reprezentând numărul de Triunghiuri și numărul de Paralelograme ale căror laturi urmează a fi citite. Să se afișeze pe ecran
Poligoanele, în ordinea ariei lor, câte un Poligon pe rând. Afișarea unui Poligon coincide cu afișarea valorilor laturilor sale, în aceeași ordine în care au fost citite,
separate de un spațiu liber.
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Poligon{
    protected:
        float l1;
        float l2;
    public:
        virtual float aria() const = 0;
        void afisare() {
            std :: cout << l1 << " " << l2 << '\n';
        }
        bool operator<(const Poligon &p) {
            return (this -> aria() < p.aria());
        }
        
        
        
};

class Triunghi : public Poligon {
    // private: 
    //     float baza;
    //     float inaltime;
    public:
        Triunghi(float baza = 0 , float inaltime = 0) { 
            l1 = baza;
            l2 = inaltime;
        }
        float aria() const{
            return l1 * l2 / 2;
        }
    
};

class Paralelogram : public Poligon{
    // private:
    //     float latime;
    //     float inaltime;
    public:
        Paralelogram(float latime = 0, float inaltime = 0) {
            l1 = latime;
            l2 = inaltime;
        }
        float aria() const{ return l1 * l2;}
};

bool compare(Poligon *p1, Poligon *p2) {
    return ((*p1) < (*p2));
}

int main(){
    
    int nr_poly;
    float temp_l1, temp_l2;
    
    std :: cin >> nr_poly;
    
    std :: vector<Poligon*> polys;
    
    for (int i = 0; i < nr_poly; ++i) {
        std :: cin >> temp_l1 >> temp_l2;
        polys.push_back(new Triunghi(temp_l1, temp_l2));
    }
    
    for (int i = 0; i < nr_poly; ++i) {
        std :: cin >> temp_l1 >> temp_l2;
        polys.push_back(new Paralelogram(temp_l1, temp_l2));
    }
    
    // std :: cout << "Inainte de sortare:\n" << std :: endl;
    
    // for (Poligon *p: polys) {
    //     p -> afisare();
    // }
    
    // std :: cout << "Dupa sortare:\n" << std :: endl;
    
    std :: sort(polys.begin(),polys.end(), compare);
    
    for (Poligon *p: polys) {
            p -> afisare();
            //std :: cout << p -> aria() << '\n';
    }
    
    return 0;
}
