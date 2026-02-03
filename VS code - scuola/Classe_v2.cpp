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
{
    while (true)
    {
        std::string name;
        char opt;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                    break;
                case 'n':
                    valid = true;
                    break;
                default:
                    std::cout << "\nErrore: scelta non valida. Riprovare.";
                }
            }
        }
    }
}
int main()
{
    Scuola s = creaScuola();
    Classe n = creaClasse(s);
    s.auleScuola.push_back(n);
    n.stampaInfo();
    s.stampaInfo();
    Classe f = creaClasse(s);
    s.auleScuola.push_back(f);
    s.stampaInfo();
}
