#include "../include/MedicalDocument.hpp"

MedicalDocument::MedicalDocument(std::string _name, std::string _deseases, bool _is_confirmed)
{
    name = _name;
    deseases = _deseases;
    is_confirmed = _is_confirmed;
}