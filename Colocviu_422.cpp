//#include "Card_calatorie.h"

#include <iostream>

class Card_calatorie{
private:
    int id;
    char tip;
public:
    Card_calatorie(){}
    Card_calatorie(int id, char tip) : id(id), tip(tip){}
    virtual void validare_calatorie(int, int)=0;
    virtual void incarcare(int)=0;
    int get_id(){ return this -> id;}
    char get_tip(){ return this -> tip;}
};

class Autobuz : public Card_calatorie {
    private:
        int sold;
        int validare;
    public:
       Autobuz(){}
       Autobuz(int sold, int id, char tip, int validare): sold(sold), Card_calatorie(id,tip), validare(validare){}
       int get_sold(){ return this -> sold;}
       void set_sold(int soldt) {
           this -> sold += soldt;
       }
       void validare_calatorie(int id, int vdata){
           
       }
        int get_validare(){
            return this -> validare;
        }
        void set_validare(int vdata) {
            this -> validare = vdata;
        }
        void incarcare(int x){
            
        }
};
class Metrou : public Card_calatorie {
    private:
        int nr_calatorii;
        int validare;
    public:
        Metrou(){}
        Metrou(int nr_calatorii, int id, char tip, int validare): nr_calatorii(nr_calatorii), Card_calatorie(id, tip), validare(validare){}
        int get_nr_calatorii(){ return this -> nr_calatorii;}
        void set_nr_calatorii(int soldt){
            this -> nr_calatorii += soldt;
        }
        void validare_calatorie(int x, int y) {
            
        }
        
        int get_validare(){
            return this -> validare;
        }
        void set_validare(int vdata) {
            this -> validare = vdata;
        }
        void incarcare(int x){
            
        }
};

int main() {
    
    int n;
    std :: cin >> n;
    
    Autobuz A[100];
    Metrou M[100];
    char ordine[100];
    int nr1 = 1, nr2 = 1;
    for (int i = 1; i <= n; ++i) {
        char x;
        std :: cin >> x;
        int id;
        std :: cin >> id;
        int valoare;
        std :: cin >> valoare;
        
        ordine[i] = x;
        
        if (x == 'a') {
            
            A[nr1++] = Autobuz(valoare, id, x, 0);
        }
        if (x == 'm') {
            
            M[nr2++] = Metrou(valoare, id, x, 0);
        }
    }
    
    int comanda;
    int e1 = 0, e2 = 0;
    
    while (std :: cin >> comanda){
        if (comanda == 1) {
            for (int i = 1; i <= n; ++i) {
                if (ordine[i] == 'a') {
                    e1++;
                    std :: cout << A[e1].get_id() << " ";
                    std :: cout << A[e1].get_tip() << " ";
                    std :: cout << A[e1].get_sold() << " ";
                    std :: cout << A[e1].get_validare() << "\n";
                    
                }
                if (ordine[i] == 'm') {
                    e2++;
                    std :: cout << M[e2].get_id() << " ";
                    std :: cout << M[e2].get_tip() << " ";
                    std :: cout << M[e2].get_nr_calatorii() << " ";
                    std :: cout << M[e2].get_validare() << "\n";
                    
                }
            }
        }
        
        if (comanda == 2) {
            int idt, soldt;
            std :: cin >> idt >> soldt;
            
            for (int i = 1; i <= nr1; ++i) {
                if (A[i].get_id() == idt) {
                    A[i].set_sold(soldt);
                }
            }
            for (int i = 1; i <= nr2; ++i) {
                if (M[i].get_id() == idt) {
                    M[i].set_nr_calatorii(soldt);
                }
            }
        }
        
        if (comanda == 3) {
            int idt, vdata;
            std :: cin >> idt >> vdata;
            for (int i = 1; i <= nr1; ++i) {
                if (A[i].get_id() == idt) {
                    if (A[i].get_sold() < 3) {
                        std :: cout << "Sold insuficient" << std :: endl;
                    } else {
                        
                        if (A[i].get_validare() == 0 ||  vdata - A[i].get_validare() > 90 )
                        {
                            A[i].set_sold(-3);
                            A[i].set_validare(vdata);
                        }
                        
                    }
                }
            }
            for (int i = 1; i <= nr2; ++i) {
                if (M[i].get_id() == idt) {
                    if (M[i].get_nr_calatorii() < 1){
                        std :: cout << "Numar calatorii insuficient" << std :: endl;
                    } else {
                       
                        if (M[i].get_validare() == 0 ||  vdata - M[i].get_validare() > 90 ) {
                             M[i].set_nr_calatorii(-1);
                            M[i].set_validare(vdata);
                        }
                        
                    }
                }
            }
        }
        
        if (comanda == 4) {
            int idt1, idt2, suma;
            int r1 = 0, r2 = 0;
            std :: cin >> idt1 >> idt2 >> suma;
            for (int i = 1; i <= nr1; ++i) {
                if (idt1 == A[i].get_id()) {
                    r1 = i;
                }
                if (idt2 == A[i].get_id()) {
                    r2 = i;
                }
                
            }    
                if (r1 != 0 && r2 != 0) {
                    if (suma <= A[r1].get_sold()) {
                        A[r2].set_sold(suma);
                        A[r1].set_sold(-suma);
                    } else {
                        std :: cout << "Transfer nereusit" << std :: endl;
                    }
                }
                
                if ((r1 != 0 && r2 == 0) || (r2 != 0 && r1 == 0)) {
                    std :: cout << "Transfer nereusit" << std :: endl;
                }
                
                if (r1 == 0 && r2 == 0) {
                    for (int i = 1; i <= nr1; ++i) {
                        if (idt1 == M[i].get_id()) {
                            r1 = i;
                        }
                        if (idt2 == M[i].get_id()) {
                             r2 = i;
                        }
                
                    }
                    
                    if (suma <= M[r1].get_nr_calatorii()) {
                        M[r2].set_nr_calatorii(suma);
                        M[r1].set_nr_calatorii(-suma);
                    } else {
                        std :: cout << "Transfer nereusit" << std :: endl;
                    }
                    
                    
                }
            
            
        }
        
        if (comanda == 5) {
            break;
        }
    }
    
    return 0;
}
