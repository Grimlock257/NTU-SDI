#pragma once

#include <string>

using namespace std;

class Project {
public:

	// Constructor & deconstructor
	Project(unsigned int projectId, string projectTitle, string projectSummary, string projectGenre, string projectDateRelease, string projectFilmingLoc, string projectLanguage, int projectRuntime, string projectKeywords, double projectTicketSale, string projectStatus);
	~Project();

	// Getters and setters for member attributes
	unsigned int get_projectId() const;

	string get_projectTitle() const;
	void set_projectTitle(const string& value);

	string get_projectSummary() const;
	void set_projectSummary(const string& value);

	string get_projectGenre() const;
	void set_projectGenre(const string& value);

	string get_projectDateRelease() const;
	void set_projectDateRelease(const string& value);

	string get_projectFilmingLoc() const;
	void set_projectFilmingLoc(const string& value);

	string get_projectLanguage() const;
	void set_projectLanguage(const string& value);

	int get_projectRuntime() const;
	void set_projectRuntime(const int& value);

	string get_projectKeywords() const;
	void set_projectKeywords(const string& value);

	double get_projectTicketSale() const;
	void set_projectTicketSale(const double& value);

	string get_projectStatus() const;
	void set_projectStatus(const string& value);

protected:
	// General project information
	const unsigned int projectId;
	string projectTitle;
	string projectSummary;
	string projectGenre;
	string projectDateRelease;
	string projectFilmingLoc;
	string projectLanguage;
	int projectRuntime;
	string projectKeywords;
	double projectTicketSale;
	string projectStatus;
};
