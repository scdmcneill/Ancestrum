#include "FamilyTree.cpp"
#include "Relative.cpp"

#include <iostream>
using std::cout;
using std::cin;
using std::string;

int main() {
	Relative johnDoe("John", "Doe", 'M');
	Relative janeSmith("Jane", "Smith", 'F');

	FamilyTree fam;

	johnDoe.displayRelative();

	return 0;
}