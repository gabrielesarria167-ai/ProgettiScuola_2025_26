// shift opt f format

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

class Studente
{
public:
    std::string nomeStudente;
    std::string cognomeStudente;
    int etaStudente;
    double mediaStudente;
    Studente(std::string nome, std::string cognome, int eta, double media) : nomeStudente(nome), cognomeStudente(cognome), etaStudente(eta), mediaStudente(media) {}
    void StampaInfo()
    {
        std::cout << "\nNome: " << nomeStudente << "\nCognome: " << cognomeStudente
                  << "\nEta:  " << etaStudente << "\nMedia: " << mediaStudente;
    }
};
class Classe
{
public:
    std::string nomeClasse;
    std::vector<Studente> aulaClasse;
    Classe(std::string nome) : nomeClasse(nome) {};
    void inserimentoStudente(const Studente s) { aulaClasse.push_back(s); }
    void stampaInfo()
    {
        std::cout << "\nNome classe: " << nomeClasse;
        std::cout << "\nStudenti in " << nomeClasse << ": " << aulaClasse.size();
        for (const auto i : aulaClasse)
        {
            std::cout << "\n"
                      << i.nomeStudente << " " << i.cognomeStudente;
        }
    }
};
class Scuola
{
public:
    std::string nomeScuola;
    std::vector<Classe> auleScuola;
    Scuola(std::string nome) : nomeScuola(nome) {};
    void inserimentoClasse(Classe c) { auleScuola.push_back(c); }
    void stampaInfo()
    {
        std::cout << "\nNome scuola: " << nomeScuola
                  << "\nNumero classi: " << auleScuola.size();
        for (auto &i : auleScuola)
        {
            std::cout << "\n"
                      << i.nomeClasse << " (" << i.aulaClasse.size() << ")";
        }
    }
};
Scuola creaScuola()
// Takes name and return to our school, added security check with a switch case
// add security control -> if the name is only numbers, print error
{
    std::string nome;
    bool verificanome;
    char opt;
    while (true)
    {
        verificanome = true;
        std::cout << "\nInserire il nome della scuola: ";
        std::getline(std::cin, nome);
        for (auto &c : nome)
        {
            c = toupper(c);
        }
        std::cout << "\n\nIl nome digitato è: " << nome;
        while (verificanome)
        {
            std::cout << "\nSei sicuro di questa scelta (y/n)? ";
            std::cin >> opt;
            opt = tolower(opt);
            switch (opt)
            {
            case 'y':
                std::cout << "\nNome selezionato con successo.\n";
                return Scuola(nome);
            case 'n':
                verificanome = false;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            default:
                std::cout << "\nErrore: scelta non valida. Riprovare.\n";
            }
        }
    }
}
Classe creaClasse(Scuola &s)
// added class creation. for next time use the method inside the scuola class. dont forget methods
// one day insert a control for class validity -> if the class has only numbers, print error
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (true)
    {
        std::string name;
        char opt;
        std::cout << "\nInserisci il nome della classe: ";
        std::getline(std::cin, name);
        for (auto &c : name)
        {
            c = toupper(c);
        }
        if (name.size() == 0)
        {
            std::cout << "\nErrore: nome non esistente. Riprovare.";
        }
        else
        {
            bool valid = false;
            while (!valid)
            {
                bool newclass = true;
                std::cout << "\nIl nome digitato é: " << name;
                std::cout << "\nSei sicuro di questa scelta (y/n)? ";
                std::cin >> opt;
                switch (opt)
                {
                case 'y':
                    for (const auto &i : s.auleScuola)
                    {
                        if (i.nomeClasse == name)
                        {
                            std::cout << "\nErrore: classe gia esistente. Riprovare.\n";
                            valid = true;
                            newclass = false;
                            break;
                        }
                    }
                    if (newclass)
                    {
                        std::cout << "\nCreazione avvenuta con successo.\n";
                        return Classe(name);
                    }
                case 'n':
                    valid = true;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                default:
                    std::cout << "\nErrore: scelta non valida. Riprovare.\n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
    }
}
Studente creaStudente()
// one day add option if the student was already part of the school or first time (grades first time are 0)
{
    bool valid = false;
    std::string nomes, cognomes;
    // name and surname control
    while (!valid)
    {
        std::cout << "\nInserisci il nome dello studente: ";
        std::getline(std::cin, nomes);
        for (auto &c : nomes)
        {
            c = tolower(c);
        }
        nomes[0] = toupper(nomes[0]);
        std::cout << "\nInserisci il cognome dello studente: ";
        std::getline(std::cin, cognomes);
        for (auto &c : cognomes)
        {
            c = tolower(c);
        }
        cognomes[0] = toupper(cognomes[0]);
        char opt;
        std::cout << "\nConfermi questi dati : " << nomes << " " << cognomes << " (y/n)? ";
        std::cin >> opt;
        switch (opt)
        {
        case 'y':
            if (nomes.size() == 0|| cognomes.size() == 0)
            {
                std::cout << "\nErrore: dati mancanti. Riprovare.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            std::cout << "\nDati salvati con successo.\n";
            valid = true;
            break;
        case 'n':
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        default:
            std::cout << "\nErrore: opzione invalida. Riprovare.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    int etas;
    double medias;
    // age and grades control
    while (true)
    {
        char opt;
        std::cout << "\nInserisci l'eta dello studente: ";
        std::cin >> etas;
        std::cout << "\nInserisci la media dello studente: ";
        std::cin >> medias;
        std::cout << "\nConfermi questi dati (y/n)?\n"
                  << "Eta: " << etas << "\nMedia: " << medias << "\n";
        std::cin >> opt;
        switch (opt)
        {
        case 'y':
            if(etas < 6){
                std::cout<<"\nErrore: eta non valida. Riprovare.\n";
            }
            std::cout << "\nDati salvati con successo.\n";
            return {nomes, cognomes, etas, medias};
        case 'n':
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        default:
            std::cout << "\nErrore: opzione non valida. Riprovare.";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
int main()
{
    Scuola s = creaScuola();
    Classe c = creaClasse(s);
    s.inserimentoClasse(c);
    Classe f = creaClasse(s);
}
