#include "FamilyTree.cpp"
#include "Relative.cpp"

#include <iostream>
using std::cout;
using std::cin;
using std::string;

int main() {
	Relative scottMcNeill("Scott", "McNeill", 'M');
	FamilyTree tree;

	scottMcNeill.setBirthDate("November 22, 1994");
	scottMcNeill.setBirthPlace("San Juan, Puerto Rico");
	scottMcNeill.setEducation("BSc. Computer Science | University of Houston - Downtown");
	scottMcNeill.setOccupation("Student");

	scottMcNeill.displayRelative();

	tree.addRelative(scottMcNeill);

	Relative markyMark("Marky", "Mark", 'M');
	Relative janeDoe("Jane", "Doe", 'F');
	Relative taylorSwift("Taylor", "Swift", 'F');
	Relative leonardoDiCaprio("Leonardo", "DiCaprio", 'M');
	Relative samuelJackson("Samuel", "Jackson", 'M');


	tree.setFather(scottMcNeill, markyMark);
	tree.setMother(scottMcNeill, janeDoe);
	tree.setSpouse(scottMcNeill, taylorSwift);
	tree.setFather(markyMark, leonardoDiCaprio);
	tree.setFather(leonardoDiCaprio, samuelJackson);

	tree.displayFamilyGraph(scottMcNeill);
	tree.displayFamilyGraph(markyMark);

	return 0;
}