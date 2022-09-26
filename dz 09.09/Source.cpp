#include<iostream>
using namespace std;

class Book
{
	char* name;
	int pages;
public:
	Book(const char* n) {
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	Book(const char* n, int p) :Book(n) {
		pages = p;
	} 
	void Print();
	~Book();
};
void Book::Print()
{
	cout << "Name:" << name << endl;
	cout << "Pages:" << pages << endl;
}
Book::~Book() {
	delete[]name;
	cout << "Destructor" << endl;
}
class Student
{
	char* name;
	const double step;// !!
	Book book; //!!!
public:
	Student() :step(0), book(nullptr, 0)
	{
		name = nullptr;
	}
	Student(const char* n, double st, const char* bookName, int bookPages) :step(st), book(bookName, bookPages) {
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n), n);
	}
	~Student();
	void Print();

};
Student::~Student() {
	delete[]name;
	cout <<"destructor"<<endl;
}
void Student::Print() {
	cout << "Name:" << name << endl;
	cout << "Step:" << step << endl;
	cout << "Book:";
	book.Print();
}
// показать использование объектом в функции main
int main()
{
	Book book1("Ayvengo", 234);
	Student Stud1("Vasya", 3.5, "Guliver", 126);
	Stud1.Print();
}