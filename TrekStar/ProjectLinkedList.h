#pragma once
#include "Project.h"

class ProjectList {
private:
	//node
	typedef struct TrekStarProject {
		Project project;
		TrekStarProject *next;

	}*nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;


public: //funcions
	ProjectList(); //set initial values for head,curr,temp
	void AddNode(Project add_project);
	void DeleteNode(Project del_project);
	void PrintProjectList();
	void writeFile();
	//void readFile(nodePtr read);
	//void WriteToFile(string wTitle, string wSummary, string wGenre, string wDateRel, string wFimLoc, string wLang, int wRuntime, string wKey, double wTicSale, string wStatus);
};