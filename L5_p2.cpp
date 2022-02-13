/*
Să se scrie un program care afișează pe ecran numele studentului cu cea mai mare medie a notelor.

Se citesc de la tastatură:

un întreg, reprezentând numărul de studenți ce urmează a fi inițializați; pentru fiecare student se citesc:
un std::string, reprezentând numele studentului;
un întreg, n, reprezentând numărul de note ce urmează a fi citit de la tastatură;
n întregi reprezentând notele studentului;
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

class Student {
    private:
     std :: string nume;
     int *note;
     int n;
   
    public:
     Student(std :: string nume, int *note, int n) : nume(nume), note(note), n(n) {}
     
     float get_media(){
         int  s = 0;
         for (int i = 0; i < n; ++i) {
             s = s + note[i];}
             return (float) s / n;
     }
     friend bool compare(Student &,  Student &);
     std :: string get_string(){
         return nume;
     }
    
};
 bool compare( Student &s1,  Student &s2){
     return (s1.get_media() > s2.get_media());
     
 }
int main()
{
    int nr_studenti;
    std :: string nume;
    int nr_note;
    int x;
    
    std :: cin >> nr_studenti;
    
    std :: vector<Student> student;
    
    for (int i = 0; i < nr_studenti; ++i) {
        std :: cin >> nume;
        std :: cin >> nr_note;
        
        int *note = new int [nr_note];
        for (int j = 0; j < nr_note; ++j) {
              std :: cin >> x;
              note[j] = x;
          }
        student.push_back(Student(nume, note, nr_note));
    }
    
    std :: sort(student.begin(), student.end(), compare);
    std :: cout << (student.begin()) -> get_string();
       
return 0;
}
