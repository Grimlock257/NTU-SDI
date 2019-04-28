#pragma once

#include "Material.h"

//#include "PackagingMaterial.h"

class MaterialList {
private:
	typedef struct TrekStarProjectM {
		Material* material;
		TrekStarProjectM *next;
	}*node_ptr;

	node_ptr head;
	node_ptr curr;
	node_ptr temp;

public: //funcions
	MaterialList(); //set initial values for head,curr,temp
	void add_node(Material* add_material);
	void delete_node(const string& title);
	void print_material_list();
	void write_file() const;
	Material* search_by_title(const string& title);
	vector<string> split_by_comma(const string& input_string) const; // TODO: Util?
	vector<string> split_by_comma2(const string& input_string) const; // TODO: Util?
	vector<Material*> read_file() const;
};
