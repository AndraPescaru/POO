#include <iostream>
#include <string.h>
#include <iomanip>
#include <cmath>

class Student {
    private:
        int *note;
        int nr_note;

    public:
        Student(int *note, int nr_note) {

            this -> nr_note = nr_note;
            this -> note = new int[nr_note];

            for (int i = 0; i < nr_note; ++i) {
            *(this -> note + i) = *(note + i);
            }
        }

        Student(Student &s) {
            this -> nr_note = s.nr_note;
            this -> note = new int[this -> nr_note];

            for (int i = 0; i < nr_note; ++i){
                *(this -> note + i) = *(s.note + i);
            }
        }   

        void display() {
            for (int i = 0; i < nr_note; ++i) {
                std :: cout << *(note + i) << " ";
            }
        }

        void increment(int incr) {
            for(int i = 0; i < nr_note; ++i) {*(note + i) += incr;}
        }
};

int main() {

    int nr_note;
    std :: cin >> nr_note;
    int *note = new int[nr_note];

    for (int i = 0; i < nr_note; i++) {
        std :: cin >> *(note + i);
    }

    Student s1(note, nr_note);
    Student s2(s1);
    s1.display();
    std :: cout << std :: endl;
    s2.increment(5);
    s1.display();

    return 0;
}
