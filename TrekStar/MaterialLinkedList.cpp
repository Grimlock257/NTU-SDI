#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "MaterialLinkedList.h"
#include "SingleSidedDVD.h"
#include "DoubleSidedDVD.h"
#include "BluRay.h"
#include "ComboBox.h"
#include "VHS.h"

using namespace std;

//constructor
MaterialList::MaterialList() {
	head = nullptr;
	curr = nullptr;
	temp = nullptr;

	vector<Material*> all_materials = read_file();
	for (Material* material : all_materials) {
		add_node(material);
	}
}

void MaterialList::add_node(Material* add_material) {
	node_ptr new_node_ptr = new TrekStarProjectM;
	new_node_ptr->material = add_material;
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
		if (curr->material->get_title() == title) {
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
	throw std::invalid_argument("No material was found with title '" + title + "'. Deletion failed!");
}

void MaterialList::print_material_list() {
	curr = head;

	cout << "Material List : \n";
	while (curr != nullptr) {
		curr->material->print();
		cout << "\n";

		curr = curr->next;
	}
}

void MaterialList::write_file() const {
	node_ptr write;
	ofstream writeProjectFile;
	writeProjectFile.open("Materials.txt", ios::out);

	if (!writeProjectFile) {
		// TODO: Replace with throw
		cout << "Error opening file\n";
	}

	for (write = head; write != nullptr; write = write->next) {
		// writeProjectFile << write->material.get_title() << ";" << write->material.get_video_format() << ";" << write->material.get_audio_format() << ";" << write->material.get_run_time() << ";" << write->material.get_language() << ";" << write->material.get_retail_price() << ";" << write->material.get_subtitles() << ";" << write->material.get_frame_aspect() << ";" << write->material.get_packaging_material() << ";" << endl;
		writeProjectFile << write->material->get_savable();
	}

	writeProjectFile.close();
}

void MaterialList::update_node(int id) {
	curr = head;

	while (curr != nullptr) {
		if (curr->material->get_id() == id) {
			string temp;

			curr->material->print();
			curr->material->set_title(UserInput::get_string_input("Enter updated material title:"));
			curr->material->set_video_format(UserInput::get_string_input("Enter updated material video format:"));
			curr->material->set_audio_format(UserInput::get_string_input("Enter updated material audio format:"));
			curr->material->set_run_time(UserInput::get_string_input("Enter updated material run time:"));
			curr->material->set_language(UserInput::get_string_input("Enter updated material language:"));
			curr->material->set_retail_price(UserInput::get_string_input("Enter updated material retail price:"));
			curr->material->set_subtitles(UserInput::get_string_input("Enter updated material subtitles:"));
			curr->material->set_frame_aspect(UserInput::get_string_input("Enter updated material frame aspect:"));
			curr->material->set_packaging_material(UserInput::get_string_input("Enter updated material packaging material:"));
		}

		curr = curr->next;
	}
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

vector<string> MaterialList::split_by_comma2(const string& input_string) const {
	vector<string> tokens;
	string token;

	stringstream ss(input_string);

	while (getline(ss, token, '|')) {
		tokens.push_back(token);
	}

	return tokens;
}


vector<Material*> MaterialList::read_file() const {
	vector<Material*> all_materials;

	ifstream readMaterialFile;
	string line;

	readMaterialFile.open("Materials.txt", ios::in);
	if (!readMaterialFile) return all_materials;

	while (getline(readMaterialFile, line)) {
		vector<string> parts = split_by_comma(line);

		// TODO: 10 is amount of expected properties to be read from the file
		if (parts.size() < 11) {
			// TODO: Replace with throw exception
			cout << "Incorrect amount of properties from the file. Found " << parts.size() << " instead of the minimum 11. Material could not be read." << endl;
		} else {
			string material_type = parts[0];
			unsigned int id = stoi(parts[1]);
			string title = parts[2];
			string video_format = parts[3];
			string audio_format = parts[4];
			string run_time = parts[5];
			string language = parts[6];
			string retail_price = parts[7];
			string subtitles = parts[8];
			string frame_aspect = parts[9];
			string packaging_material = parts[10];

			// See what the material_type is so we can read the material into the correct data structure
			if (material_type == "SINGLESIDEDDVD") {
				vector<string> additional_languages = split_by_comma2(parts[11]);
				vector<string> additional_subtitles = split_by_comma2(parts[12]);
				vector<string> bonus_features = split_by_comma2(parts[13]);

				SingleSidedDVD* newSingleSidedDVD = new SingleSidedDVD(id, 1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material, additional_languages, additional_subtitles, bonus_features);
				all_materials.push_back(newSingleSidedDVD);
			} else if (material_type == "DOUBLESIDEDDVD") {
				vector<string> additional_languages = split_by_comma2(parts[11]);
				vector<string> additional_subtitles = split_by_comma2(parts[12]);
				vector<string> bonus_features = split_by_comma2(parts[13]);
				string side_a_content = parts[14];
				string side_b_content = parts[15];

				DoubleSidedDVD* newDoubleSidedDVD = new DoubleSidedDVD(id, 1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material, additional_languages, additional_subtitles, bonus_features, side_a_content, side_b_content);
				all_materials.push_back(newDoubleSidedDVD);
			} else if (material_type == "COMBOBOX") {
				ComboBox* newComboBox = new ComboBox(id, 1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material);
				all_materials.push_back(newComboBox);
			} else if (material_type == "VHS") {
				VHS* newVHS = new VHS(id, 1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material);
				all_materials.push_back(newVHS);
			} else if (material_type == "BLURAY") {
				vector<string> additional_languages = split_by_comma2(parts[11]);
				vector<string> additional_subtitles = split_by_comma2(parts[12]);
				vector<string> bonus_features = split_by_comma2(parts[13]);

				BluRay* newBluRay = new BluRay(id, 1, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material, additional_languages, additional_subtitles, bonus_features);
				all_materials.push_back(newBluRay);
			} else {
				// TODO: Throw
				cout << "Invalid material type found, don't know what '" + material_type + "'" << endl;
			}
		}
	}

	return all_materials;
}

// Untested
Material* MaterialList::search_by_title(const string& title) {
	Material* material = nullptr;
	curr = head;

	// While current node isn't a nullptr
	while (curr != nullptr) {
		// Check if iteration project title matches search title, if so set this value and break
		if (curr->material->get_title() == title) {
			material = curr->material;
			break;
		}

		// Wasn't found so look at the next node
		curr = curr->next;
	}

	return material;
}

unsigned int MaterialList::get_next_id() {
	curr = head;

	while (curr != nullptr && curr->next != nullptr) {
		curr = curr->next;
	}

	return (curr != nullptr) ? curr->material->get_id() + 1 : 1;
}