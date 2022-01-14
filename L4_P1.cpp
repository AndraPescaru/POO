#include <iostream>
#include <string>

class Entity {
protected:
    std::string name;
public:
    Entity(std::string name): name(name){std::cout << "Ctor Entity" << std::endl;}
    virtual void display(){
        std::cout << "Entity name: " << name << std::endl;
    }
};

class Person: public Entity {
protected:
    int age;
public:
    Person(std::string name, int age): Entity(name), age(age){std::cout << "Ctor Person" << std::endl;}
    void display(){
        std::cout << "Entity name: " << name << std::endl;
    }
};

class Student: public Person {
private:
    char serie;
public:
    Student(std::string name, int age, char serie): Person(name, age), serie(serie){std::cout << "Ctor Student" << std::endl;}
    void display(){
        std::cout << "Entity name: " << name << std::endl;
    }
};

int main(){
    Entity e1("Entity 1");
    Person p1("Person 1", 34);
    Student s1("Student 1", 21, 'B');

    std::cout << std::endl;

    Entity *p_entity[3] = {&e1, &p1, &s1};
    for (int i=0; i<3; i++){
        p_entity[i]->display();
    }

    return 0;
}
