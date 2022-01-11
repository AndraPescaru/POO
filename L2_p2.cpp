#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iomanip>

class Parinte {
  
    public:

    
    void modificare_nume(  int varsta, std :: string new_name,int &modificare) {
        if ( varsta < 18) {
            modificare = 1;
        }
    }
    
        
        
};
class Copil {
    private:
        int varsta;
        std :: string nume;
        friend class Parinte;
        
    public:
   
    
    Copil(int varsta1, std :: string nume1):varsta(varsta1),nume(nume1){}
    
    
    int get_varsta() {
        return this -> varsta;
    }
    
    void set_nume(std :: string nume) {
        this -> nume = nume;
    }
    std :: string get_nume() {
        return this -> nume;
    }
    void permite_modificare(std :: string new_name, int &modificare) {
        if (this -> varsta >= 18) {
            set_nume(new_name);
            modificare = 1;
        }
        
    }
    
        
};
int main () {
    
    int c_varsta;
    std :: cin >> c_varsta;
    
    std :: string c_nume;
    getchar();
    std :: getline(std :: cin , c_nume);
    std :: string new_name;
    std :: getline(std :: cin, new_name);
    
    int x;
    std :: cin >> x;
    
    Copil C(c_varsta, c_nume);
    Parinte P;
    
    if (x) {
        int modificare = 0;
        C.permite_modificare(new_name, modificare);
        if (modificare) {
            std :: cout << C.get_nume();
        } else {
            std :: cout << "EROARE";
        }
    }
    else {
        int modificare = 0;
        P.modificare_nume(C.get_varsta(), new_name, modificare);
        if (modificare) {
            C.set_nume(new_name);
            std :: cout << C.get_nume();
        } else {
            std :: cout << "EROARE";
        }
    }
    
    return 0;
    
}
