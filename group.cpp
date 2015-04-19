#include "./group.h"
#include <list>
#include <string>
#include <vector>
Group::Group() {
	name = "NO NAME"; studentNumber = 0; subjNumber = 0;
}
Group::Group(const string& nameK, int studentNumberK,
	int subjNumberK, const list<Student>& StdList) {
	name = nameK; studentNumber = studentNumberK; subjNumber = subjNumberK;
	students = StdList;
}
Group::Group(const string& nameK, int studentNumberK, int subjNumberK) {
	name = nameK; studentNumber = studentNumberK; subjNumber = subjNumberK;
}
Group::~Group() {
	students.clear();
}
string Group::getName() const {
	return name;
}
int Group::getSubjNumber() const {
	return subjNumber;
}
int Group::getStudentNumber() const {
	return studentNumber;
}
const list<Student>&  Group::getStudents() const {
	return students;
}
void Group::setName(const string& x) {
	name = x;
}
void Group::setStudentNumber(int x) {
	studentNumber = x;
}
void Group::setSubjNumber(int x) {
	subjNumber = x;
}
double Group::countMiddleSubj(int SbjId) {
	int tempSum = 0;
	list<Student>::iterator itr;
	for (itr = students.begin(); itr != students.end(); ++itr)
	if (!students.empty()) {
		vector<int> temp;
		temp = (*itr).getMarks();
		tempSum += temp[SbjId - 1];
	}
	itr = students.begin();
	return static_cast<double>(tempSum) / studentNumber;
}
double Group::countMiddleMarks() {
	int tempSum = 0;
	list<Student>::iterator itr;
	for (itr = students.begin(); itr != students.end(); ++itr)
	if (!students.empty()) {
		vector<int> temp;
		temp = (*itr).getMarks();
		for (int i = 0; i < subjNumber; i++)
			tempSum += temp[i];
	}
	itr = students.begin();
	return static_cast<double>(tempSum) / (subjNumber*studentNumber);
}
bool Group::checkDebt() {
	bool  temp;
	list<Student>::iterator itr;
	for (itr = students.begin(); itr != students.end(); ++itr)
	if (!students.empty()) {
		if ((*itr).getDebt()) {
			return true;
		}
		else {
			temp = false;
		}
	}
	itr = students.begin();
	return temp;
}
void Group::PrintStudents() {
	list<Student>::iterator itr;
	for (itr = students.begin(); itr != students.end(); ++itr)
	if (!students.empty()) {
		cout << *itr;
	}
	itr = students.begin();
}
void Group::PrintPerfect() {
	list<Student>::iterator itr;
	for (itr = students.begin(); itr != students.end(); ++itr)
	if (!students.empty()) {
		if ((*itr).CheckPerfect(subjNumber))
			cout << *itr;
	}
	itr = students.begin();
}
void Group::PrintGroupInfo() {
	cout << "Group name : " << name << endl;
	cout << "Number of students: " << studentNumber << endl;
	cout << "Number of subjects: " << subjNumber << endl;
}
int Group::add(const Student &p) {
	for (Student& value : students)
	if (value == p) throw studentAlreadyExistsException(p);
	students.push_back(p);
	return students.size();
}
void Group::dell(const Student &p) {
	list<Student>::iterator pos = find(students.begin(), students.end(), p);
	if (pos != students.end()) {
		students.erase(pos);
		studentNumber--;
	}
	else {
		throw studentNotFoundException(p);
	}
}
void Group::dell(int idx) {
	list<Student>::iterator pos;
	if (idx < this->getStudentNumber()) {
		for (int i = 0; i < idx; i++, pos++) {}
		students.erase(pos);
		studentNumber--;
	}
	else {
		throw studentNotFoundException(idx);
	}
}
bool Group::has(const Student &p) {
	if (find(students.begin(), students.end(), p) != students.end())
		return true;
	else
		return false;
}
void Group::setStudents(const list<Student>& tmpList) {
	students = tmpList;
}
Group& Group::operator+(const Group &input) {
	shared_ptr<Group> newGroup(new Group());
	newGroup->setName(this->getName() + " and " + input.getName());
	list<Student> newList = this->getStudents();
	newList.insert(newList.end(), input.getStudents().begin(),
		input.getStudents().end());
	newGroup->setStudents(newList);
	newGroup->setStudentNumber(this->getStudentNumber()
		+ input.getStudentNumber());
	newGroup->setSubjNumber(this->getSubjNumber()
		+ input.getSubjNumber());
	return *newGroup;
}
Group& Group::operator=(const Group& input) {
	this->name = input.name;
	this->studentNumber = input.studentNumber;
	this->subjNumber = input.subjNumber;
	this->students = input.students;
	return *this;
}
Student& Group::operator[](int idx) {
	list<Student>::iterator itr = students.begin();
	if (idx < students.size()) {
		for (int i = 0; i < idx; i++)
			itr++;
		return *itr;
	}
	else {
		throw studentNotFoundException(idx);
	}
}