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
int main()
{
}
