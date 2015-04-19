#pragma once
#include <string>
#include <iostream>
#include <list>
#include <memory>
#include "./exceptions.h"
using ::std::list;
using ::std::shared_ptr;
class Group {
private:
	string name;
	int studentNumber;
	int subjNumber;
	list<Student> students;

public:
	Group();
	Group(const Group& group);
	Group(const string& nameK, int studentNumberK, int subjNumberK);
	Group(const string& nameK, int studentNumberK, int subjNumberK,
		const list<Student>& StdList);
	~Group();
	string getName() const;
	int getSubjNumber() const;
	int getStudentNumber() const;
	const list<Student>& getStudents() const;
	void setName(const string& name);
	void setSubjNumber(int x);
	void setStudentNumber(int x);
	void setStudents(const list<Student>& students);
	double countMiddleSubj(int SbjId);
	double countMiddleMarks();
	bool checkDebt();
	void PrintStudents();
	void PrintPerfect();
	void PrintGroupInfo();
	int add(const Student &p);
	void dell(const Student &p);
	void dell(int idx);
	Group& operator+(const Group & group);
	Group& operator=(const Group& group);
	Student& operator[](int idx);
	void remove(int idx);
	bool has(const Student& student);
};