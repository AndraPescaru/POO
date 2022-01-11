/*
Se vor instanția un obiect din clasa Vehicul și un obiect din clasa Autovehicul cu datele citite de la tastatură. Se citesc de la tastatură, de pe rânduri diferite, următoarele:
1. un șir de caractere, reprezentând numele Vehiculului;
2. un număr real, reprezentând prețul Vehiculului;
3. un număr real, reprezentând greutatea Vehiculului;
4. un șir de caractere, reprezentând numele Autovehiculului;
5. un număr real, reprezentând prețul Autovehiculului;
6. un număr real, reprezentând greutatea Autovehiculului;
7. un număr întreg, reprezentând puterea Autovehiculului.

Se vor afișa pe ecran datele membre ale celor două obiecte, începând cu vehiculul, fiecare pe un rând nou, sub forma: <nume data membra>: <valoare data membra>. Constructorii vor folosi liste de inițializare, iar funcția de afișare din clasa Autovehicul va utiliza funcția de afișare din clasa Vehicul.
*/
#include <iostream>
#include <string.h>

class Vehicul {
  private:
    std :: string nume;
    float pret;
    float greutate;
    
  public:
  
  Vehicul( std :: string nume, float pret, float greutate) {
      this -> nume = nume;
      this -> pret = pret;
      this -> greutate = greutate;
  }
  
  std :: string get_nume() {
      return this -> nume;
  }
  
  float get_greutate() {
      return this -> greutate;
  }
  
  float get_pret() {
      return this -> pret;
  }
  
  void  display() {
      std :: cout << "nume: " << this -> nume << '\n';
      std :: cout << "pret: " << this -> pret << '\n';
      std :: cout << "greutate: " << this -> greutate << '\n';
  }
};

class Autovehicul : public Vehicul {
    private:
        int putere;
    public:
    Autovehicul(std :: string nume, float pret, float greutate, int putere): Vehicul(nume,pret,greutate), putere(putere) {
       
    }
    void a_display() {
      
      std :: cout << "putere: " << this -> putere << '\n';
    }
};

int main() {
    
    std :: string nume_veh;
    std :: getline(std :: cin, nume_veh);
    
    float pret;
    std :: cin >> pret;
    
    float greutatea;
    std :: cin >> greutatea;
    
    Vehicul V(nume_veh,pret, greutatea);
    
    getchar();
    std :: string nume_au;
    std :: getline(std :: cin, nume_au);
    
    float pret_au;
    std :: cin >> pret_au;
    
    float greutate_au;
    std :: cin >> greutate_au;
    
    int putere;
    std :: cin >> putere;
    
    Autovehicul A(nume_au, pret_au, greutate_au, putere);
    
    V.display();
    A.display();
    A.a_display();
    
    
    
    
    return 0;
}

