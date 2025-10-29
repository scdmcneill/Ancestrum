#pragma once
#include <iostream>  
#include <vector>  
#include <string>  

using std::string;  
using std::cout;  
using std::cin;  

class Relative {  
public:  
   // Default Constructor  
   Relative(string fName, string lName, char gender) : firstName(fName), lastName(lName), gender(gender), isLiving(true) {}  

   // Partial Constructor (with middle name)  
   Relative(std::string fName, string mName, string lName, char gender) : firstName(fName), middleName(mName),  
       lastName(lName), gender(gender), isLiving(true) { }  

   // Full Constructor  
   Relative(string fName, string mName, string lName, char gender,  
       string bDate, bool living, string dDate,  
       string bPlace, string dPlace, string occ,  
       string edu, string bio) : firstName(fName), middleName(mName), lastName(lName), gender(gender),
       birthDate(bDate), isLiving(true), deathDate(dDate), birthPlace(bPlace), deathPlace(dPlace),  
       occupation(occ), education(edu), biography(bio) {  
   }  

   // getters  
   string getFirstName() const { return firstName; }  
   string getMiddleName() const { return middleName; }  
   string getLastName() const { return lastName; }  
   char getGender() const { return gender; }  
   string getBirthDate() const { return birthDate; }  
   bool getIsLiving() const { return isLiving; }  
   string getDeathDate() const { return deathDate; }  
   string getBirthPlace() const { return birthPlace; }  
   string getDeathPlace() const { return deathPlace; }  
   string getOccupation() const { return occupation; }  
   string getEducation() const { return education; }  
   string getBiography() const { return biography; }  

   // mutators  
   void setFirstName(const string& fName) { firstName = fName; }  
   void setMiddleName(const string& mName) { middleName = mName; }  
   void setLastName(const string& lName) { lastName = lName; }  
   void setBirthDate(const string& bDate) { birthDate = bDate; }  
   void setLiving(bool living) { isLiving = living; }  
   void setDeathDate(const string& dDate) { deathDate = dDate; }  
   void setBirthPlace(const string& bPlace) { birthPlace = bPlace; }  
   void setDeathPlace(const string& dPlace) { deathPlace = dPlace; }  
   void setOccupation(const string& occ) { occupation = occ; }  
   void setEducation(const string& edu) { education = edu; }  
   void setBiography(const string& bio) { biography = bio; }  

   void displayRelative() {
       cout << "----- Relative Information -----\n";
       cout << "First Name: " << firstName << "\n";
       cout << "Middle Name: " << middleName << "\n";
       cout << "Last Name: " << lastName << '\n';
       cout << "Gender: " << gender << '\n';
       cout << "Birth Date: " << birthDate << '\n';
       cout << "Living: " << (isLiving ? "Yes" : "No") << '\n';
       if (!isLiving) {
           cout << "Death Date: " << deathDate << '\n';
       }
       cout << "Birth Place: " << birthPlace << '\n';
       if (!isLiving) {
           cout << "Death Place: " << deathPlace << '\n';
       }
       cout << "Occupation: " << occupation << '\n';
       cout << "Education: " << education << '\n';
       cout << "Biography: " << biography << '\n';
   }


private:  
   string firstName;  
   string middleName;  
   string lastName;  
   char gender;  

   string birthDate;  
   bool isLiving = true;  
   string deathDate;  
   string birthPlace;  
   string deathPlace;  

   string occupation;  
   string education;  
   string biography;  
};

