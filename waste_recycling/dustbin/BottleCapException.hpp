//
// Created by jeannie on 2017.10.20..
//

#ifndef WASTE_BOTTLECAPEXCEPTION_HPP
#define WASTE_BOTTLECAPEXCEPTION_HPP

#include <exception>

class BottleCapException : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Unacceptable BottleCap color.";
    }
};


#endif //WASTE_BOTTLECAPEXCEPTION_HPP
