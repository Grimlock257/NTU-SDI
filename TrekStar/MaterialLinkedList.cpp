#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "MaterialLinkedList.h"

using namespace std;

//constructor
MaterialList::MaterialList()
{
	head = nullptr;
	curr = nullptr;
	temp = nullptr;

	vector<Material> all_materials = read_file();
	for (const Material& all_materials : all_materials)
	{
		add_node(all_materials);
	}
}

void MaterialList::add_node(const Material& add_material)
{
	node_ptr new_node_ptr = new TrekStarProjectM;
	new_node_ptr->material = add_material;
	new_node_ptr->next = nullptr;

	if (head != nullptr) 
	{
		// Existing data in LinkedList so find end of the LinkedList and add this new node
		curr = head;
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = new_node_ptr;
	}
	else 
	{
		// Empty LinkedList so set head to be this new node
		head = new_node_ptr;
	}
}

void MaterialList::delete_node(const string& title) {
	node_ptr prev = head;
	curr = head;
	temp = head;

	// Empty list so exit function
	if (head == nullptr) {
		cout << "The material list is empty, " << title << " not deleted\n";
		return;
	}

	// Loop through all elements
	while (curr != nullptr) {
		// Check iteration title matches supplied title, if so, delete and return
		if (curr->material.get_title() == title) {
			// Project to delete is the first one
			if (curr == head) {
				head = curr->next;
				delete curr;
			}
			else {
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
	throw std::invalid_argument("No material was found with title '" + title + "'. Deletion failed!");
}

void MaterialList::print_material_list() {
	curr = head;

	cout << "Material List : \n";
	while (curr != nullptr) {
		curr->material.display();
		cout << "\n";

		curr = curr->next;
	}
}

void MaterialList::write_file() const
{
	node_ptr write;
	ofstream writeProjectFile;
	writeProjectFile.open("Materials.txt", ios::out);

	if (!writeProjectFile) {
		// TODO: Replace with throw
		cout << "Error opening file\n";
	}

	for (write = head; write != nullptr; write = write->next) {
		writeProjectFile << write->material.get_title() << ";" << write->material.get_video_format() << ";" << write->material.get_audio_format() << ";" << write->material.get_run_time() << ";" << write->material.get_language() << ";" << write->material.get_retail_price() << ";" << write->material.get_subtitles() << ";" << write->material.get_frame_aspect() << ";" << write->material.get_packaging_material() << ";" << endl;
	}

	writeProjectFile.close();
}


vector<string> MaterialList::split_by_comma(const string& input_string) const {
	vector<string> tokens;
	string token;

	stringstream ss(input_string);

	while (getline(ss, token, ';')) {
		tokens.push_back(token);
	}

	return tokens;
}


vector<Material> MaterialList::read_file() const {
	vector<Material> all_materials;

	ifstream readProjectFile;
	string line;

	readProjectFile.open("Materials.txt", ios::in);
	if (!readProjectFile) return all_materials;

	while (getline(readProjectFile, line)) {
		vector<string> parts = split_by_comma(line);

		// TODO: 10 is amount of expected properties to be read from the file
		if (parts.size() != 9) {
			// TODO: Replace with throw exception
			cout << "Incorrect amount of properties from the file. Found " << parts.size() << " instead of 8. Project could not be read." << endl;
		}
		else {
			string title = parts[0];
			string video_format = parts[1];
			string audio_format = parts[2];
			string run_time = parts[3];
			string language = parts[4];
			string retail_price = parts[5];
			string subtitles = parts[6]; // TODO: Should be int
			string frame_aspect = parts[7];
			string packaging_material = parts[8]; // TODO: Should be double
			

			all_materials.emplace_back(1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material);
		}
		cout << endl;
	}

	return all_materials;
}

// Untested
Material MaterialList::search_by_title(const string& title) {
	Material material;
	curr = head;

	// While current node isn't a nullptr
	while (curr != nullptr) {
		// Check if iteration project title matches search title, if so set this value and break
		if (curr->material.get_title() == title) {
			material = curr->material;
			break;
		}

		// Wasn't found so look at the next node
		curr = curr->next;
	}

	return material;
}

// Untested
//vector<string> ProjectList::search_by_actor(const string& actor_name) {
//	vector<string> project_titles;
//	curr = head;
//
//	// While current node isn't a nullptr
//	while (curr != nullptr) {
//		vector<unsigned int> project_crew = curr->project.get_crew();
//
//		for (int i = 0; i < project_crew.size(); i++) {
//			if (project_crew[i] == 1) { // TODO: Change this to == actor_name
//				project_titles.push_back(curr->project.get_title());
//			}
//		}
//
//		curr = curr->next;
//	}
//
//	return project_titles;
//}
