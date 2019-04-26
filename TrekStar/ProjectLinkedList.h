#pragma once
#include "Project.h"

class ProjectList {
private:
	// Node
	typedef struct TrekStarProject {
		Project project;
		TrekStarProject *next;

	}*node_ptr;

	node_ptr head;
	node_ptr curr;
	node_ptr temp;

public:
	// Constructor
	ProjectList(); // Set initial values for head, curr, temp

	// Functions
	void add_node(Project add_project);
	void delete_node(Project del_project);
	void PrintProjectList();
	void writeFile();
	//void readFile(node_ptr read);
	//void WriteToFile(string wTitle, string wSummary, string wGenre, string wDateRel, string wFimLoc, string wLang, int wRuntime, string wKey, double wTicSale, string wStatus);
};