# Ancestrum

## Author
Scott McNeill

## Overview
**Ancestrum** is a C++ application designed to model, store, and display complex family relationships in a structured and dynamic way.

The program allows users to:
- create and store information about individual relatives
- Link them through parent, sibling, spouse, and extended family relationships
- Generate readable family tree from any relative's perspective
- Generate readable biographies for family members

This project emphasizes object-oriented programming, data organization, and relationship modeling. This program
has served both as an educational exercise in software design and the foundation for a future
graphical user interface.

## Project Goals
- Build a fully functional family relationship graph using C++ data structures
- enable dynamic queries such as "show me the family tree from x's perspective"
- support printing and exporting family graphs to text or .dot formats
- evolve into a GUI-based desktop applications, allowing users to interact with and visualize family trees

## Current Features
### Object Oriented Design
Two core classes:
- Relative : encapsulates personal information for each individual
- FamilyTree : manages relationships between Relative objects

### Relative Data
Each Relative includes:
- name components (first, middle, last)
- gender and living status
- birth/death dates and lcoations
- occupation and education fields
- biography or notes

### Relationship Management
Supports: 
- Parent/child linking (setFather(), setMother())
- Sibling Relationships (addSibling())
- Spousal Relationships (setSpouse())
- Extended Relationships : aunts, uncles, cousins (planned expansion), grandparents (planned expansion)

### Querying
- Display all known family relationships for a given relative
- View a structured, human-readbale output of the family graph
- export the family network

## Planned Enhancements
### GUI Integration (Planned)
Ultimately this project will evolve into a full fledged graphical desktop application where users can:
- Add or edit relatives through interactive forms
- visually connect family members using nodes and edges
- pan, zoom, and reaarange the family tree dynamically
- export visual trees as PNG/SVG images

Planned GUI Framework Options:
- wxWidgets
- Qt
- ImGui

### Data Persistence
- save and load family data from files (JSON or XML)
- maintain unique IDs to prevent duplicates

### Extended Graph Logic
- Automatically infer cousins, grandparents, and descendants
- detect and prevent circular relationships
- support adoption or step-family relationships

### Visualization Options
- ASCII text-based tree view (for console)
- Full GUI tree with color-coded relationship types

## Technical Details
Component  >  Description  
Language  >  C++20  
Libraries > <iostream>, <vector>, <unordered_map>, <string>, <fstream>  
Paradigm  >  Object-Oriented Programming (OOP)  
Data Structure  >  Directed Graph (nodes = relatives, edges = relationships)  
Planned GUI Library  >  exWidgets/ Qt  
Compiler  >  g++/MSVC  

## About the Developer
Scott McNeill
- U.S. Army Veteran (35G - Geospatial Intelligence Imagery Analyst, 12 Years)
- Computer Science Major @ University of Houston-Downton
- Focus Areas: C++ development, AI, data visualization, and geospatial applicaitons/intelligence collection.
My goal with this project is to provide an easily accessible application for anyone to use to learn more about their familiy history  
as well as discover their past along the way. I have always had a passion for learning about my ancestry and many of those in my family
enjoy it as well. I envisioned creating an application that is inuitive enough so that older family members can enjoy building the family tree.
