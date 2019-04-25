#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "ProjectLinkedList.h"

using namespace std;

//constructor
ProjectList::ProjectList() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void ProjectList::AddNode(Project add_project) {
	nodePtr n = new TrekStarProject;
	n->project = add_project;
	n->next = NULL;

	if (head != NULL) {
		//have a data
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	} else {
		//will create new data
		head = n;
	}
}

void ProjectList::DeleteNode(Project del_project) {
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;
	if (delPtr == head)
		while (curr != NULL
			&& curr->project.get_title() != del_project.get_title()
			&& curr->project.get_summary() != del_project.get_summary()
			&& curr->project.get_genre() != del_project.get_genre()
			&& curr->project.get_date_release() != del_project.get_date_release()
			&& curr->project.get_filming_loc() != del_project.get_filming_loc()
			&& curr->project.get_language() != del_project.get_language()
			&& curr->project.get_runtime() != del_project.get_runtime()
			&& curr->project.get_keywords() != del_project.get_keywords()
			&& curr->project.get_ticket_sale() != del_project.get_ticket_sale()
			&& curr->project.get_status() != del_project.get_status()) {

			temp = curr;
			curr = curr->next;
		}
	if (curr == NULL) {
		cout << del_project.get_title() << " was not in the list\n";
		delete delPtr;
	} else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if (delPtr == head) {
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << "The project " << del_project.get_title() << " was deleted\n";
	}
}



void ProjectList::PrintProjectList() {
	curr = head;
	cout << "Display Project List : \n";
	while (curr != NULL) {
		cout << curr->project.get_title() << ", " << curr->project.get_summary() << ", " << curr->project.get_genre() << ", " << curr->project.get_date_release() << ", " << curr->project.get_filming_loc() << ", " << curr->project.get_language() << ", " << curr->project.get_runtime() << ", " << curr->project.get_keywords() << ", " << curr->project.get_ticket_sale() << ", " << curr->project.get_status() << endl;
		cout << "\n";
		curr = curr->next;
	}
}

void ProjectList::writeFile() {
	nodePtr write;
	ofstream writeProjectFile;
	writeProjectFile.open("OutputFile.txt", ios::app);
	if (!writeProjectFile) {
		cout << "Error opening file\n";
	}
	for (write = head; write != NULL; write = write->next) {
		writeProjectFile << write->project.get_title() << "; " << write->project.get_summary() << "; " << write->project.get_genre() << "; " << write->project.get_date_release() << "; " << write->project.get_filming_loc() << "; " << write->project.get_language() << "; " << write->project.get_runtime() << "; " << write->project.get_keywords() << "; " << write->project.get_ticket_sale() << "; " << write->project.get_status() << ";\n " << endl;
	}
	writeProjectFile.close();
}

//void ProjectList::readFile(nodePtr read)
//{
//	ifstream readProjectFile;
//	readProjectFile.open("OutputFile.txt", ios::in);
//	if (!readProjectFile) return;
//
//	while (!readProjectFile.eof())
//	{
//		nodePtr read;
//		getline()
//	}
//}

//void ProjectList::WriteToFile(string wTitle, string wSummary, string wGenre, string wDateRel, string wFimLoc, string wLang, int wRuntime, string wKey, double wTicSale, string wStatus)
//{
//	ofstream writeProjectFile;
//	writeProjectFile.open("OutputFile.txt", ios::app);
//
//	
//	nodePtr write = new TrekStarProject;
//	write->next = NULL;
//	write->title = wTitle;
//	write->summary = wSummary;
//	write->genre = wGenre;
//	write->date_release = wDateRel;
//	write->filming_loc = wFimLoc;
//	write->language = wLang;
//	write->runtime = wRuntime;
//	write->keywords = wKey;
//	write->ticket_sale = wTicSale;
//	write->status = wStatus;
//
//	if (!writeProjectFile)
//	{
//		head = write;
//		curr = NULL;
//		temp = NULL;
//
//		if (head != NULL) //have a data
//		{
//			curr = head;
//			while (curr->next != NULL)
//			{
//				curr = curr->next;
//			}
//			curr->next = write;
//			writeProjectFile << write->title << "; " << write->summary << "; " << write->genre << "; " << write->date_release << "; " << write->filming_loc << "; " << write->language << "; " << write->runtime << "; " << write->keywords << "; " << write->ticket_sale << "; " << write->status << ";\n " << endl;
//		}
//		else //will create new data
//		{
//			head = write;
//			writeProjectFile << write->title << "; " << write->summary << "; " << write->genre << "; " << write->date_release << "; " << write->filming_loc << "; " << write->language << "; " << write->runtime << "; " << write->keywords << "; " << write->ticket_sale << "; " << write->status << ";\n " << endl;
//		}
//	}	
//}
