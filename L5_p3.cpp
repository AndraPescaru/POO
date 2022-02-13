/*
Să se scrie un program care afișează pe ecran numele studenților citiți de la tastatură, ordonați după un anumit criteriu definit mai jos.

Se citesc de la tastatură până la apariția cuvântului STOP:

un std::string, reprezentând numele studentului;
un întreg, n, reprezentând numărul de note ce urmează a fi citit de la tastatură;
n întregi reprezentând notele studentului;
După cuvântul STOP se mai citește o valoare întreagă de test, în funcție de a cărei valoare se execută:

Ordonarea studenților după nume. Se afișează pe ecran numele studenților în ordine lexicografică, câte unul pe un rând diferit. Fiecare nume este urmat de caracterul '\n'.
Ordonarea studenților după media notelor. Se afișează pe ecran numele studenților în ordinea mediilor notelor, câte unul pe un rând. Fiecare nume este urmat de caracterul '\n'.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Student {
    
    private:
        int n;
        std :: string name;
        int *note;
    public:
        Student(int n, int *note, std :: string name) : n(n), note(note), name(name) {}
        
        std :: string get_name() {
            return this -> name;
        }
        
        friend bool compare(Student &, Student &);
        
        float media() {
            float suma = 0;
            for (int i = 1; i <= this -> n; ++i) {
                suma += this -> note[i];
            }
            
            return (float) suma / this -> n;
        }
        
        
    
};

bool compare(Student &a, Student &b) {
    if (a.get_name() == b.get_name()) 
        return 0;
        else
        return 1;
}

bool compare_medie(Student &a, Student &b) {
    return ( a.media() < b.media());
}


int main() {
    
    std :: string nume;
    int n, x;
    
    std :: vector<Student> student;
    
   do {
        std :: cin >> nume;
        
        if (nume != "STOP") {
            std :: cin >> n;
        
            int *note = new int[n];
        
            for (int i = 1; i <= n; ++i) {
                std :: cin >> x;
                note[i] = x;
            }
            
            student.push_back(Student(n, note, nume));
        }
        
    } while(nume != "STOP");
    
    int comanda;
    
    std :: cin >> comanda;
    
    if (comanda == 1) {
        std :: sort(student.begin(), student.end(), compare);
    
        for (auto i = student.begin(); i != student.end(); ++i) {
            std :: cout << i -> get_name() << "\n";
        }
    }
     if (comanda == 2) {
         std :: sort(student.begin(), student.end(), compare_medie);
    
        for (auto i = student.begin(); i != student.end(); ++i) {
            std :: cout << i -> get_name() << "\n";
        }
     } 
    
    return 0;
    
}
