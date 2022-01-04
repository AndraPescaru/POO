#include <iostream>
#include <string.h>
#include <iomanip>
#include <cmath>

class Student {
    private:
        std::string *nume;

    public:
        Student(const std :: string& str) {
          //Alocare bloc memorie, copiere str în zona alocată și returnare pointer către blocul de memorie.
            this->nume = new std::string(str);
        }

        Student(Student &&s) { // Referință la o rvalue
            this -> nume = s.nume;
            s.nume = nullptr; //Asignarea nullptr pentru pointer-ul *nume din referința la rvalue previne ștergerea accidentală a datelor din memorie atunci când obiectul din rvalue este distrus.
        }

        Student(Student &s) {
            this->nume = new std::string(*(s.nume));
        }

        void display(){std::cout << *nume << std::endl;}
};

Student f(Student s) {return s;}

int main() {
    
    Student s1("John");
    Student s2 = f(s1);

    s1.display();
    s2.display();

    return 0;
}
