#pragma once

#include "Project.h"
#include "UserInput.h"

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
	void add_node(const Project& add_project);
	void delete_node(const string& title);
	void print_project_list();
	void write_file() const;
	void update_node(int id, const Project& update_project);
	vector<Project> search_by_title(const string& title);
	vector<string> search_by_actor(const string& actor_name);
	vector<string> split_by_comma(const string& input_string) const;
	vector<Project> read_file() const;
	unsigned int get_next_id();
};