//
// Created by jeannie on 2017.10.22..
//

#ifndef DUSTBIN_DUSTBINISFULLEXCEPTION_HPP
#define DUSTBIN_DUSTBINISFULLEXCEPTION_HPP

#include <exception>

class DustbinIsFull : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Garbage overflow, dustbin is full.";
    }
};

#endif //DUSTBIN_DUSTBINISFULLEXCEPTION_HPP
