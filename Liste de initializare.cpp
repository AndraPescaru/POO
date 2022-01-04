#include <iostream>
#include <string.h>
#include <iomanip>
#include <cmath>
class Exemple {
    private:
        int m;
        int &r;
        const int c;
    public:
        // lista de initializare 
        Exemple(int m, int &referinta, const int constanta):m(m), r(referinta), c(constanta){}

        void display()  {
            std::cout << "m:" << m << std::endl;
            std::cout << "r:" << r << std::endl;
            std::cout << "c:" << c << std::endl;
        }
};

int main() {

    int a = 20;
    const int b = 30;

    Exemple e(10, a, b);
    e.display();

    return 0;
}
