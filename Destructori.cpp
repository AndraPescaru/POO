// folosit pentru a elibera resursele ce au fost ocupate de obiect în timpul existenței sale
// • pentru fiecare new avem nevoie de un delete;
// • pentru fiecare new[] avem nevoie de un delete[];
// • pentru fiecare malloc() avem nevoie de free().
#include <iostream>
#include <stdlib.h>

class Student {
    private:
        int *note;
        int nr_note;
  
    public:
        Student(int *note, int nr_note) {

            this -> nr_note = nr_note;
            this -> note = new int[nr_note]; 

            for (int i = 0; i < nr_note; i++) {
            *(this -> note + i) = *(note + i);
            }
        }
        ~Student() {
            delete [] note;
            std :: cout << "Apel destructor!" << std :: endl;
        }
        void display() {
            for (int i = 0; i < this -> nr_note; ++i){
                std :: cout << *(note + i) << " ";
            }
            std :: cout << std :: endl;
        }
};

int main() {

    int a[4] = {3, 7, 1, 5};

    Student s1(a, 4);
    s1.display();

    return 0;
}
