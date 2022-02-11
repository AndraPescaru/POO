#include <iostream>

class Complex {
    private:
        float re;
        float im;
    public:
        Complex(float re = 0, float im = 0):re(re), im(im){}
        Complex operator+(const Complex &c){
            return Complex(this -> re + c.re, this -> im + c.im);
        }
        Complex operator/(double scalar) {
            if (scalar != 0){
                return Complex(this -> re / scalar, this -> im / scalar);
            } else {
                std::cout << "Impartire la 0";
                exit(1);
            }
        }
    void afisare() {
        std::cout << this -> re << " + i*"<< this -> im;
    }
};
int main() {

    float re;
    float im;

    std::cin >> re >> im;

    Complex c1(re, im);

    std :: cin >> re >> im;

    Complex c2(re, im);

    ((c1 + c2) / 2.0).afisare();

    return 0;
}
