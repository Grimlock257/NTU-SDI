#include <string>

#include "Project.h"

using namespace std;

// Constructor & deconstructor
Project::Project(unsigned int projectId, string projectTitle, string projectSummary, string projectGenre, string projectDateRelease, string projectFilmingLoc, string projectLanguage, int projectRuntime, string projectKeywords, double projectTicketSale, string projectStatus)
	: projectId(projectId),
	projectTitle(projectTitle),
	projectSummary(projectSummary),
	projectGenre(projectGenre),
	projectDateRelease(projectDateRelease),
	projectFilmingLoc(projectFilmingLoc),
	projectLanguage(projectLanguage),
	projectRuntime(projectRuntime),
	projectKeywords(projectKeywords),
	projectTicketSale(projectTicketSale),
	projectStatus(projectStatus) {
}

Project::~Project() {
}

// Getters and setters for member attributes
unsigned int Project::get_projectId() const {
	return this->projectId;
}

string Project::get_projectTitle() const {
	return this->projectTitle;
}

void Project::set_projectTitle(const string& value) {
	this->projectTitle = value;
}

string Project::get_projectSummary() const {
	return this->projectSummary;
}

void Project::set_projectSummary(const string& value) {
	this->projectSummary = value;
}

string Project::get_projectGenre() const {
	return this->projectGenre;
}

void Project::set_projectGenre(const string& value) {
	this->projectGenre = value;
}

string Project::get_projectDateRelease() const {
	return this->projectDateRelease;
}

void Project::set_projectDateRelease(const string& value) {
	this->projectDateRelease = value;
}

string Project::get_projectFilmingLoc() const {
	return this->projectFilmingLoc;
}

void Project::set_projectFilmingLoc(const string& value) {
	this->projectFilmingLoc = value;
}

string Project::get_projectLanguage() const {
	return this->projectLanguage;
}

void Project::set_projectLanguage(const string& value) {
	this->projectLanguage = value;
}

int Project::get_projectRuntime() const {
	return this->projectRuntime;
}

void Project::set_projectRuntime(const int& value) {
	this->projectRuntime = value;
}

string Project::get_projectKeywords() const {
	return this->projectKeywords;
}

void Project::set_projectKeywords(const string& value) {
	this->projectKeywords = value;
}

double Project::get_projectTicketSale() const {
	return this->projectTicketSale;
}

void Project::set_projectTicketSale(const double& value) {
	this->projectTicketSale = value;
}

string Project::get_projectStatus() const {
	return this->projectStatus;
}

void Project::set_projectStatus(const string& value) {
	this->projectStatus = value;
}