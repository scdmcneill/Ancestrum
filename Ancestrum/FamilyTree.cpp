#pragma once
#include "Relative.cpp"

#include <unordered_map>

// Build Notes to Self:
// - Need to come up with way to sort grandparents by maternal and paternal.
//		- how would this be displayed?
//		- how deep by default are grandparents displayed
//		- possible GUI implementation would be asking user to input desired tree depth?

// - Need to add logic so that when a father is added to an individual, all appropriate relationships are built afterwards.

using std::string;
using std::vector;
using std::pair;

struct Relationships {
	Relative* father = nullptr;
	Relative* mother = nullptr;
	vector<Relative*> siblings;
	vector<Relative*> children;
	Relative* spouse = nullptr;
	vector<pair<Relative*, int>> grandparents; // int to represent generation level
	vector<pair<Relative*, int>> grandfathers; // int to represent generation level	
	vector<pair<Relative*, int>> grandmothers; // int to represent generation level
	vector<Relative*> uncles;
	vector<Relative*> aunts;
	vector<pair<Relative*, int>> cousins; // int to represent degree of cousinship
	vector<Relative*> grandchildren;
};

class FamilyTree {
public:
	//Constructors
	FamilyTree() {} // default
	
	string makeID(const Relative& relative) {
		return relative.getFirstName() + " " + relative.getMiddleName() + " " + relative.getLastName()
			+ " " + relative.getBirthDate();
	}
	void addRelative(const Relative& relative) {
			string id = makeID(relative);
			family[id] = relative;
			familyGraph.emplace(id, Relationships{});
	}

	// Getters
	Relative* getFather(const Relative& relative) {
		string childID = makeID(relative);
		return familyGraph[childID].father;
	}
	Relative* getMother(const Relative& relative) {
		string childID = makeID(relative);
		return familyGraph[childID].mother;
	}
	Relative* getSiblings(const Relative& relative) {
		string siblingID = makeID(relative);
		for (auto sibling : familyGraph[siblingID].siblings) {
			return sibling;
		}
	}
	
	
	// Mutators
	void setFather(const Relative& child, const Relative& father) {
		string childID = makeID(child);
		string fatherID = makeID(father);

		// add relatives to family if not already present
		addRelative(child);
		addRelative(father);

		// set relationship in graph
		familyGraph[childID].father = &family[fatherID];
		familyGraph[fatherID].children.push_back(&family[childID]);
	}
	void setMother(const Relative& child, const Relative& mother) {
		string childID = makeID(child);
		string motherID = makeID(mother);
		
		// add relatives to family if not already present
		addRelative(child);
		addRelative(mother);
		
		// set relationship in graph
		familyGraph[childID].mother = &family[motherID];
		familyGraph[motherID].children.push_back(&family[childID]);
	}
	void setSiblings(const Relative& thing1, const Relative& thing2) {
		string thing1ID = makeID(thing1);
		string thing2ID = makeID(thing2);

		// add relatives to family if not already present
		addRelative(thing1);
		addRelative(thing2);

		// set relationship in graph
		familyGraph[thing1ID].siblings.push_back(&family[thing2ID]);
		familyGraph[thing2ID].siblings.push_back(&family[thing1ID]);
	}
	void setChildren(const Relative& parent, const Relative& child) {
		string parentID = makeID(parent);
		string childID = makeID(child);

		// add relatives to family if not already present
		addRelative(parent);
		addRelative(child);

		// set relationship in graph
		familyGraph[parentID].children.push_back(&family[childID]);
	}
	void setSpouse(const Relative& partner1, const Relative& partner2) {
		string partner1ID = makeID(partner1);
		string partner2ID = makeID(partner2);

		// add relatives to family if not already present
		addRelative(partner1);
		addRelative(partner2);

		// set relationship in graph
		familyGraph[partner1ID].spouse = &family[partner2ID];
		familyGraph[partner2ID].spouse = &family[partner1ID];
	}
	void setGrandparents(const Relative& grandchild, const Relative& grandparent, int generationLevel) {
		string grandchildID = makeID(grandchild);
		string grandparentID = makeID(grandparent);

		// add relatives to family if not already present
		addRelative(grandchild);
		addRelative(grandparent);

		// set relationship in graph
		familyGraph[grandchildID].grandparents.emplace_back(&family[grandparentID], generationLevel);
		familyGraph[grandparentID].grandchildren.push_back(&family[grandchildID]);
	}
	
	// need to add methods for diplaying familyGraph
	void displayFamilyGraph(const Relative& relative) {
		string relativeID = makeID(relative);
		auto it = familyGraph.find(relativeID);
		if (it == familyGraph.end()) {
			cout << "No relationship data for this person.\n";
			return;
		}

		const Relationships& rel = it->second;

		cout << "----- Family Tree for "
			<< relative.getFirstName() << " " << relative.getLastName() << " -----\n\n";

		// Parents
		cout << "Parents:\n";
		if (rel.father) {
			cout << " - Father: " << rel.father->getFirstName() << " " << rel.father->getLastName() << '\n';
		}
		if (rel.mother) {
			cout << " - Mother: " << rel.mother->getFirstName() << " " << rel.mother->getLastName() << '\n';
		}
		if (!rel.father && !rel.mother) {
			cout << " (No Parent Record Found)\n";
		}

		// Siblings
		cout << "\nSiblings:\n";
		if (rel.siblings.empty()) {
			cout << " (No Sibling Record Found)\n";
		}
		else {
			for (auto sib : rel.siblings) {
				cout << " - " << sib->getFirstName()
					<< " " << sib->getLastName()
					<< " (" << sib->getGender() << ")\n";
			}
		}

		// Spouse
		cout << "\nSpouse:\n";
		if (!rel.spouse) {
			cout << " (No Spouse Record Found)\n";
		}
		else {
			cout << rel.spouse->getFirstName() << " " << rel.spouse->getFirstName() << '\n';
		}

		//Children
		cout << "\nChildren:\n";
		if (rel.children.empty()) {
			cout << " (No Children Record Found)\n";
		}
		else {
			for (auto kid : rel.children) {
				cout << " - " << kid->getFirstName()
					<< " " << kid->getLastName()
					<< " (" << kid->getGender() << ")\n";
			}
		}

		// Grandparents
		cout << "\nGrandparents: ";
		if (rel.grandparents.empty()) {
			cout << " (No Grandparent Record Found)\n";
		}
		else {
			for (auto gp : rel.grandparents) {
				string generation;
				for (int i = 1; i < gp.second; i++) {
					generation.append("Great ");
				}
				cout << " - " << gp.first->getFirstName()
					<< " " << gp.first->getLastName()
					<< "\n (" << generation << "Grandparent)\n"
					<< " - Gender: " << gp.first->getGender();
			}
		}
	}
private:
	// family network as a graph
	std::unordered_map<string, Relative> family;
	std::unordered_map<string, Relationships> familyGraph;
};