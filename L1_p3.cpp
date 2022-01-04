/*
 Programmer : Anamaria Andra Pescaru 
 
 Cerinta : Menținerea specificatorului de acces “public” este o potențială breșă de securitate. Pentru a asigura ascunderea datelor, cele 3 date membre ale clasei Cutie vor avea specificatorul de acces “private”.
Pentru clasa Cutie se vor scrie o serie de funcții care modifică (setter), respectiv accesează (getter) valorile datelor membre. În programul principal se va instanția un obiect de tipul Cutie, se vor citi de la tastatură cele 3 atribute și se vor asigna obiectului respectiv cu ajutorul funcțiilor setter. Ulterior, se vor afișa pe ecran cu ajutorul funcțiilor getter în ordinea precizată, fiecare pe un rând nou.
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
 
    void display() {
     std :: cout << std :: fixed;
     std :: cout << std :: setprecision(3);
     std :: cout << this -> lungime << " "<< this -> latime << " "<< this -> inaltime;
    {
    
};

int main() {
    
    float v_lungime, v_latime, v_inaltime;
    
    std :: cin >> v_lungime;
    std :: cin >> v_latime;
    std :: cin >> v_inaltime;
    
    Cutie c(v_lungime, v_latime, v_inaltime);
    c.display();
    
    return 0;
}
