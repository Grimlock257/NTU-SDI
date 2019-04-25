#include <iostream>

#include "DoubleSidedDVD.h"

using namespace std;

// Constructor & deconstructor
DoubleSidedDVD::DoubleSidedDVD(unsigned int id, string title, string video_format, string audio_format, string run_time, string language, string retail_price, string subtitles, string frame_aspect, string packaging_material, vector<string> additional_languages, vector<string> additional_subtitles, vector<string> bonus_features, string side_a_content, string side_b_content)
	: DVD(id, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material, additional_languages, additional_subtitles, bonus_features), side_a_content(side_a_content), side_b_content(side_b_content) {
}

DoubleSidedDVD::~DoubleSidedDVD() {
}

// Methods
void DoubleSidedDVD::print() const {
	cout << "ID: " << this->id << endl
		<< "Title: " << this->title << endl
		<< "Video Format: " << this->video_format << endl
		<< "Audio Format: " << this->audio_format << endl
		<< "Run Time: " << this->run_time << endl
		<< "Default Language: " << this->language << endl
		<< "Retail Price: " << this->retail_price << endl
		<< "Default Subtitles: " << this->subtitles << endl
		<< "Aspect Ratio: " << this->frame_aspect << endl
		<< "Packaging Material: " << this->packaging_material << endl
		<< "Additional Languages: " << this->additional_languages << endl
		<< "Additional Subtitles: " << this->additional_subtitles << endl
		<< "Bonus Features: " << this->bonus_features << endl
		<< "Side A Content: " << this->side_a_content << endl
		<< "Side B Content: " << this->side_b_content << endl;
}

// Getters and setters for member attributes
string DoubleSidedDVD::get_side_a() const {
	return this->side_a_content;
}

void DoubleSidedDVD::set_side_a(const string& value) {
	this->side_a_content = value;
}

string DoubleSidedDVD::get_side_b() const {
	return this->side_b_content;
}

void DoubleSidedDVD::set_side_b(const string& value) {
	this->side_b_content = value;
}
