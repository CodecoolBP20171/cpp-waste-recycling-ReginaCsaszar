//
// Created by jeannie on 2017.10.20..
//

#ifndef WASTE_DUSTBINCONTENTERROR_HPP
#define WASTE_DUSTBINCONTENTERROR_HPP

#include <exception>

class DustbinContentError : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Unacceptable Garbage.";
    }
};


#endif //WASTE_DUSTBINCONTENTERROR_HPP
