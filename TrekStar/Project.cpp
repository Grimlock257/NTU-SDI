#include <string>

#include "Project.h"

using namespace std;

// Constructor & deconstructor
Project::Project() {
}

Project::Project(unsigned int projectId, string projectTitle, string projectSummary, string projectGenre, string projectDateRelease, string projectFilmingLoc, string projectLanguage, int projectRuntime, string projectKeywords, double projectTicketSale, string projectStatus)
	: id(projectId),
	title(projectTitle),
	summary(projectSummary),
	genre(projectGenre),
	date_release(projectDateRelease),
	filming_loc(projectFilmingLoc),
	language(projectLanguage),
	runtime(projectRuntime),
	keywords(projectKeywords),
	ticket_sale(projectTicketSale),
	status(projectStatus) {
}

Project::~Project() {
}

// Getters and setters for member attributes
unsigned int Project::get_projectId() const {
	return this->id;
}

string Project::get_title() const {
	return this->title;
}

void Project::set_title(const string& value) {
	this->title = value;
}

string Project::get_summary() const {
	return this->summary;
}

void Project::set_summary(const string& value) {
	this->summary = value;
}

string Project::get_genre() const {
	return this->genre;
}

void Project::set_genre(const string& value) {
	this->genre = value;
}

string Project::get_date_release() const {
	return this->date_release;
}

void Project::set_date_release(const string& value) {
	this->date_release = value;
}

string Project::get_filming_loc() const {
	return this->filming_loc;
}

void Project::set_filming_loc(const string& value) {
	this->filming_loc = value;
}

string Project::get_language() const {
	return this->language;
}

void Project::set_language(const string& value) {
	this->language = value;
}

int Project::get_runtime() const {
	return this->runtime;
}

void Project::set_runtime(const int& value) {
	this->runtime = value;
}

string Project::get_keywords() const {
	return this->keywords;
}

void Project::set_keywords(const string& value) {
	this->keywords = value;
}

double Project::get_ticket_sale() const {
	return this->ticket_sale;
}

void Project::set_ticket_sale(const double& value) {
	this->ticket_sale = value;
}

string Project::get_status() const {
	return this->status;
}

void Project::set_status(const string& value) {
	this->status = value;
}