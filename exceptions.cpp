#include "./exceptions.h"

studentNotFoundException::studentNotFoundException(int index) {
	ostringstream stream;
	stream << "No student with index " << index;
	message = stream.str();
}

studentNotFoundException::
studentNotFoundException(const Student& input) {
	ostringstream stream;
	stream << "Student " << input.getLastName() << " "
		<< input.getFirstName() << " " << input.getPatronymic()
		<< " not found";
	message = stream.str();
}

const char* studentNotFoundException::what() const throw() {
	return message.c_str();
}

studentAlreadyExistsException::
studentAlreadyExistsException(const Student& input) {
	ostringstream stream;
	stream << "Student " << input.getLastName() << " "
		<< input.getFirstName() << " " << input.getPatronymic()
		<< " already exists";
	message = stream.str();
}

const char* studentAlreadyExistsException::
what() const throw() {
	return message.c_str();
}