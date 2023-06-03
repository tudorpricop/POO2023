#pragma once

#include <string>

class Contact {
public:
    std::string persName;
    virtual ~Contact() = default; // adaugam ca sa mearga dinamic cast-ul

};
