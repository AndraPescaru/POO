#include <iostream>

class Card{
   private :
        float sold_card = 0;
            
   public:
        friend class Profil;
        Card(){

        }
        Card(float valoare_sold){
            this -> sold_card = valoare_sold;
        }
        float getSold_card(){
            return this -> sold_card;
        }
        void addSold_card(float value){
            this -> sold_card += value;
        }
        void substractSold_card(float value){
            this -> sold_card -= value;
        }
};

class Cont_economii{
    private :
        float sold_economii = 0;
        float dobanda = 0;
    public:
        friend class Profil;
        Cont_economii(){

        }
        Cont_economii(float valoare_economii, float dobanda){
            this -> sold_economii = valoare_economii;
            this -> dobanda = dobanda;
        }
        float getSold_economii(){
            return this -> sold_economii;
        }
        float getDobanda(){
            return this -> dobanda;
        }
        void addSold_economii(float value){
            this -> sold_economii += value;
            this -> sold_economii *= (dobanda / 100 + 1);
        }
        void substractSold_economii(float value){
            this -> sold_economii -= value;
        }
};


class Profil{
    private:
        std :: string nume;
        Card card;
        Cont_economii cont_economii;
    public:
        Profil(std :: string vnume, Card card, Cont_economii cont_economii){
            this -> nume = vnume;
            this -> card = card;
            this -> cont_economii = cont_economii;
        }
        std :: string getName(){
            return this -> nume;
        }
        class Card getCard(){
            return this -> card;
        }
        class Cont_economii getCont_economii(){
            return this -> cont_economii;
        }
};





int main(){
    
    std :: string vnume_titular;
    std :: getline(std :: cin, vnume_titular);
    
    float vsold_card;
    std :: cin >> vsold_card;
    
    float vsold_economii;
    std :: cin >> vsold_economii;
    
    float vdobanda;
    std :: cin >> vdobanda;
    
    int vcomanda;
    std ::  cin >> vcomanda;

    Card card = Card(vsold_card);
    Cont_economii cont_economii(vsold_economii, vdobanda);
    Profil utilizator(vnume_titular, card, cont_economii);

    if(vcomanda == 1){
        std :: cout << utilizator.getName();
        std :: cout << std :: endl;
        std :: cout << "card_bancar:" << std :: endl;
        std :: cout << utilizator.getCard().getSold_card() << std :: endl;
        std :: cout << "cont_economii:" << std :: endl;
        std :: cout << utilizator.getCont_economii().getSold_economii() << std :: endl;
        std :: cout << utilizator.getCont_economii().getDobanda() << std :: endl;
    }
    if(vcomanda == 2){
        float suma;
        bool ok = 1;
        std :: cin >> suma;
        if(suma < 0){
            std :: cout << "EROARE: depunere suma negativa";
            ok = 0;
        }
        if(ok){
             card.addSold_card(suma);
             utilizator.getCard().addSold_card(suma);
             std :: cout << "card_bancar:" << std :: endl;
             std :: cout << card.getSold_card() << std :: endl;
        }
    }
    if(vcomanda == 3){
        float suma;
        bool ok = 1;
        std :: cin >> suma;
        if(suma > card.getSold_card()){
            std :: cout << "EROARE: fonduri insuficiente";
            ok = 0;
        }
        if(ok){
            utilizator.getCard().substractSold_card(suma);
            std :: cout << "card_bancar:" << std :: endl;
            std :: cout << utilizator.getCard().getSold_card() << std :: endl;
        }
    }
    if(vcomanda == 4){
        float suma;
        bool ok = 1;
        std :: cin >> suma;
        if(suma > card.getSold_card()){
            std :: cout << "EROARE: fonduri insuficiente";
            ok = 0;
        }
        if(ok){
            card.substractSold_card(suma);
            utilizator.getCard().substractSold_card(suma);
            cont_economii.addSold_economii(suma);
            utilizator.getCont_economii().addSold_economii(suma);
             std :: cout << "card_bancar:" << std :: endl;
            std :: cout << card.getSold_card() << std :: endl;
            std :: cout << "cont_economii:" << std :: endl;
            std :: cout << cont_economii.getSold_economii() << std :: endl;
            std :: cout << cont_economii.getDobanda() << std :: endl;
        }
    }
    if(vcomanda == 5){
        float value;
        std :: cin >> value;
        float have = cont_economii.getSold_economii();
        float dobanda = cont_economii.getDobanda();
        int nr_luni = 0;
        while(have < value){
            have = have * (dobanda / 100 + 1);
            ++nr_luni;
        } 
        std :: cout << nr_luni;
    }


    
    return 0;
}
