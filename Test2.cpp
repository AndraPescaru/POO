#include<iostream>
#include <string.h>

class MathFunction {
    protected:
        std :: string function_name;
    public:
        void get_value();
        float get_max_value(int x, int y);
        void setFuncionName(std :: string funcion_name) {
            this -> function_name = function_name;
        }
};

class Polynomial : public MathFunction {
    protected:
        float coefficents[100];
        int nr;
    public:
        Polynomial(int nr, float coefficents[100]) {
            this -> nr = nr;
            for (int i = 1; i <= nr; ++i) {
                this -> coefficents[i] = coefficents[i];
            }
        }
        void get_value() {
            std :: cout << "Alex";
        }
    
};

class Quadratic : public Polynomial {
    public:
        Quadratic(int nr, float coefficients[100]) : Polynomial(nr, coefficients) {
            
        }
        void print_roots() {

        }
        void get_value() {
            std :: cout << "Maria";    
        }
};

class Exponential : public MathFunction {
    private:
        const float e =  2.71;
        float constant;
        float exp_coeff;
    public:
        Exponential(float constant, float exp_coeff) {
            this -> constant = constant;
            this -> exp_coeff = exp_coeff;
        }
        void get_value() {

        }
};

class DiscreteFunction : public MathFunction {
    private:
        float x[100];
        float y[100];
    public:
        std :: string find_best_approximation() {
            std :: string t;
            return t;
        }
        void get_value() {

        }
};



int main() {
    
    MathFunction F[100];
    float coef[10];
    Polynomial P(2, coef);

    int nr_functii;
    std :: cin >> nr_functii;
    std :: string name;
    
    for (int i = 1; i <= nr_functii; ++i) {
        std :: cin >> name;
        
        if (name == "Polynomial") {
            int nr_coeficienti;
            float coef[100];
            std :: cin >> nr_coeficienti;

            for (int j = 1; j <= nr_coeficienti; ++j) {
                std :: cin >> coef[j];
            }

            Polynomial P = Polynomial(nr_coeficienti, coef);
            F[i] = P;
            F[i].setFuncionName(name);
        }
        if (name == "Quadratic") {
            int nr_coeficienti = 3;
            float coef[100];
            for (int j = 1; j <= nr_coeficienti; ++j) {
                std :: cin >> coef[j];
            }
            Quadratic Q = Quadratic(nr_coeficienti, coef);
            F[i] = Q;
            F[i].setFuncionName(name);
        }
        if (name == "Exponential") {
            float constant;
            float exp_coef;
            std :: cin >> constant >> exp_coef;
            Exponential E = Exponential(constant, exp_coef);
            F[i] = E;
            F[i].setFuncionName(name);
        }
        if (name == "DiscreteFunction") {

        }
    }

    int tip_comanda;
    std :: cin >> tip_comanda;
    if (tip_comanda == 1) {
        for (int i = 1; i <= nr_functii; ++i) {
            //F[i].get_value();
        }
    }


    return 0;
}
