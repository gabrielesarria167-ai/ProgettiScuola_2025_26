#include <iostream>
#include <string>
#include <vector>
#include <limits>
/*
menu con
- crea classe x
- crea studente x
- visualizza classi x
- inserimento studenti x
- modifica classe
- modifica studente
- media generale scolastica
- media classe
- fine
*/

struct Studente{
    std::string nome;
    std::string cognome;
    int eta;
    double media;
};

struct Classe{
    std::vector<Studente> infostudenti;
    std::string nomeclasse;
};

void creaClasse(std::vector<Classe>& v){
    std::cout<<"\nInserire nome classe. Digitare 'fine' per terminare l'inserimento.\n\n";
    while(true){
        Classe classe; 
        std::cout<<"Nome classe: ";
        std::getline(std::cin, classe.nomeclasse);
        for(auto& c: classe.nomeclasse){
            c = toupper(c);
        }
        if(classe.nomeclasse == "FINE"){
            break;
        }
        std::cout<<"Classe generata con successo.\n\n";
        v.push_back(classe);
    }
}

void visualizzaClassi(const std::vector<Classe>& v){
    std::cout<<"Classi:\n\n";
    for(auto& i:v){
        std::cout<<"Classe: "<<i.nomeclasse<<"\nStudenti in "<<i.nomeclasse<<": "<<i.infostudenti.size()<<"\n\n";
    }
}

void modificaClasse(std::vector<Classe>& v, std::vector<Studente> sl){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string nomemodifica;
    std::string creo;
    if(v.size() == 0){
        while(true){
        std::cout<<"\nErrore: classi non esistenti.\nDesideri creare delle classi (si/no)? ";
        std::getline(std::cin, creo);
        for(auto& c:creo){
            c = tolower(c);
        }
        if(creo == "si"){
            creaClasse(v);
            break;
        }
        else if(creo == "no"){
            return;
        }
        else{
            std::cout<<"\nErrore: scelta non valida. Riprovare.\n";
        }
    }
    }
    bool exit = false;
    int idx;
    while (exit == false){
    std::cout<<"\nQuale classe desideri modificare?\n";
    std::getline(std::cin, nomemodifica);
    for(auto& c:nomemodifica){
        c = toupper(c);
    }
    bool valid = false;
    for(size_t i=0; i<v.size(); i++){
        if(nomemodifica == v[i].nomeclasse){
            valid = true;
            idx = i;
            std::cout<<"\nClasse trovata\n";
            exit = true;
            break;
        }
    }
    if(valid == false){
        std::cout<<"\nClasse non esistente\n";
    }
    }
    int choice;
    std::cout<<"\nCosa desideri modificare?\n\n1. Nome classe\n2. Eliminare classe\n3. Rimuovere studente\n\n";
    std::cin>>choice;
    switch(choice){
        case 1: {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string newnomeclasse;
        while(true){
        bool doppio = false;
        std::cout<<"\n\nNomi classi occupati:\n";
        for(size_t i=0; i<v.size(); i++){
            std::cout<<v[i].nomeclasse<<" ";
        }
        std::cout<<"\nInserire nuovo nome della classe: ";
        std::getline(std::cin, newnomeclasse);
        for(auto& c:newnomeclasse){
            c = toupper(c);
        }
        for(size_t i=0; i<v.size(); i++){
            if(v[i].nomeclasse == newnomeclasse){
                std::cout<<"\nErrore: Nome della classe gia occupato. Riprovare.";
                doppio = true;
                break;
            }
        }
        if(doppio == false){
            break;
        }
        }
        v[idx].nomeclasse = newnomeclasse;
        std::cout<<"\nNome classe modificato con successo.\n";
        break;
        }
        
        case 2:{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string sure;
        std::cout<<"\nSei sicuro di voler cancellare una classe intera (si/no)?\nGli studenti al suo interno non avranno piu una classe\n";
        std::getline(std::cin, sure);
        for(auto& c:sure){
            c = tolower(c);
        }
        if(sure == "si"){
        for(size_t i=0; i<v[idx].infostudenti.size(); i++){
            sl.push_back(v[idx].infostudenti[i]);
        }
        v.erase(v.begin() + idx);
        std::cout<<"\nClasse eliminata con successo.\n";
        break;
        }
        else{
            return;
        }
        }


        default:
        return;



    }

}

void creaStudente(std::vector<Studente>& v, std::vector<Studente>& vl){
    Studente s;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"\nInserire dati studente. Digitare 'fine' in nome per terminare l'inserimento.\n";
    while(true){
        std::cout<<"\nNome: ";
        std::getline(std::cin, s.nome);
        for(auto& c: s.nome){
            c = tolower(c);
        }
        if(s.nome == "fine"){
            std::cout<<"\n\n";
            break;
        }
        else{
            s.nome[0] = toupper(s.nome[0]);
        }
        std::cout<<"Cognome: ";
        std::getline(std::cin, s.cognome);
        s.cognome[0] = toupper(s.cognome[0]);
        std::cout<<"Età: ";
        std::cin>>s.eta;
        std::cout<<"Media: ";
        std::cin>>s.media;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //use this after every cin thats before a getline
        v.push_back(s);
        vl.push_back(s);
    }
}

void stampaStudente(const std::vector<Studente>& v){
    std::cout<<"Classe:\n\n";
    for(auto& s: v){
        std::cout<<s.nome<<" "<<s.cognome;
        std::cout<<"\nEtà: "<<s.eta<<"\nMedia scolastica: "<<s.media<<"\n\n";
    }
}

int inserimentoClasse(std::vector<Classe>& v){
    std::string iclasse;
    int indice;
    std::cout<<"\nSeleziona la classe dove inserire lo studente: ";
    std::getline(std::cin, iclasse);
    for(auto& c: iclasse){
        c = toupper(c);
    }
    for(size_t i=0; i<v.size(); i++){
        if (v[i].nomeclasse == iclasse){
            return i;
        }
    }
    return -1;

}



std::pair<std::string, std::string> nomecognome(
    std::vector<Classe>& classi, 
    std::vector<Studente> studenti, 
    std::vector<Studente> studentiliberi)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string nomestudente, cognomestudente;
    std::cout<<"Inserisci il nome dello studente da inserire: ";
    std::getline(std::cin, nomestudente);
    for(auto& c: nomestudente){
        c = tolower(c);
    }
    if(!nomestudente.empty()){
        nomestudente[0] = toupper(nomestudente[0]);
    }
    bool inclass = false;
    for(size_t i=0; i<classi.size(); i++){
        for(size_t j=0; j<classi[i].infostudenti.size(); j++){
            if(nomestudente == classi[i].infostudenti[j].nome){
                std::cout<<"\n"<<classi[i].infostudenti[j].nome<<" "<<classi[i].infostudenti[j].cognome<<" | Classe "<<classi[i].nomeclasse<<"\n\n";
                inclass = true;
            }
        }
    }
    if(!inclass){
        for(size_t i=0; i<studentiliberi.size(); i++){
            if(nomestudente == studentiliberi[i].nome){
                std::cout<<"\n"<<studentiliberi[i].nome<<" "<<studentiliberi[i].cognome<<" | In nessuna classe\n\n";
            }
        }
    }
    std::cout<<"Inserisci il cognome dello studente da inserire: ";
    std::getline(std::cin, cognomestudente);
    for(auto& c:cognomestudente){
        c = tolower(c);
    }
    if(!cognomestudente.empty()){
        cognomestudente[0] = toupper(cognomestudente[0]);
    }
    return {nomestudente, cognomestudente};
}

bool studenteoccupato(std::vector<Studente> studentiliberi, std::pair<std::string, std::string> nomeCognome){
    for(size_t i=0; i<studentiliberi.size(); i++){
        if(studentiliberi[i].nome == nomeCognome.first && studentiliberi[i].cognome == nomeCognome.second){
            return false;
        }
    }
    return true;
}

std::pair<bool,int> ricercastudente(std::vector<Studente>& studente, std::pair<std::string, std::string> nomeCognome){
    for(int i=0; i<studente.size(); i++){
        if(studente[i].nome == nomeCognome.first && studente[i].cognome == nomeCognome.second){
            std::cout<<"\nStudente trovato\n";
            return {true, i};
        }
    }
    return {false, -1};
}



/*
while (true){
     for(size_t i=0; i<studente.size(); i++){
        if(studente[i].nome == comeCognome.first && studente[i].cognome == nomeCognome.second){
            if(first== true){
                std::cout<<"\nStudente trovato\n";
            }
            rifclasse = inserimentoClasse(classe);
            if(rifclasse == -1){
                std::cout<<"\nClasse non esistente\n";
                first = true;
                break;
            }
            else{
                bool found = true;
                bool presente = false;
                for(size_t i=0; i<classe.size(); i++){
                    for(size_t j=0; j<classe[i].infostudenti.size(); j++){
                        if(istudente == classe[i].infostudenti[j].nome && cstudente == classe[i].infostudenti[j].cognome){
                            if(classe[i].nomeclasse == classe[rifclasse].nomeclasse){
                                std::cout<<"\nErrore: lo studente appartiene gia a questa classe. Riprovare\n";
                            }
                            else{
                                std::string prompt;
                                std::cout<<"\nErrore: "<<istudente<<" "<<cstudente<<" appartiene gia ad una classe ("<<classe[i].nomeclasse<<")\n\n";
                                while(true){
                                std::cout<<"Desideri cambiare la classe dello studente (si/no)? ";
                                std::getline(std::cin, prompt);
                                for(auto& c: prompt){
                                    c = tolower(c);
                                }
                                if(prompt == "si"){
                                    classe[rifclasse].infostudenti.push_back(studente[i]);
                                    classe[i].infostudenti.erase(classe[i].infostudenti.begin()+j);
                                    std::cout<<"\nScambio avvenuto con successo.\n";
                                    return;
                                }
                                else if(prompt == "no"){
                                    return;
                                }
                                else{
                                    std::cout<<"Scelta non valida. Riprovare\n";
                                }
                              }
                            }
                            presente = true;
                            first = false;
                            continue;
                        }
                    }
                }
                if(presente == false){
                    classe[rifclasse].infostudenti.push_back(studente[i]);
                    std::cout<<"\nInserimento avvenuto con successo.\n";
                    studentiliberi.erase(studentiliberi.begin()+ i);
                    return;
                }
            }
        }
    if(found == true){
        std::cout<<"\nStudente non esistente\n";
        break;
    }
    }
  }

*/




void scambioclasse(
    std::vector<Classe>& classi, 
    std::pair<bool, int>& studente,
    std::vector<Studente> studenti)
{
    std::string input;
    while(true){
        std::cout<<"\nLo studente è gia in una classe. Desideri cambiargli classe (si/no)?\n";
        std::getline(std::cin, input);
        for(auto& c:input){
            c = tolower(c);
        }
        if(input == "si"){
            std::string newclass;
            std::cout<<"\nClassi disponibili:\n\n";
            for(size_t i=0; i<classi.size(); i++){
                std::cout<<classi[i].nomeclasse<<" ";
            }
            std::cout<<"\nInserire la nuova classe dello studente: ";
            std::getline(std::cin, newclass);
            for(auto& c:newclass){
                c = toupper(c);
            }
            for(size_t i=0; i<classi.size(); i++){
                if(newclass == classi[i].nomeclasse){
                    classi[i].infostudenti.push_back(studenti[studente.second]);
                    std::cout<<"\nScambio classi avvenuto con successo\n";
                    return;
                }
            }
        }
        else if(input == "no"){
            return;
        }
        else{
            std::cout<<"\nErrore: scelta non valida. Riprovare\n";
        }
    }
}


int posizionestudentelibero(std::pair<std::string, std::string>& nomeCognome, std::vector<Studente>& studentiliberi){
    for(size_t i=0; i<studentiliberi.size(); i++){
        if(nomeCognome.first == studentiliberi[i].nome && nomeCognome.second == studentiliberi[i].cognome){
            return i;
        }
    }
    return -1;
}










void inserimentoStudenti(
    std::vector<Classe>& classe,
    std::vector<Studente>& studente,
    std::vector<Studente>& studentiliberi)
{
    std::pair<std::string, std::string> nomeCognome;
    int classeStudente;
    if(classe.empty()){
        std::cout<<"\nErrore: nessuna classe disponibile.\n";
        return;
    }
    nomeCognome = nomecognome(classe, studente, studentiliberi);
    bool first = true;
    std::pair<bool, int> found = ricercastudente(studente, nomeCognome);
    if(found.first){
        classeStudente = inserimentoClasse(classe);
        if(classeStudente == -1){
            std::cout<<"\nClasse non esistente.\n";
        }
        else{
            bool studenteinclasse = studenteoccupato(studentiliberi, nomeCognome);
            if(studenteinclasse){
                scambioclasse(classe, found, studente);
                return;
            }
            else{
                classe[classeStudente].infostudenti.push_back(studente[found.second]);
                int n = posizionestudentelibero(nomeCognome, studentiliberi);
                studentiliberi.erase(studentiliberi.begin() + n);
                std::cout<<"\nInserimento avvenuto con successo\n";
                return;
            }
        }
    }
    else{
        std::cout<<"\nStudente non esistente.\n";
    }
}




void menuprincipale(
    std::vector<Studente>& s,
    std::vector<Classe>& c,
    std::vector<Studente>& sl)

{
    std::cout<<"Benvenuto nel menu scolastico!\n\n";
    while(true){
        int scelta;
        std::cout<<"\n1. Crea studente\n2. Crea classe\n3. Visualizza classi\n4. Inserimento studenti\n5. Modifica classe\n6. Modifica studente\n7. Visualizza media generale scolastica\n8. Visualizza media generale della classe\n9. Fine\n";
        std::cout<<"\nSeleziona un opzione: ";
        std::cin>>scelta;
        if(scelta<1 || scelta>9){
            std::cout<<"\nScelta non valida.";
        }
        else{
            switch(scelta){
                case 1:
                creaStudente(s, sl);
                break;
                case 2:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                creaClasse(c);
                break;
                case 3:
                visualizzaClassi(c);
                break;
                case 4:
                inserimentoStudenti(c, s, sl);
                break;
                case 5:
                modificaClasse(c, sl);
                break;
                default:
                std::cout<<"\nfine";
                std::exit(0);
            }
        }
    }
}

int main(){
    std::vector<Studente> studente;
    std::vector<Classe> classe;
    std::vector<Studente> studentiliberi;
    menuprincipale(studente, classe, studentiliberi);
}