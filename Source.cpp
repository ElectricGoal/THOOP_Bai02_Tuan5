#include "Header.h"

template <typename T>
vectorClass<T>::vectorClass()
{
	arr = new T[1];
	capacity = 1;
	current = 0;
}

template <typename T>
void vectorClass<T>::push(T data)
{
	if (current == capacity) {
		T* temp = new T[2 * capacity];

		// copying old array elements to new array
		for (int i = 0; i < capacity; i++) {
			temp[i] = arr[i];
		}

		// deleting previous array
		delete[] arr;
		capacity *= 2;
		arr = temp;
	}

	// Inserting data
	arr[current] = data;
	current++;
}

template <typename T>
void vectorClass<T>::insert(T data, int index)
{
	if (index == capacity)
		push(data);
	else
		arr[index] = data;
}

template <typename T>
T vectorClass<T>::get(int index)
{
	if (index < current)
		return arr[index];
}

template <typename T>
T vectorClass<T>::operator[](int index)
{
	if (index < current)
		return arr[index];
}

template <typename T>
void vectorClass<T>::pop()
{
	current--;
}

template <typename T>
int vectorClass<T>::size()
{
	return current;
}

template <typename T>
int vectorClass<T>::getcapacity()
{
	return capacity;
}

template <typename T>
void vectorClass<T>::print()
{
	for (int i = 0; i < current; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//Class Course

Course::Course()
{
	name = "";
}

void Course::Nhap()
{
	cout << "Nhap ten khoa hoc: ";
	getline(cin >> ws, name);
}

void Course::Xuat()
{
	cout << name;
}

bool Roster::Nhap(string tenSV)
{
	if (students.size() >= 40)
	{
		return 0;
	}
	students.push(tenSV);
	return 1;
}

bool Course::ThemSV(string tenSV)
{
	return roster.Nhap(tenSV);
}

string Course::GetName()
{
	return name;
}

//Class Student

Student::Student()
{
	name = "";
}

void Student::Nhap()
{
	cout << "Nhap ten sinh vien: ";
	getline(cin >> ws, name);
}

void Student::Xuat()
{
	cout << name;
}

bool Schedule::Nhap(string tenKH)
{
	if (courses.size() >= 5)
	{
		return 0;
	}
	courses.push(tenKH);
	return 1;
}

void Schedule::Xuat()
{
	for (int i = 0; i < courses.size(); i++)
	{
		cout << courses[i] << "\n";
	}
}

bool Student::ThemKH(string tenKH)
{
	return schedule.Nhap(tenKH);
}

string Student::GetName()
{
	return name;
}

void Student::DanhSachKHDK()
{
	schedule.Xuat();
}

//Class Registrar

Registrar::Registrar()
{
	return;
}

void Registrar::AddStudents()
{
	int flag = 1;
	cout << "Nhap cac sinh vien:\n";
	while (true)
	{
		Student temp;
		temp.Nhap();
		st.push(temp);
		cout << "(1. Tiep tuc, 0. Thoat): ";
		cin >> flag;
		if (flag == 0)
		{
			break;
		}
	}
}

void Registrar::PrintStudents()
{
	for (int i = 0; i < st.size(); i++)
	{
		cout << i << ": ";
		st[i].Xuat();
		cout << endl;
	}
}

void Registrar::AddCourses()
{
	int flag = 1;
	cout << "Nhap cac khoa hoc:\n";
	while (true)
	{
		Course temp;
		temp.Nhap();
		co.push(temp);
		cout << "(1. Tiep tuc, 0. Thoat): ";
		cin >> flag;
		if (flag == 0)
		{
			break;
		}
	}
}

void Registrar::PrintCourses()
{
	for (int i = 0; i < co.size(); i++)
	{
		cout << i << ": ";
		co[i].Xuat();
		cout << endl;
	}
}

void Registrar::Register()
{
	int flag1 = 1;
	int flag2 = 1;
	int id = -1;
	while (flag2)
	{
		cout << "Nhap id sinh vien: ";
		cin >> id;
		Student student = st.get(id);
		cout << "\nDa chon sinh vien ten [" << student.GetName() << "]:\n\n";
		while (true)
		{
			cout << "Nhap id khoa hoc: ";
			cin >> id;
			Course course = co.get(id);
			if (!student.ThemKH(course.GetName()) || !course.ThemSV(student.GetName()))
			{
				cout << "*Khong the dang ki*\n";
			}
			else
			{
				cout << "*Dang ki thanh cong*\n";
			}

			cout << "0. Thoat, 1. Tiep tuc: ";
			cin >> flag1;
			if (flag1 == 0)
			{
				break;
			}
		}
		cout << "\nDanh sach cac mon da dang ky cua sinh vien [" << student.GetName() << "]: \n";
		student.DanhSachKHDK();

		cout << "\nNhan 0 de thoat: ";
		cin >> flag2;
	}
	
	cout << "\nKet thuc dang ki";
}