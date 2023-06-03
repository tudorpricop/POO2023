#pragma once

#include <iostream>
#include "Contact.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include "Prieten.h"
#include <vector>
#include <typeinfo>

class Agenda {
public:
    Contact cautareContact(std::string nume);
    std::vector<Prieten> getPrieteni();
    void stergeContact(std::string nume);
    void adaugaContact(Contact contact);

private:
    std::vector<Contact> contacte;
};

Contact Agenda::cautareContact(std::string nume) {
    for (const auto& contact : contacte) {
        if (contact.persName == nume) {
            return contact;
        }
    }
    Contact contactGol; // Returneaza un contact gol daca nu se gaseste niciunul cu numele dat
    return contactGol;
}

std::vector<Prieten> Agenda::getPrieteni() {
    std::vector<Prieten> prieteni;
    for (size_t i = 0; i < contacte.size(); i++) {
        Contact* contact = &contacte[i];
        Prieten* prieten = dynamic_cast<Prieten*>(contact);
        if (prieten != nullptr) {
            prieteni.push_back(*prieten);
        }
    }
    return prieteni;
}


void Agenda::stergeContact(std::string nume) {
    for (auto it = contacte.begin(); it != contacte.end(); ++it) {
        if (it->persName == nume) {
            contacte.erase(it);
            std::cout << "Contactul " << nume << " a fost sters!\n";
            return;
        }
    }
    std::cout << "Contactul " << nume << " nu a fost gasit!\n";
}

void Agenda::adaugaContact(Contact contact) {
    contacte.push_back(contact);
    std::cout << "Contactul " << contact.persName << " a fost adaugat!\n";
}
