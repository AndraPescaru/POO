#include <iostream>
#include <string.h>
#include <iomanip>
#include <cmath>

class Segment {
    private:
    float x, x1, y, y1, z, z1;

    public:

    Segment(float x, float x1, float y, float y1, float z, float z1) {
        this -> x = x;
        this -> x1 = x1;
        this -> y = y;
        this -> y1 = y1;
        this -> z = z;
        this -> z1 = z1;
    }

    float distanta(float x, float x1, float y, float y1, float z, float z1) {
        return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1) + (z - z1) * (z - z1) );
    }

    void set_x(float x) {
        this -> x = x;
    }
    float get_x() {
        return this -> x;
    }
    void set_y(float y) {
        this -> y = y;
    }
    float get_y() {
        return this -> y;
    }
    void set_z(float z) {
        this -> z = z;
    }
    float get_z() {
        return this -> z;
    }
    void set_x1(float x1) {
        this -> x1 = x1;
    }
    float get_x1() {
        return this -> x1;
    }
    void set_y1(float y1) {
        this -> y1 = y1;
    }
    float get_y1() {
        return this -> y1;
    }
    void set_z1(float z1) {
        this -> z1 = z1;
    }
    float get_z1() {
        return this -> z1;
    }
};

int main() {
    float xx, xx1, yy, yy1, zz, zz1;
    std :: cin >> xx >> yy >> zz >> xx1 >> yy1 >> zz1;

    Segment s(xx, xx1, yy, yy1, zz, zz1);
    float d = s.distanta(s.get_x(), s.get_x1(), s.get_y(), s.get_y1(), s.get_z(), s.get_z1());

    std :: cout << std :: fixed;
    std :: cout << std :: setprecision(2);
    

    return 0;
    
}
