#pragma once
#include <string>
#include <sstream>
#include <exception>
#include "./student.h"
class studentNotFoundException : public exception {
private:
	string message;
public:
	explicit studentNotFoundException(const Student& student);
	explicit studentNotFoundException(int index);
	virtual const char* what() const throw();
};
class studentAlreadyExistsException : public exception {
private:
	string message;
public:
	explicit studentAlreadyExistsException(const Student& Student);
	virtual const char* what() const throw();
};