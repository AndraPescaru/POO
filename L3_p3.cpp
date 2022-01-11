/*
În urma rulării codului din funcția main() se vor afișa pe ecran nota maximă a studenților seriei selectate, respectiv media notelor lor. Constructorul clasei Serie are rolul de a prelua din vectorul de intrare și a reține doar studenții care aparțin seriei selectate ('A').
*/
#include <iostream>
#include <cmath>
#include <string.h>

class Persoana {
    protected:
        std :: string nume;

    public:
        Persoana( std :: string nume): nume(nume){
            
        }
};

class Student : public Persoana {
    private:
        char serie;
        int nota;
        friend class Serie;
    public:
        Student(std :: string nume,char serie, int nota): Persoana(nume),serie(serie), nota(nota){
            
        }
        // void display(){
            
        // }
};

class Serie {
    private:
        char serie;
        Student* p_studenti;
        int nr_studenti;
    public:
        Serie(char serie, Student* p_studenti, int nr_studenti ): serie(serie), p_studenti(p_studenti), nr_studenti(nr_studenti) {
            
        }
        // void display(){
            
        // }
        int nota_max(){
            int maxi = -1;
            for (int i = 0; i < nr_studenti; ++i) {
                if (this -> serie == p_studenti[i].serie) {
                    if (maxi < p_studenti[i].nota)
                        maxi =  p_studenti[i].nota;
                    // maxi = max(maxi, p_studenti[i].nota);
                }
            }
            return maxi;

        }
        float nota_medie(){
           float ma = 0;
           int nr = 0;
            for (int i = 0; i < nr_studenti; ++i) {
                if (this -> serie == p_studenti[i].serie) {
                    nr++;
                    ma += p_studenti[i].nota;
                }
            }
            ma = (float) ma / nr;
            return ma;
        }
    
};

int main(){
    Student studenti[] = {Student("Costache", 'A', 9),
                          Student("Dobre", 'B', 10),
                          Student("Enache", 'A', 8),
                          Student("Faur", 'A', 5),
                          Student("Georgescu", 'B', 2),
                          Student("Harapu", 'A', 10),
                          Student("Ionescu", 'C', 7),
                          Student("Jianu", 'B', 9),
                          Student("Konstantinos", 'A', 10),
                          Student("Laica", 'B', 3),
                          Student("Manea", 'A', 9)};
    Serie s('A', studenti, sizeof(studenti)/ sizeof(Student));
    
    std :: cout << s.nota_max() << std :: endl;
    std :: cout << s.nota_medie() << std :: endl;
    
    return 0;
}
