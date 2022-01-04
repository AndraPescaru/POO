/*
Să se scrie două clase distincte, Vector și Matrice care să conțină drept date membre un vector de maxim 20 de întregi, respectiv un tablou bidimensional, de dimensiune maximă 20 x 20. Se vor scrie constructorii aferenți celor 2 clase și o funcție membră de afișare a elementelor (cel puțin pentru clasa Vector). Se va scrie o funcție de tip friend care să execute înmulțirea dintre un Vector și o Matrice. Funcția va verifica mai întâi dacă operația poate avea loc (numărul de coloane ale vectorului să coincidă cu numărul de linii ale matricei). În caz contrar, va afișa mesajul “EROARE” pe ecran. Vectorul este considerat de tipul linie. Toate inițializările din constructori vor fi făcute cu ajutorul listei de inițializare.
Se citesc de la tastatură, de pe linii diferite, următoarele date:

un întreg n, reprezentând numărul de elemente ale vectorului;

n valori întregi, reprezentând valorile vectorului;

doi întregi, m și n, reprezentând numărul de linii, respectiv coloane ale matrice;

m x n valori întregi, reprezentând valorile matricei.

Se va afișa pe ecran rezultatul obținut în urma înmulțirii vectorului cu matricea, respectiv "EROARE", în cazul în care înmulțirea nu poate avea loc.

Extensie: funcția friend va întoarce în programul apelant un obiect de tipul Vector drept rezultat.
Extensie 2: atât Vectorul, cât și Matricea, vor stoca valorile în mod dinamic.
Extensie 3: separați declarațiile claselor și definițiile funcțiilor membre în fișiere diferite. Notă: trebuie avute în vedere declarațiile în avans (forward declaration) ale claselor și a funcției friend - discutăm împreună.
*/
#include <iostream>

class Vector {
    
    private:
        int *v;
        int n;
        
    public:
        
        Vector(int *v, int n) {
            this -> n = n;
            this -> v = new int[n];
            for (int i = 0; i < n; ++i) {
                *(this -> v + i) = *(v + i);
            }
        }
        void display() {
            for (int i = 0; i < this -> n; ++i) {
                std :: cout << *(v + i) << " ";
            }
            std :: cout << std :: endl;
        }
        int *getVector(){
            return v;
        } 
        friend void inmultire(int *v, int **m, int n, int nn, int mm, int *vv, int mesaj);
};

class Matrice {
    
    private:
        friend class Vector;
        int **m;
        int nn, mm;
        
    public:
    Matrice(int **m, int nn, int mm) {
        this -> nn = nn;
        this -> mm = mm;
        this -> m = (int **)malloc(nn * sizeof(int *));
        
        for (int i = 0; i < nn; ++i) {
            this -> m[i] = (int *)malloc(mm * sizeof(int));
        }
        
        for (int i = 0; i < nn; ++i) {
		    for (int j = 0; j < mm; ++j) {
			    this -> m[i][j] = m[i][j];
		    }
	    }
    }
    int **getMatrice(){
        return m;
    }
    
};

void inmultire(int *v, int **m, int n, int nn, int mm, int *vv, int &mesaj) {
            mesaj = 1;
            if (n != nn) {
                mesaj = 0;
            } else {
                for (int i = 0; i < mm; ++i) {
                    int sum = 0;
                    for(int j = 0; j < n; ++j) {
                       
                        sum += v[j] * (m[j][i]);
                    }
                    std :: cout << std :: endl;
                    *(vv + i) = sum;
                }
            }
}

int main() {
    
    int n, mm, nn, *v, **m;
    
    std :: cin >> n;
    v = new int[n];
    for (int i = 0; i < n; ++i) {
        std :: cin >> v[i];
    }
    std :: cin >> nn >> mm;
    m = (int **)malloc(nn * sizeof(int *));
        
    for (int i = 0; i < nn; ++i) {
        m[i] = (int *)malloc(mm * sizeof(int));
    }
        
    for (int i = 0; i < nn; ++i) {
	    for (int j = 0; j < mm; ++j) {
		     std :: cin >> m[i][j];
	    }
	}

    Vector V(v,n);
    Matrice M(m,nn,mm);

    int *vv = new int[n];
    int mesaj = 1;

    inmultire(V.getVector(), M.getMatrice(), n, nn, mm, vv, mesaj);
    
    if (mesaj) {
      for(int i = 0; i < mm; ++i)
         std :: cout << vv[i] << " ";
    } else {
        std :: cout << "EROARE";
    }
    
    return 0;
}
