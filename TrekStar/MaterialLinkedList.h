#pragma once

#include "Material.h"

//#include "PackagingMaterial.h"

class MaterialList {
private:
	typedef struct TrekStarProjectM {
		Material material;
		//string title;
		//string video_format;
		//string audio_format;
		//string run_time;
		//string language;
		//string retail_price;
		//string subtitles;
		//string frame_aspect;
		////PackagingMaterial packaging_material;

		TrekStarProjectM *next;
	}*node_ptr;

	node_ptr head;
	node_ptr curr;
	node_ptr temp;

public: //funcions
	MaterialList(); //set initial values for head,curr,temp
	void add_node(const Material* add_material);
	void delete_node(const string& title);
	void print_material_list();
	void write_file() const;
	Material search_by_title(const string& title);
	//vector<string> search_by_actor(const string& actor_name);
	vector<string> split_by_comma(const string& input_string) const; // TODO: Util?
	vector<Material> read_file() const;

};
