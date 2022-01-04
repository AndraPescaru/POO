// Vectori geometrici in spatiu cartezian 2D
// 2 perechi de coordonate (x,y)

#include <iostream>
#include <cmath>

class Vector;

class Point{
private:
    friend class Vector;
    int x;
    int y;
public:
    Point(int x=0, int y=0):x(x),y(y){}
    friend Vector rezultanta_friend(Vector v1, Vector v2);
};

class Vector {
private:
    Point p1;
    Point p2;
public:
    // Constructor:
    Vector(int x1=0, int y1=0, int x2=0, int y2=0):p1(x1, y1), p2(x2, y2){}

    // Functie de afisare a coordonatelor:
    void display(){
        std::cout << "x1=" << p1.x << "\ty1=" << p1.y << std::endl;
        std::cout << "x2=" << p2.x << "\ty2=" << p2.y << std::endl;
    }

    // Functie de mutare a vectorului cu baza in originea sistemului de coordonate:
    void center(){
        // Mutam "sageata" vectorului
        p2.x = p2.x - p1.x;
        p2.y = p2.y - p1.y;
        // Mutam "baza" vectorului
        p1.x = 0;
        p1.y = 0;
    }

    // Functie de inmultire cu un scalar:
    // 1. inmultire "in-place":
    void multiply(int alpha){
        p1.x = p1.x * alpha;
        p1.y = p1.y * alpha;
        p2.x *= alpha;
        p2.y *= alpha;
    }
    // 2. inmultire "out-of-place":
//    Vector multiply (int alpha){
//        return Vector(p1.x*alpha, p1.y*alpha, p2.x*alpha, p2.y*alpha);
//    }

    // Calcul norma vector:
    // sqrt ((x2-x1)^2 + (y2-y1)^2)
    float norma(){
        return std::sqrt(std::pow((p2.x - p1.x), 2) + std::pow((p2.y - p1.y), 2));
    }

    // Calcul rezultanta vector (coordonatele se refera doar la varful sagetii; baza este automat (x1,y1)=(0,0)):
    // V3.x2 = V1.x2 + V2.x2
    // V3.y2 = V1.y2 + V2.y2

    // 1. functie membra a clasei:
    Vector rezultanta(Vector v2){
        // se va apela din V1
        return Vector(0, 0, p2.x + v2.p2.x, p2.y + v2.p2.y);
    }
    // 2. functie care primeste 2 argumente si returneaza un nou Vector:
    friend Vector rezultanta_friend(Vector v1, Vector v2);

};

Vector rezultanta_friend(Vector v1, Vector v2){
    return Vector (0, 0, v1.p2.x + v2.p2.x, v1.p2.y + v2.p2.y);
}

int main(){
    std::cout << "Instantiere:" << std::endl;
    Vector v1(1, 1, 4, 4);
    v1.display();
    std::cout << std::endl;

    std::cout << "Centrare in origine:\n";
    v1.center();
    v1.display();
    std::cout << std::endl;

    std::cout << "Inmultire cu un scalar:\n";
    v1.multiply(5);
    v1.display();
    std::cout << std::endl;

    std::cout << "Calcul norma:\n" << v1.norma();
    std::cout << std::endl << std::endl;

    std::cout << "Calcul rezultanta:\n";
    Vector v2(0, 0, -2, -2);
    Vector v_rezultanta = v1.rezultanta(v2);
	
    std::cout << "Varianta 1:\n";
    v_rezultanta.display();
    std::cout << std::endl;
	
    std::cout << "Varianta 2:\n";
    Vector v_rezultanta_2 = rezultanta_friend(v1, v2);
    v_rezultanta_2.display();

    return 0;
}
