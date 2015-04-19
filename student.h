#pragma once

#include <iostream>
#include <string>
#include <vector>

using ::std::string;
using ::std::ostream;
using ::std::endl;
using ::std::cout;
using ::std::cin;
using ::std::exception;
using ::std::ostringstream;
using ::std::vector;

class Student {
private:
	string FirstName;
	string LastName;
	string Patronymic;
	bool Debt;
	vector<int> Mark;
	string StudentType;

public:
	Student();
	Student(const Student& student);
	Student(const string& FirstNameK, const string& LastNameK,
		const string& PatronymicK, bool debtK,
		const vector<int>& MarkK, const string& StudentTypeK);
	~Student();
	string getFirstName() const;
	void setFirstName(const string&);
	string getLastName() const;
	void setLastName(const string&);
	string getPatronymic() const;
	void setPatronymic(const string&);
	bool getDebt() const;
	void setDebt(bool tempDebt);
	vector<int> getMarks() const;
	void setMarks(const vector<int>& tempMarks);
	string getStudentType() const;
	void setStudentType(const string& tempStudentType);
	bool CheckPerfect(int size);
	friend ostream& operator<<(ostream& os, const Student& dt);
	bool operator==(const Student &input);
	Student& operator=(const Student &);
};