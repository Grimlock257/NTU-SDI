#include "Crew.h"

// Constructor & deconstructor
Crew::Crew(const unsigned int id, string producer, string director, string writer, int numCast, string editor, string prodDesign, string setDeco, string costumeDesign) :
	id(id),
	producer(producer),
	director(director),
	writer(writer),
	numCast(numCast),
	editor(editor),
	prodDesign(prodDesign),
	setDeco(setDeco),
	costumeDesign(costumeDesign) {
}

Crew::~Crew() {
}

// Getters and setters for member attributes
unsigned int Crew::get_id() const {
	return this->id;
}

string Crew::get_producer() const {
	return this->producer;
}

void Crew::set_producer(const string & value) {
	this->producer = value;
}

string Crew::get_director() const {
	return this->director;
}

void Crew::set_director(const string & value) {
	this->director = value;
}

string Crew::get_writer() const {
	return this->writer;
}

void Crew::set_writer(const string & value) {
	this->writer = value;
}

int Crew::get_numCast() const {
	return this->numCast;
}

void Crew::set_numCast(const int & value) {
	this->numCast = value;
}

string Crew::get_editor() const {
	return this->editor;
}

void Crew::set_editor(const string & value) {
	this->editor = value;
}

string Crew::get_prodDesign() const {
	return this->prodDesign;
}

void Crew::set_prodDesign(const string & value) {
	this->prodDesign = value;
}

string Crew::get_setDeco() const {
	return this->setDeco;
}

void Crew::set_setDeco(const string & value) {
	this->setDeco = value;
}

string Crew::get_costumeDesign() const {
	return this->costumeDesign;
}

void Crew::set_costumeDesign(const string & value) {
	this->costumeDesign = value;
}