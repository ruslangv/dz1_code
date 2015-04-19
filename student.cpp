#include "./student.h"
#include <string>
#include <vector>
Student::Student() {
	FirstName = "";
	LastName = "";
	Patronymic = "";
	Debt = false;
	StudentType = "";
}
Student::Student(const Student& student) {
	FirstName = student.FirstName;
	LastName = student.LastName;
	Patronymic = student.Patronymic;
	Debt = student.Debt;
	StudentType = student.StudentType;
	Mark = student.Mark;
}
Student::Student(const string& FirstNameK, const string& LastNameK,
	const string& PatronymicK, bool debtK, const vector<int>& MarkK,
	const string& StudentTypeK) {
	FirstName = FirstNameK;
	LastName = LastNameK;
	Patronymic = PatronymicK;
	Debt = debtK;
	StudentType = StudentTypeK;
	Mark = MarkK;
}
Student::~Student() {
	Mark.clear();
}
bool Student::CheckPerfect(int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += Mark[i];
	if
		((sum - 5 * size) == 0) return true;
	else
		return false;
}
void Student::setFirstName(const string& x) {
	FirstName = x;
}
string Student::getFirstName() const {
	return FirstName;
}
void Student::setLastName(const string& x) {
	LastName = x;
}
string Student::getLastName() const {
	return LastName;
}
void Student::setPatronymic(const string& x) {
	Patronymic = x;
}
string Student::getPatronymic() const {
	return Patronymic;
}
bool Student::getDebt() const {
	return Debt;
}
void Student::setDebt(bool tempDebt) {
	Debt = tempDebt;
}
vector<int> Student::getMarks() const {
	return Mark;
}
void Student::setMarks(const vector<int>& tempMarks) {
	Mark = tempMarks;
}
string Student::getStudentType() const {
	return StudentType;
}
void Student::setStudentType(const string& tempStudentType) {
	StudentType = tempStudentType;
}
bool Student::operator==(const Student &input) {
	if ((input.FirstName == this->FirstName) &&
		(input.LastName == this->LastName) &&
		(input.Patronymic == this->Patronymic) &&
		(input.Debt == this->Debt) &&
		(input.Mark == this->Mark) &&
		(input.StudentType == this->StudentType))
		return true;
	else
		return false;
}
ostream& operator<<(ostream& os, const Student& st) {
	os << "FIO - " << st.FirstName << " " << st.LastName << " "
		<< st.Patronymic << " " << "type " << st.StudentType << " " << st.Debt;
	vector<int> temp;
	vector<int>::iterator v_itr;
	temp = st.Mark;
	for (v_itr = temp.begin(); v_itr != temp.end(); v_itr++)
		os << " " << *v_itr;
	os << "\n";
	return os;
}
Student& Student::operator=(const Student & input) {
	Student *copy = new Student(input.FirstName, input.LastName,
		input.Patronymic, input.Debt, input.Mark, input.StudentType);
	return *copy;
}