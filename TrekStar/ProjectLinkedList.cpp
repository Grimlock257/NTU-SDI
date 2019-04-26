#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "ProjectLinkedList.h"

using namespace std;

// Constructor
ProjectList::ProjectList() {
	head = nullptr;
	curr = nullptr;
	temp = nullptr;

	vector<Project> all_projects = read_file();

	for (const Project& all_project : all_projects) {
		add_node(all_project);
	}
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

void ProjectList::print_project_list() {
	curr = head;

	cout << "Project List : \n";
	while (curr != nullptr) {
		curr->project.display();
		cout << "\n";

		curr = curr->next;
	}
}

void ProjectList::write_file() const {
	node_ptr write;
	ofstream writeProjectFile;
	writeProjectFile.open("Projects.txt", ios::out);

	if (!writeProjectFile) {
		// TODO: Replace with throw
		cout << "Error opening file\n";
	}

	for (write = head; write != nullptr; write = write->next) {
		writeProjectFile << write->project.get_title() << ";" << write->project.get_summary() << ";" << write->project.get_genre() << ";" << write->project.get_date_release() << ";" << write->project.get_filming_loc() << ";" << write->project.get_language() << ";" << write->project.get_runtime() << ";" << write->project.get_keywords() << ";" << write->project.get_ticket_sale() << ";" << write->project.get_status() << ";" << endl;
	}

	writeProjectFile.close();
}

vector<string> ProjectList::split_by_comma(const string& input_string) const {
	vector<string> tokens;
	string token;

	stringstream ss(input_string);

	while (getline(ss, token, ';')) {
		tokens.push_back(token);
	}

	return tokens;
}


vector<Project> ProjectList::read_file() const {
	vector<Project> all_projects;

	ifstream readProjectFile;
	string line;

	readProjectFile.open("Projects.txt", ios::in);
	if (!readProjectFile) return all_projects;

	while (getline(readProjectFile, line)) {
		vector<string> parts = split_by_comma(line);

		// TODO: 10 is amount of expected properties to be read from the file
		if (parts.size() != 10) {
			// TODO: Replace with throw exception
			cout << "Incorrect amount of properties from the file. Found " << parts.size() << " instead of 9. Project could not be read." << endl;
		} else {
			string title = parts[0];
			string summary = parts[1];
			string genre = parts[2];
			string date_release = parts[3];
			string filming_loc = parts[4];
			string language = parts[5];
			string runtime = parts[6]; // TODO: Should be int
			string keywords = parts[7];
			string ticket_sale = parts[8]; // TODO: Should be double
			string status = parts[9];

			all_projects.emplace_back(1, title, summary, genre, date_release, filming_loc, language, 1, keywords, 1, status);
		}
		cout << endl;
	}

	return all_projects;
}

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