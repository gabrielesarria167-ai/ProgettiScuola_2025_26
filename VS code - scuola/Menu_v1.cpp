#include <iostream>
#include <vector>
#include <string>
void ordinaValori(std::vector<int>& v){
    std::string choice;
    while(true){
        if(v.size()==0){
            std::cout<<"\nNon disponibile: vettore non esistente.\n";
            break;
        }
    std::cout<<"\nSeleziona il tipo di riordinamento che desideri:\n";
    std::cout<<"(crescente) / (decrescente)\n\n";
    std::cin.ignore(); //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
    std::getline(std::cin, choice);
    for(auto& x: choice){
        x = tolower(x);
    }
    if(choice == "crescente"){
        std::sort(v.begin(), v.end());
        std::cout<<"\nRiordinamento avvenuto con successo.";
        break;
    }
    else if(choice == "decrescente"){
        std::sort(v.begin(), v.end());
        std::reverse(v.begin(), v.end());
        std::cout<<"\nRiordinamento avvenuto con successo.";
        break;
    }
    else{
        std::cout<<"Scelta non valida.";

    }
 }
}
double media(const std::vector<int>& v){
    if(v.size() == 0){
        std::cout<<"\nNon disponibile: vettore non esistente\n";
        return 0;
    }
    int somma = 0;
    for(int i:v){
        somma = somma +i;
    }
    return somma/double(v.size());
}
std::pair<int,int> maxmin(const std::vector<int>& v){
    if(v.size()==0){
        return {0,0};
    }
    int min = v[0];
    int max = v[0];
    for(int i:v){
        if(i>max){
            max = i;
        }
        else if(i < min){
            min = i;
        }
    }
    return {max, min};
}
void ModificaValore(std::vector<int>& v){
    int val;
    int tot = 0;
    int fisso;
    if(v.size() == 0){
        std::cout<<"\nErrore, vettore non esistente\n";
        return;
    }
    std::cout<<"\nQuale valore vuoi sostituire?\n";
    for(int i:v){
        std::cout<<i<<" ";
    }
    std::cout<<"\nInserire il numero da sostituire: ";
    std::cin>>val;
    for(int i=0; i<v.size();i++){
        if(v[i] == val){
            fisso = i;
            tot++;
        }
    }
    if(tot > 1){
        while(true){
            std::string scelta;
            std::cout<<"Ci sono diverse posizioni contenenti il tuo numero.\n";
            std::cout<<"Desideri sostituirle tutte o solo una?\n(tutte/una)     ";
            std::getline(std::cin, scelta);
            for(auto& c: scelta){
                c = tolower(c);
            }
            if(scelta == "tutte"){
                int newvalue;
                std::cout<<"Inserisci il nuovo valore: ";
                std::cin>>newvalue;
                for(int i=0;i<v.size();i++){
                    if(v[i]== val){
                        v[i] = newvalue;
                    }
                }
                std::cout<<"Valori inseriti con successo.";
                break;
            }
            else if(scelta == "una"){
                int pos, newvalue;
                std::cout<<"Quale posizione di "<<val<<" desideri modificare? \n";
                for(int i:v){
                    std::cout<<i<<" ";
                }
                std::cout<<"\n\n";
                std::cin>>pos;
                std::cout<<"Inserisci il nuovo valore: ";
                std::cin>>newvalue;
                v[pos] = newvalue;
                std::cout<<"Valore inserito con successo.";
                break;
            }
            else{
                std::cout<<"Scelta non valida.\n\n";
            }
        }
    }
    else{
        int newvalue;
        std::cout<<"Inserisci il nuovo valore: ";
        std::cin>>newvalue;
        v[fisso] = newvalue;
        std::cout<<"\nInserimento avvenuto con successo.\n";

    }
}
void InserisciValori(std::vector<int>& v){
    int n;
    std::cout<<"\nDigitare '9999' per terminare l'aggiunta dei valori.\n";
    while(true){
        std::cout<<"\nInserisci il valore in posizione "<<v.size()<<": ";
        std::cin>>n;
        if(n== 9999){
            break;
        }
        v.push_back(n);
    }
}
void CancellaVettore(std::vector<int>& v){
    std::cout<<"\nCancellando...";
    for(int i=0; i<v.size();i++){
        v.erase(v.begin()+i); // use v.erase(v.begin()+i) faster (O(n))
        i--;
    }
    std::cout<<"\nVettore eliminato con successo.\n";
}
void VisualizzaVettore(const std::vector<int>& v){
    std::cout<<"\nVettore:\n";
    if(v.size() == 0){
        std::cout<<"Vettore non esistente.";
    }
    for(int i:v){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
}
void InserimentoMultiplo(std::vector<int>& v, int& i){
    i++;
    if(i>1){
        std::string p;
        std::cout<<"Procedendo cancellerai il vettore precedente. Prosegui? (si/no)\n";
        std::cin.ignore();
        std::getline(std::cin, p);
        if(p == "si"){
            v.clear();
        }
        else{
            return;
        }
    }
    int n;
    std::cout<<"Digitare '9999' per terminare l'inserimento automatico\n";
    while(true){
        std::cout<<"\nInserisci il valore in posizione "<<v.size()<<": ";
        std::cin>>n;
        if(n == 9999){
            break;
        }
        v.push_back(n);
    }
}
bool condizione (int scelta){
    if(scelta >9 || scelta <1){
        return false;
    }
    else return true;
}



int main(){
    int scelta, i=0;
    bool valido;
    std::vector<int> vettore;
    std::cout<<"\nBenvenuto nel menu!\n";
    while(true){
        std::cout<<"\n1. Inserimento multiplo iniziale \n2. Visualizza vettore \n3. Cancella vettore precedente \n4. Inserisci nuovi valori \n5. Modifica valore \n6. Massimo/minimo \n7. Media valori \n8. Ordina valori \n9. Fine";
        std::cout<<"\nScegli un opzione: ";
        std::cin>>scelta;
        valido = condizione(scelta);
        while(valido == false){
            std::cout<<"Scelta non valida. Selezionare un'opzione disponibile: ";
            std::cin>>scelta;
            bool valido = condizione(scelta);
            if(valido == true){
                break;
            }
        }
        switch(scelta){
            case 1:
            InserimentoMultiplo(vettore, i);
            break;
            case 2:
            VisualizzaVettore(vettore);
            break;
            case 3:
            CancellaVettore(vettore);
            break;
            case 4:
            InserisciValori(vettore);
            break;
            case 5:
            ModificaValore(vettore);
            break;
            case 6: {
            std::pair<int,int> maxminval = maxmin(vettore);
            if(vettore.size() == 0){
                std::cout<<"\nOperazione non disponibile: vettore non esistente\n";
                break;
            }
            std::cout<<"\nIl massimo vale: "<<maxminval.first<<"\n\nIl minimo vale: "<<maxminval.second<<"\n";
            break;
            }
            case 7: {
            double mediaval = media(vettore);
            std::cout<<"\nLa media dei valori nel vettore vale: "<<mediaval<<"\n";
            break;
            }
            case 8:
            ordinaValori(vettore);
            break;
            default:
            std::cout<<"Arrivederci!";
            std::exit(0);
        }
    }

}