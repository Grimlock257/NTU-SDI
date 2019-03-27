#pragma once

#include<string>

using namespace std;

class Crew {
public:
	// Constructor & deconstructor
	Crew(const unsigned int id, string producer, string director, string writer, int numCast, string editor, string prodDesign, string setDeco, string costumeDesign);
	~Crew();

	// Getters and setters for member attributes
	unsigned int get_id() const;

	string get_producer() const;
	void set_producer(const string& value);

	string get_director() const;
	void set_director(const string& value);

	string get_writer() const;
	void set_writer(const string& value);

	int get_numCast() const;
	void set_numCast(const int& value);

	string get_editor() const;
	void set_editor(const string& value);

	string get_prodDesign() const;
	void set_prodDesign(const string& value);

	string get_setDeco() const;
	void set_setDeco(const string& value);

	string get_costumeDesign() const;
	void set_costumeDesign(const string& value);

protected:
	// General crew information
	const unsigned int id;
	string producer;
	string director;
	string writer;
	int numCast;
	string editor;
	string prodDesign;
	string setDeco;
	string costumeDesign;
};