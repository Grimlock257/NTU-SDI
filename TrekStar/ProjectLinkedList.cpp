#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "ProjectLinkedList.h"

using namespace std;

// Constructor
ProjectList::ProjectList() {
	head = nullptr;
	curr = nullptr;
	temp = nullptr;
}

void ProjectList::add_node(Project add_project) {
	node_ptr new_node_ptr = new TrekStarProject;
	new_node_ptr->project = add_project;
	new_node_ptr->next = nullptr;

	if (head != nullptr) {
		// Existing data in LinkedList so find end of the LinkedList and add this new node
		curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		}

		curr->next = new_node_ptr;
	} else {
		// Empty LinkedList so set head to be this new node
		head = new_node_ptr;
	}
}

void ProjectList::delete_node(Project del_project) {
	node_ptr del_node_ptr = nullptr;
	temp = head;
	curr = head;
	if (del_node_ptr == head) {
		while (curr != nullptr
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
	}

	if (curr == nullptr) {
		cout << del_project.get_title() << " was not in the list\n";
		delete del_node_ptr;
	} else {
		del_node_ptr = curr;
		curr = curr->next;
		temp->next = curr;

		if (del_node_ptr == head) {
			head = head->next;
			temp = nullptr;
		}

		delete del_node_ptr;
		cout << "The project " << del_project.get_title() << " was deleted\n";
	}
}

void ProjectList::PrintProjectList() {
	curr = head;
	cout << "Display Project List : \n";
	while (curr != nullptr) {
		cout << curr->project.get_title() << ", " << curr->project.get_summary() << ", " << curr->project.get_genre() << ", " << curr->project.get_date_release() << ", " << curr->project.get_filming_loc() << ", " << curr->project.get_language() << ", " << curr->project.get_runtime() << ", " << curr->project.get_keywords() << ", " << curr->project.get_ticket_sale() << ", " << curr->project.get_status() << endl;
		cout << "\n";
		curr = curr->next;
	}
}

void ProjectList::writeFile() {
	node_ptr write;
	ofstream writeProjectFile;
	writeProjectFile.open("OutputFile.txt", ios::app);

	if (!writeProjectFile) {
		cout << "Error opening file\n";
	}

	for (write = head; write != nullptr; write = write->next) {
		writeProjectFile << write->project.get_title() << "; " << write->project.get_summary() << "; " << write->project.get_genre() << "; " << write->project.get_date_release() << "; " << write->project.get_filming_loc() << "; " << write->project.get_language() << "; " << write->project.get_runtime() << "; " << write->project.get_keywords() << "; " << write->project.get_ticket_sale() << "; " << write->project.get_status() << ";\n " << endl;
	}

	writeProjectFile.close();
}

//void ProjectList::readFile(node_ptr read)
//{
//	ifstream readProjectFile;
//	readProjectFile.open("OutputFile.txt", ios::in);
//	if (!readProjectFile) return;
//
//	while (!readProjectFile.eof())
//	{
//		node_ptr read;
//		getline()
//	}
//}

//void ProjectList::WriteToFile(string wTitle, string wSummary, string wGenre, string wDateRel, string wFimLoc, string wLang, int wRuntime, string wKey, double wTicSale, string wStatus)
//{
//	ofstream writeProjectFile;
//	writeProjectFile.open("OutputFile.txt", ios::app);
//
//	
//	node_ptr write = new TrekStarProject;
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
