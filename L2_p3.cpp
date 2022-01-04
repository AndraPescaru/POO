/*
Să se scrie o clasă Pantof cu datele membre stil și mărime. Suplimentar, aceasta va conține o dată membră de tip întreg cu rolul de contor, ce va reține numărul de obiecte create, și o dată membră care reține numărul maxim de obiecte ce pot fi create din această clasă (se presupune că sunt în ediție limitată). Dacă la tentativa de instanțiere a unui obiect se constată că s-a atins deja numărul maxim de obiecte ce pot fi instanțiate se va afișa pe ecran mesajul “S-a atins pragul maxim din editia limitata!”. Toate inițializările din constructori vor fi făcute cu ajutorul listei de inițializare.
În programul principal se vor citi de la tastatură, de pe linii diferite, următoarele date:

un întreg m, reprezentând numărul maxim de Pantofi pe care îi putem instanția;

un întreg n, reprezentând numărul de obiecte pe care le vom instanția;

n perechi de date de tipul std::string și int, reprezentând stilul și mărimea, câte o pereche pe fiecare rând. Stilul este reprezentat de un singur cuvânt.

După fiecare instanțiere se vor afișa pe ecran stilul și marimea, separate de un spațiu și urmate de caracterul newline.

Extensie: separați declarația clasei și definițiile funcțiilor membre în fișiere diferite.
Extensie 2: cele n instanțe ale clasei Pantof vor fi reținute sub forma unui vector static de obiecte.
Extensie 3: cele n instanțe ale clasei Pantof vor fi reținute sub forma unui vector dinamic de obiecte.


*/
#include <iostream>
#include <stdlib.h>

class Pantof{
    private: 
        std :: string stil;
        int marime;
        int max;
    public:
        static int contor;
        //Pantof(std :: string stil, int marime, int contor, int max):stil(stil),marime(marime),contor(contor),max(max){}
        Pantof(std :: string stil, int marime, int max){
            this -> stil = stil;
            this -> marime = marime;
            this -> max = max;
            ++ contor;
            
        }
    
        std :: string get_stil() {
        return this -> stil;
        }
    
        int get_marime() {
            return this -> marime;
     }
        void display() {
            if(contor > max){
                std :: cout<<"S-a atins pragul maxim din editia limitata!";
            } else
            std :: cout << this -> stil << " " << this -> marime;
         }
    
};
int Pantof::contor = 0;

int main() {
    
  
    int m;
    
    std :: cin >> m;
    
    int n;
    std :: cin >> n;
    
    std :: string c_stil;
    int c_marime;
  
        for ( int i = 0; i < n; ++i) {
            std :: cin >> c_stil;
            std :: cin >> c_marime;
            Pantof c(c_stil,c_marime, m);
            c.display();
            std :: cout << std :: endl;
        }
    
    
    
    return 0;
}
