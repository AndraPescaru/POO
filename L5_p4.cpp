#include<iostream>
#include<vector>
/*
Să se scrie un program care ordonează o secvență de maxim 20 de numere complexe.

Se va citi de la tastatură un număr întreg reprezentând numărul de numere complexe ce urmează a fi citit. Ulterior, de pe fiecare linie se citesc 2
valori reale, reprezentând partea reală, respectiv partea imaginară, separate de un spațiu.

Să se afișeze pe ecran numerele complexe ordonate, câte unul pe linie. Afișarea unui număr complex se face sub forma "<partea_reala> <partea_imaginara>".
*/
#include<cmath>
#include<algorithm>
class Complex{
    private:
    float re, im;
    public:
    Complex(float re=0,float im=0){
        this->re=re;
        this->im=im;
    }
    void afisare(){
        std::cout<<re<<" "<<im<<std::endl;
    }
    float modul() const{
        return sqrt(this->re*this->re+this->im*this->im);
    }
    bool operator<(const Complex &c){
        return(this->modul()<(c.modul()));
    }
};
int main(){
    std::vector<Complex> numere;
    int n;
    float temp_re, temp_im;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>temp_re>>temp_im;
        numere.push_back(Complex(temp_re,temp_im));
    }
    std::sort(numere.begin(),numere.end());
    for(Complex c:numere){
        c.afisare();
    }
    return 0;
}
