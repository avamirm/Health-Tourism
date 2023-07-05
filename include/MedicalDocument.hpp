#ifndef MEDICALDOCUMENT_HPP
#define MEDICALDOCUMENT_HPP

#include "string"

class MedicalDocument {
public:
    MedicalDocument(std::string _name, std::string _deseases, bool _is_confirmed);
private:
    std::string name;
    std::string deseases;
    bool is_confirmed;
    // data: JGP
};

#endif