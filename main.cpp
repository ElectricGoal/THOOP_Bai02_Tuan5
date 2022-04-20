#include "Header.h"

int main()
{
	Registrar registrar;
	registrar.AddCourses();
	cout << endl;
	registrar.AddStudents();

	cout << "\nDanh sach cac khoa hoc:\n";
	registrar.PrintCourses();
	cout << "\nDanh sach cac sinh vien:\n";
	registrar.PrintStudents();

	cout << "\nDang ky khoa hoc:\n";
	registrar.Register();

	return 0;
}