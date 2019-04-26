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

void ProjectList::add_node(const Project& add_project) {
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

void ProjectList::delete_node(const string& title) {
	node_ptr prev = head;
	curr = head;
	temp = head;

	// Empty list so exit function
	if (head == nullptr) {
		cout << "The project list is empty, " << title << " not deleted\n";
		return;
	}

	// Loop through all elements
	while (curr != nullptr) {
		// Check iteration title matches supplied title, if so, delete and return
		if (curr->project.get_title() == title) {
			// Project to delete is the first one
			if (curr == head) {
				head = curr->next;
				delete curr;
			} else {
				temp = curr;
				prev->next = curr->next;
				delete curr;
			}

			return;
		}

		// No match, move to next node in the LinkedList
		prev = curr;
		curr = curr->next;
	}

	// No project found matching supplied title, throw error
	throw std::invalid_argument("No project was found with title '" + title + "'. Deletion failed!");
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

// Untested
Project ProjectList::search_by_title(const string& title) {
	Project project;
	curr = head;

	// While current node isn't a nullptr
	while (curr != nullptr) {
		// Check if iteration project title matches search title, if so set this value and break
		if (curr->project.get_title() == title) {
			project = curr->project;
			break;
		}

		// Wasn't found so look at the next node
		curr = curr->next;
	}

	return project;
}

// Untested
vector<string> ProjectList::search_by_actor(const string& actor_name) {
	vector<string> project_titles;
	curr = head;

	// While current node isn't a nullptr
	while (curr != nullptr) {
		vector<unsigned int> project_crew = curr->project.get_crew();

		for (int i = 0; i < project_crew.size(); i++) {
			if (project_crew[i] == 1) { // TODO: Change this to == actor_name
				project_titles.push_back(curr->project.get_title());
			}
		}

		curr = curr->next;
	}

	return project_titles;
}
