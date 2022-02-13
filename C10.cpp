#include <algorithm>
#include <vector>
#include <iostream>

class Student{
private:
    std::string nume;
    std::vector<int> note;
public:
    Student(std::string nume, std::vector<int> var_note):nume(nume), note(std::move(var_note)){}
    

    void afisare_1(){ 
        for (std::vector<int>::iterator it = note.begin(); it != note.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";
    }

    void afisare_2(){ 
        for (auto s : note){
            std::cout << s << " ";
        }
        std::cout << "\n";
    }

    void increment_1(){ 
        for (std::vector<int>::iterator it = note.begin(); it != note.end(); ++it) {
            (*it)++;
        }
    }

    void increment_2(){ 
        for (auto &s : note){
            s++;
        }
    }
};
int main()
{
    std::vector<int> vec;
    vec.push_back(15);
    vec.push_back(20);
    vec.push_back(7);
    vec.push_back(13);

    Student s("John", vec); 
    s.afisare_1();          
    s.increment_1();        
    s.afisare_2();          

    Student b("Jack", vec); 
    b.afisare_1();          

    return 0;
}
