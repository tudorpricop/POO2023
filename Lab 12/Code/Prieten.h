#pragma once

#include "Contact.h"
#include <string>

class Prieten : public Contact {
public:
    std::string birthDate;
    std::string phoneNo;
    std::string address;
};
