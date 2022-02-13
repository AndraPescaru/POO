#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <cmath>

class MathFunction {
protected:
    std :: string function_name;
public:
    MathFunction(std :: string function_name = "") : function_name(function_name) {}
    virtual float get_value(int nr) = 0;
    virtual float get_max_value(int a, int b) = 0;
    virtual void afisare() = 0;
    virtual std :: string get_nume() = 0;
    virtual void print_roots() = 0;
    
};

class Polynomial : public MathFunction {
protected:
    int nr_termeni;
    float* coefficients;
public:
    std :: string get_nume() {
        return function_name;
    }
    Polynomial(std :: string function_name, int nr_termeni, float* coefficients) : MathFunction(function_name), nr_termeni(nr_termeni), coefficients(coefficients) {}
    
    void afisare() {
        std :: cout << function_name << "\n";
        std :: cout << "f(x) = ";
        for (int i = 0; i < nr_termeni; ++i) {
            if (( i == 0) && (*(coefficients) != 0))
            std :: cout << *(coefficients);
            if ((i == 0) && (*(coefficients) == 0))
            i++;
            
            if ((i == 1) && (*(coefficients + 1) > 0) && (*(coefficients + 1) != 1))
            std :: cout << " + " << *(coefficients + 1) << "x";
            if ((i == 1) && (*(coefficients + 1) > 0) && (*(coefficients + 1) == 1))
            std :: cout << " + " << "x";
            if ((i == 1) && (*(coefficients + 1) < 0) && (*(coefficients + 1) != -1))
            std :: cout << " - " << *(coefficients + 1) << "x";
            if ((i == 1) && (*(coefficients + 1) < 0) && (*(coefficients + 1) == -1))
            std :: cout << " - " << "x";
            
            if ((i > 1 ) && (*(coefficients + i) > 0) && (*(coefficients + i) != 1))
            std :: cout << " + " << *(coefficients + i) << "x^" << i;
            if (( i > 1) && (*(coefficients + i) > 0) && (*(coefficients + i) == 1))
            std :: cout << " + " << "x^" <<i;
            if ((i > 1) && (*(coefficients + i) < 0) && (*(coefficients + i) != -1))
            std :: cout << " - " << *(coefficients + i) << "x^" << i;
            if ((i > 1) && (*(coefficients + i) < 0) && (*(coefficients + i) == -1))
            std :: cout << " - " << "x^" << i;
            
        }
        std :: cout << std :: endl;
    }
    void print_roots() {
        std :: cout << "Suprascriere1";
    }
    
    float get_max_value(int a, int b) {
        float max = 0;
        float valoare_functie;
        
        //3 + x + 4*x^2 
        
        for (int i = a; i <= b; ++i) {
            valoare_functie = 0;
            for(int j = 0; j < nr_termeni; ++j) {
                valoare_functie += (*(coefficients + j)) * pow(i, j);
            }
            
            if (valoare_functie > max)
            max = valoare_functie;
        }
        
        return max;
    }
    
    float get_value(int nr) {
        float value = 0;
        
        for (int i = 0; i < nr_termeni; ++i)
            value += (*(coefficients + i)) * pow(nr, i);
        
        return value;
    }
};

class Quadratic: public Polynomial {
public:
    Quadratic(std :: string function_name, int nr_termeni, float* coefficients) : Polynomial(function_name, nr_termeni, coefficients) {}
    std::string get_nume() {
        return function_name;
    }
    void afisare() {
        std :: cout << function_name << "\n";
        std :: cout << "f(x) = ";
        for (int i = 0; i < nr_termeni; ++i) {
            if ((i == 0) && (*(coefficients) != 0))
            std :: cout << *(coefficients);
            if ((i == 0) && (*(coefficients) == 0))
            i++;
            
            if ((i == 1) && (*(coefficients + 1) > 0) && (*(coefficients + 1) != 1))
            std :: cout << " + " << *(coefficients + 1) << "x";
            if ((i == 1) && (*(coefficients + 1) > 0) && (*(coefficients + 1) == 1))
            std :: cout << " + " << "x";
            if ((i == 1) && (*(coefficients + 1) < 0) && (*(coefficients + 1) != -1))
            std :: cout << " - " << *(coefficients + 1) << "x";
            if ((i == 1) && (*(coefficients + 1) < 0) && (*(coefficients + 1) == -1))
            std :: cout << " - " << "x";
            
            if ((i > 1) && (*(coefficients + i) > 0) && (*(coefficients + i) != 1))
            std :: cout << " + " << *(coefficients + i) << "x^" << i;
            if ((i > 1) && (*(coefficients + i) > 0) && (*(coefficients + i) == 1))
            std :: cout << " + " << "x^" <<i;
            if (( i > 1) && (*(coefficients + i) < 0) && (*(coefficients + i) != -1))
            std :: cout << " - " << *(coefficients + i) << "x^" << i;
            if ((i > 1) && (*(coefficients + i) < 0) && (*(coefficients + i) == -1))
            std :: cout << " - " << "x^" << i;
            
        }
        std :: cout << std :: endl;
    }
    
    void print_roots() {
        float a, b, c, delta, X1, X2;
        c = *(coefficients);
        b = *(coefficients + 1);
        a = *(coefficients + 2);
      
        
        delta = b * b - 4 * a * c;
        
        if (delta == 0) {
            X1 = -b / (2 * a);
            std :: cout << "X1 = X2 = " << std :: fixed << std :: setprecision(2) << X1 << std :: endl;
        } else { 
            X2 = (-b - sqrt(delta)) / (2 * a);
            X1 = (-b + sqrt(delta)) / (2 * a);
            std :: cout << "X1 = " << std :: fixed << std :: setprecision(2) << X1 << std :: endl;
            std :: cout << "X2 = " << std :: fixed << std :: setprecision(2) << X2 << std :: endl;
        }
    }
    
    float get_max_value(int a, int b) {
        float max = 0;
        float valoare_functie;
        
        //3 + x + 4*x^2 
        
        for (int i = a; i <= b; ++i) {
            valoare_functie = 0;
            for(int j = 0; j < nr_termeni; ++j) {
                valoare_functie += (*(coefficients + j)) * pow(i, j);
            }
            
            if (valoare_functie > max)
            max = valoare_functie;
        }
        
        return max;
    }
    
    float get_value(int nr) {
        float value = 0;
        
        for (int i = 0; i < nr_termeni; ++i)
            value += (*(coefficients + i)) * pow(nr, i);
        
        return value;
    }
};

class Exponential : public MathFunction{
private:
    const float e = 2.71;
    float constant;
    float exp_coeff;
public: 
    std :: string get_nume() {
        return function_name;
    }
    Exponential(std :: string function_name = "", const float e = 2.71, float constant = 0 , float exp_coeff = 0) : MathFunction(function_name), e(e), constant(constant), exp_coeff(exp_coeff){}
    void afisare() {
        std :: cout << function_name << "\n";
        std :: cout << "f(x) = ";
        std :: cout << constant << " + " << exp_coeff << "e^x" << std :: endl;
        
    }
    void print_roots() {
        std :: cout << "Suprascriere2";
    }
    
    float get_max_value(int a, int b) {
        float max = 0;
        float valoare_functie;
        
        for (int i = a; i <= b; ++i) {
            valoare_functie = 0;
            valoare_functie += constant + pow(e, i);
            if (valoare_functie > max)
            max = valoare_functie;
        }
        
        return max;
    }
    
    float get_value(int nr) {
        float value = 0;
        value += constant + pow(e, exp_coeff);
        return value;
    }
};

class DiscreteFunction : public MathFunction{
private:
    float* x_values;
    float* y_values;
public:
    DiscreteFunction(float* x_values, float* y_values) : x_values(x_values), y_values(y_values) {}
    float get_value(int nr) {return 1;}
    float get_max_value(int a, int b) {return 1;}
    void afisare() {}
    std :: string get_nume(){return function_name;}
    void print_roots() {}
    float suma_diferentelor(MathFunction *f) {
        float suma_valori_absolute = 0;
        for (int i = 0; i < 3; ++i)
            suma_valori_absolute += abs(*(y_values + i) - f -> get_value(*(x_values + i)));
        return suma_valori_absolute;
    }
    
    
};

int main() {
    
    std :: string nume;
    int nr_functii, nr_termeni;
    float* coefficients;
    const float e = 2.71;
    float constant;
    float exp_coeff;
    int comanda;
    float* x_values;
    float* y_values;
    
    x_values = new float[3];
    y_values = new float[3];
    
    std :: cin >> nr_functii;
    
    std :: vector<MathFunction*> functii;
    
    for (int i = 0; i < nr_functii; ++i) {
        std :: cin >> nume;
        if (nume == "Polynomial") {
            std :: cin >> nr_termeni;
            coefficients = new float [nr_termeni];
            for (int j = 0; j < nr_termeni; ++j) {
                std :: cin >> *(coefficients + j);
            }
            functii.push_back(new Polynomial(nume, nr_termeni, coefficients));
        }
        
        if (nume == "Quadratic") {
            coefficients = new float [3];
            for (int j = 0; j < 3; ++j) {
                std :: cin >> *(coefficients + j);
            }
            functii.push_back(new Quadratic(nume, 3, coefficients));
        }
        
        if(nume == "Exponential"){
            std :: cin >> constant >> exp_coeff;
            functii.push_back(new Exponential(nume, e, constant, exp_coeff));
        }
    }
    
    std::cin >> comanda;
    
    switch(comanda) {
        case 1:
            for(MathFunction* f : functii)
                f -> afisare();
        break;
            
        case 2:
            for(MathFunction* f : functii)
                if (f -> get_nume() == "Quadratic")
                    f -> print_roots();
        break;
        
        case 3:
            int a, b;
            std :: cin >> a >> b;
            for (MathFunction* f : functii)
                std :: cout << std :: fixed << std :: setprecision(2) << f -> get_max_value(a, b) << std :: endl;
        break;
        
        case 4:
            for (int i = 0;  i < 3; ++i)
                std :: cin >> *(x_values + i);
            for (int i = 0; i < 3; ++i)
                std :: cin >> *(y_values + i);
    }
    

    return 0;
}
