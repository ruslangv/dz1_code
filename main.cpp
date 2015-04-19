#include <string>
#include <vector>
#include "./group.h"
void printBool(bool x) {
	if (x)
		cout << "True";
	else
		cout << "False";
}
int main() {
	cout << "Insert group name, size, number of subjects" << endl;
	string x;
	int y, z;
	cin >> x;
	cin >> y;
	cin >> z;
	Group n(x, y, z);

	string tempS, temp1S, temp2S, temp3S;
	Student **std;

	std = new Student*[y];
	vector<int> tempV(n.getSubjNumber());
	bool tempB;
	for (int i = 0; i < n.getStudentNumber(); i++) {
		cout << "insert student fio, type, dolgi, ozenki" << endl;
		cin >> tempS;
		cin >> temp2S;
		cin >> temp3S;
		cin >> temp1S;
		cin >> tempB;
		for (int j = 0; j < n.getSubjNumber(); j++)
			cin >> tempV[j];
		std[i] = new Student(tempS, temp2S, temp3S, tempB, tempV, temp1S);
		n.add(*std[i]);
	}
	n.PrintStudents();
	cout << "\nmiddle  ---->   " << n.countMiddleMarks() << endl;
	cout << "Select subj to check(enter id from 1 to) "
		<< n.getSubjNumber() << " - ";
	int tempSbjId;
	cin >> tempSbjId;
	if ((tempSbjId >0) && (tempSbjId <= n.getSubjNumber()))
		cout << "\nmiddle in Sbj - " << n.countMiddleSubj(tempSbjId);
	cout << "\nprinting perfect students" << endl;
	n.PrintPerfect();
	cout << "\n\nChecking debts --- >>> ";
	printBool(n.checkDebt());
	cout << "\n";
	cout << "deleting student 1" << endl;
	n.dell(*std[0]);
	n.PrintStudents();
	try {
		n.dell(100);
	}
	catch (studentNotFoundException& e) {
		cout << "Error: " << e.what() << endl;
	}
	delete[]std;
	system("pause");
}
