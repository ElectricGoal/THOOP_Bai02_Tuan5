#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T> class vectorClass
{
	T* arr;
	int capacity;
	int current;

public:
	// Default constructor to initialise
	// an initial capacity of 1 element and
	// allocating storage using dynamic allocation
	vectorClass();

	// Function to add an element at the last
	void push(T data);

	// function to add element at any index
	void insert(T data, int index);

	// function to extract element at any index
	T get(int index);

	T operator[](int index);

	// function to delete last element
	void pop();

	// function to get size of the vector
	int size();

	// function to get capacity of the vector
	int getcapacity();

	// function to print array elements
	void print();
};

class Schedule
{
private:
	vectorClass<string> courses;
public:
	bool Nhap(string tenKH);
	void Xuat();
};

class Student
{
private:
	string name;
	Schedule schedule;
public:
	Student();
	void Nhap();
	void Xuat();
	bool ThemKH(string tenKH);
	string GetName();
	void DanhSachKHDK();
};

class Roster
{
private:
	vectorClass<string> students;
public:
	bool Nhap(string tenSV);
};

class Course
{
private:
	string name;
	Roster roster;
public:
	Course();
	void Nhap();
	void Xuat();
	bool ThemSV(string tenSV);
	string GetName();
};

class Registrar//:public Student, public Course
{
private:
	vectorClass<Student> st;
	vectorClass<Course> co;
public:
	Registrar();
	void AddCourses();
	void PrintCourses();
	void AddStudents();
	void PrintStudents();
	void Register();
};

