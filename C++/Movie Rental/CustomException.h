#ifndef CUSTOMEXCEPTION_H_
#define CUSTOMEXCEPTION_H_

#include <exception>

class DuplicateMovieException : public std::exception
{
public:
    const char* what() const throw();
};

class DuplicateRenterException : public std::exception
{
public:
    const char* what()const throw();
};

class EmptyMovieInfoException : public std::exception
{
public:
    const char* what()const throw();
};

class EmptyMovieListException : public std::exception
{
public:
    const char* what()const throw();
};

class EmptyRenterListException : public std::exception
{
public:
    const char* what()const throw();
};

class EmptyRenterNameException : public std::exception
{
public:
    const char* what()const throw();
};

class InvalidRenterIDException : public std::exception
{
public:
    const char* what()const throw();
};

class MovieLimitException : public std::exception
{
public:
    const char* what()const throw();
};

class MovieNotFoundException : public std::exception
{
public:
    const char* what()const throw();
};

class RentedMovieException : public std::exception
{
public:
    const char* what()const throw();
};

class RenterLimitException : public std::exception
{
public:
    const char* what()const throw();
};

class RenterNotFoundException : public std::exception
{
public:
    const char* what()const throw();
};

#endif
