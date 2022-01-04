/*
Cerinta :Pentru clasa Punctaj se va defini un destructor, un constructor de copiere și o funcție membră care modifică nota de la un index dat. Se va instanția un obiect de tip Punctaj folosind constructorul cu 2 parametri, se va crea o nouă instanță prin copierea acestuia, se va modifica nota de la un anumit index cu o nouă valoare citită de la tastatură, după care se vor afișa pe ecran notele celui de-al doilea obiect.

Se va apela în mod explicit destructorul primului obiect, după care se vor afișa din nou pe ecran notele celui de-al doilea obiect.

Comentați constructorul de copiere și repetați pașii de mai sus.
*/

#include <iostream>
#include <string.h>

class Punctaj {
    private:
    int nr_note;
    int *note;

    public:

    Punctaj(int nr_note, int *note) {
        this -> nr_note = nr_note;
        this -> note = new int[nr_note];
        for (int i = 0; i < nr_note; ++i) {
            *(this -> note + i) = *(note + i);
        }

    }

    Punctaj(Punctaj &copie) {
        this -> nr_note = copie.nr_note;
        this -> note = new int[nr_note];
        for (int i = 0; i < nr_note; ++i) {
            *(this -> note + i) = *(copie.note + i);
        }
    }

    void display() {
        for (int i = 0; i < nr_note; ++i) {
            std :: cout << *(note + i) << " ";
        }
        std :: cout << std :: endl;
    }

    void modificare_note(int valoare, int index) {
        for (int i = index - 1; i < nr_note; ++i) {
            *(note + i) += valoare;
        }
    }
};

int main() {
    int v_nr_note, v_valoare, v_index;
    std :: cin >> v_nr_note;
    int *v_note = new int[v_nr_note];

    for (int i = 0; i < v_nr_note; ++i) {
        std :: cin >> *(v_note + i);
    }

    std :: cin >> v_valoare;
    std :: cin >> v_index;

    Punctaj s1(v_nr_note,v_note);
    Punctaj s2(s1);
    s1.display();
    s2.display();
    s2.modificare_note(v_valoare, v_index);
    s2.display();

    return 0;
    
}
