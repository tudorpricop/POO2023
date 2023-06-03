#include "Agenda.h"
#include <iostream>

int main() {
    Agenda agenda;

    // Adaugarea unui contact de tip Prieten
    Prieten prieten;
    prieten.persName = "Tudor";
    prieten.birthDate = "11/04/2002";
    prieten.phoneNo = "074555555";
    prieten.address = "Strada acasa";
    agenda.adaugaContact(prieten);

    // Adaugarea unui contact de tip Cunoscut
    Cunoscut cunoscut;
    cunoscut.persName = "Stefan";
    cunoscut.phoneNo = "0723222222";
    agenda.adaugaContact(cunoscut);

    // Adaugarea unui contact de tip Coleg
    Coleg coleg;
    coleg.persName = "George";
    coleg.phoneNo = "0723255222";
    coleg.address = "Strada Negruzzi";
    coleg.firm = "Compania Emag";
    agenda.adaugaContact(coleg);

    // Cautarea unui contact dupa nume
    std::string numeCautat = "Tudor";
    Contact contactGasit = agenda.cautareContact(numeCautat);
    if (!contactGasit.persName.empty()) {
        std::cout << "Contactul " << numeCautat << " a fost gasit!\n";
    }
    else {
        std::cout << "Contactul " << numeCautat << " nu a fost gasit!\n";
    }

    // Obtinerea listei de prieteni
    std::vector<Prieten> prieteni = agenda.getPrieteni();
    std::cout << "Lista de prieteni:\n";
    for (const auto& prieten : prieteni) {
        std::cout << "- Nume: " << prieten.persName << ", Data nasterii: " << prieten.birthDate << ", Telefon: " << prieten.phoneNo << ", Adresa: " << prieten.address << "\n";
    }

    // Stergerea unui contact dupa nume
    std::string numeSters = "Stefan";
    agenda.stergeContact(numeSters);

    return 0;
}
