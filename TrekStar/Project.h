#pragma once

#include <string>
#include <vector>

#include "Crew.h"

using namespace std;

class Project {
public:

	// Constructor & deconstructor
	Project();
	Project(unsigned int projectId, string projectTitle, string projectSummary, string projectGenre, string projectDateRelease, string projectFilmingLoc, string projectLanguage, int projectRuntime, string projectKeywords, double projectTicketSale, string projectStatus);
	~Project();

	// Getters and setters for member attributes
	unsigned int get_projectId() const;

	string get_title() const;
	void set_title(const string& value);

	string get_summary() const;
	void set_summary(const string& value);

	string get_genre() const;
	void set_genre(const string& value);

	string get_date_release() const;
	void set_date_release(const string& value);

	string get_filming_loc() const;
	void set_filming_loc(const string& value);

	string get_language() const;
	void set_language(const string& value);

	int get_runtime() const;
	void set_runtime(const int& value);

	string get_keywords() const;
	void set_keywords(const string& value);

	double get_ticket_sale() const;
	void set_ticket_sale(const double& value);

	string get_status() const;
	void set_status(const string& value);

	// TODO: Edit crew?
	vector<unsigned int> get_crew() const;
	void set_crew(const vector<unsigned int>& value);

protected:
	// General project information
	unsigned int id;
	string title;
	string summary;
	string genre;
	string date_release;
	string filming_loc;
	string language;
	int runtime;
	string keywords;
	double ticket_sale;
	string status;

	vector<unsigned int> crew;
	vector<unsigned int> materials;
};
