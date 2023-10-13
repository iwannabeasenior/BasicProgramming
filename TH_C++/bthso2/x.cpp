// C++ program for the Comparator Class
// implementing sorting

#include <bits/stdc++.h>
using namespace std;

// Student Class
class student {
public:
	// To store Name and Roll Number
	string name;
	int rollnum;

	// Overloaded Constructor
	student(string name, int rollnum)
	{
		this->name = name;
		this->rollnum = rollnum;
	}
};

// Comparator Class to compare 2 objects
class studentcompare {
public:
	// Comparator function
	bool operator()(const student& a,
					const student& b)
	{
		// Compare on basis of roll number
		if (a.rollnum < b.rollnum) {
			return true;
		}
		return false;
	}
};

// Driver Code
int main()
{
	// Object of class student
	student s1("Raj", 23);
	student s2("Prerna", 24);
	student s3("Harshit", 21);

	// List of students
	list<student> s;
	s.push_back(s1);
	s.push_back(s2);
	s.push_back(s3);

	// Creating object of
	// comparator class
	studentcompare cmp;

	// Passing the object of
	// comparator class to sort()
	s.sort(cmp);

	// Printing the list after sorting
	for (auto stu : s) {
		cout << stu.name << " ";
	}

	return 0;
}
