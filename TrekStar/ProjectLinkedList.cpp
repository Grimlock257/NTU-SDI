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
		writeProjectFile << write->project.get_projectId() << ";" << write->project.get_title() << ";" << write->project.get_summary() << ";" << write->project.get_genre() << ";" << write->project.get_date_release() << ";" << write->project.get_filming_loc() << ";" << write->project.get_language() << ";" << write->project.get_runtime() << ";" << write->project.get_keywords() << ";" << write->project.get_ticket_sale() << ";" << write->project.get_status() << ";" << endl;
	}

	writeProjectFile.close();
}

void ProjectList::update_node(int id, const Project& update_project) {
	curr = head;

	while (curr != nullptr) {
		if (curr->project.get_projectId() == id) {
			string temp;
			int tempI;

			curr->project.display();

			temp = UserInput::get_string_input("Enter updated project title:");
			curr->project.set_title(temp);
			temp = UserInput::get_string_input("Enter updated project summary:");
			curr->project.set_summary(temp);
			temp = UserInput::get_string_input("Enter updated project genre:");
			curr->project.set_genre(temp);
			temp = UserInput::get_string_input("Enter updated project date release:");
			curr->project.set_date_release(temp);
			temp = UserInput::get_string_input("Enter updated project filming location:");
			curr->project.set_filming_loc(temp);
			temp = UserInput::get_string_input("Enter updated project language:");
			curr->project.set_language(temp);
			tempI = UserInput::get_integer_input("Enter updated project runtime:");
			curr->project.set_runtime(tempI);
			temp = UserInput::get_string_input("Enter updated project keywords:");
			curr->project.set_keywords(temp);
		}

		curr = curr->next;
	}
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
		if (parts.size() != 11) {
			// TODO: Replace with throw exception
			cout << "Incorrect amount of properties from the file. Found " << parts.size() << " instead of 11. Project could not be read." << endl;
		} else {
			unsigned int id = stoi(parts[0]);
			string title = parts[1];
			string summary = parts[2];
			string genre = parts[3];
			string date_release = parts[4];
			string filming_loc = parts[5];
			string language = parts[6];
			string runtime = parts[7]; // TODO: Should be int
			string keywords = parts[8];
			string ticket_sale = parts[9]; // TODO: Should be double
			string status = parts[10];

			// TODO: ID property
			all_projects.emplace_back(id, title, summary, genre, date_release, filming_loc, language, 1, keywords, 1, status);
		}
	}

	return all_projects;
}

// Untested
vector<Project> ProjectList::search_by_title(const string& title) {
	vector<Project> found_projects;
	curr = head;

	// While current node isn't a nullptr
	while (curr != nullptr) {
		// Check if iteration project title matches search title, if so add to found projects
		if (curr->project.get_title() == title) {
			found_projects.push_back(curr->project);
		}

		curr = curr->next;
	}

	return found_projects;
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

unsigned int ProjectList::get_next_id() {
	curr = head;

	while (curr != nullptr && curr->next != nullptr) {
		curr = curr->next;
	}

	return (curr != nullptr) ? curr->project.get_projectId() + 1 : 1;
}