#pragma once
#include "Relative.cpp"

#include <unordered_map>

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
	string makeID(const Relative& relative) {
		return relative.getFirstName() + " " + relative.getMiddleName() + " " + relative.getLastName()
			+ " " + relative.getBirthDate();
	}
	void addRelative(const Relative& relative) {
			string id = makeID(relative);
			family[id] = relative;
			familyGraph.emplace(id, Relationships{});
	}

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
	

private:
	// family network as a graph
	std::unordered_map<string, Relative> family;
	std::unordered_map<string, Relationships> familyGraph;
};