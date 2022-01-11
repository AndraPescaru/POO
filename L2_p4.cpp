#include <iostream>
#include <string.h>

class Mail_box {
    
  private:
    std :: string adresa_mail;
    int capacitate;
    
  public:
    Mail_box() {
        
    };
    Mail_box(std :: string adresa_mail, int capacitate ) {
        this -> adresa_mail = adresa_mail;
        this -> capacitate = capacitate;
    }
    
    void set_adresa_mail(std :: string adresa_mail) {
        this -> adresa_mail = adresa_mail;
    }
    
    std :: string get_adresa_mail() {
        return this -> adresa_mail;
    }
  
};

class Mail {
    
    private:
        std :: string sender;
        std :: string recipient;
        std :: string subject;
        std :: string body;
        
    public:
        Mail() {
            
        };
        Mail(std :: string sender,std ::  string recipient,std :: string subject,std :: string body) {
            this -> sender = sender;
            this -> recipient = recipient;
            this -> subject = subject;
            this -> body = body;
        }
        
        void set_sender(std :: string sender) {
            this -> sender =  sender;
        }
        
        std :: string  get_sender() {
            return this -> sender;
        }
        
        void set_recipient(std ::  string recipient) {
            this -> recipient =  recipient;
        }
        
        std ::  string  get_recipient() {
            return this -> recipient;
        }
        
        void set_subject( std :: string subject) {
            this -> subject = subject;
        }
        
        std :: string get_subject() {
             return this -> subject;
        }
        
        void set_body( std :: string body) {
            this -> body;
        }
        
        std :: string get_body() {
            return this -> body;
        }
        
        void display() {
            std :: cout << "From:" << this -> sender << '\n';
            std :: cout << "To:" << this -> recipient << '\n';
            std :: cout << "Subject:" << this -> subject << '\n';
            std :: cout << "Body:" << this -> body << '\n';
        }
};

int main() {
    
    std :: string c_adresa_mail;
    std :: getline(std :: cin, c_adresa_mail);
    
    int c_capacitate;
    std :: cin >> c_capacitate;
    int nr_mesaje_primite;
    std :: cin >> nr_mesaje_primite;
    
    Mail_box M(c_adresa_mail, c_capacitate);
    
    Mail v[100];
    
    for (int i = 1; i <= nr_mesaje_primite; ++i) {
        std :: string c_sender;
        std :: getline(std :: cin, c_sender);
        std ::  string c_recipient;
        std :: getline(std :: cin, c_recipient);
        std :: string c_subject;
        std :: getline(std :: cin, c_subject);
        std :: string c_body;
        std :: getline(std :: cin, c_body);
        
        v[i] = Mail( c_sender, c_recipient, c_subject, c_body);
        
    }
    
    int comanda;
    
    std :: cin >> comanda;
 
    
    if (comanda == 1) {
      
        
        for (int i = 1; i <= nr_mesaje_primite; ++i) {
            
            if (M.get_adresa_mail() == v[i].get_recipient()) {
               std :: cout << "Index:" << i - 1<< '\n';
               v[i].display();
               std :: cout << "---" << '\n';
            }
        }
    }
    
    return 0;
}
