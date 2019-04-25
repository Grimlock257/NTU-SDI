#include <iostream>

#include "DVD.h"

using namespace std;

// Constructor & deconstructor
DVD::DVD(unsigned int id, string title, string video_format, string audio_format, string run_time, string language, string retail_price, string subtitles, string frame_aspect, string packaging_material, vector<string> additional_languages, vector<string> additional_subtitles, vector<string> bonus_features)
	: Material(id, title, video_format, audio_format, run_time, language, retail_price, subtitles, frame_aspect, packaging_material), additional_languages(additional_languages), additional_subtitles(additional_subtitles), bonus_features(bonus_features) {
}

DVD::~DVD() {
}

// Methods
void DVD::print() const {
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
		<< "Bonus Features: " << this->bonus_features << endl;
}

// Getters and setters for member attributes
vector<string> DVD::get_additional_languages() const {
	return this->additional_languages;
}

void DVD::set_additional_languages(const vector<string>& value) {
	this->additional_languages = value;
}

vector<string> DVD::get_additional_subtitles() const {
	return this->additional_subtitles;
}

void DVD::set_additional_subtitles(const vector<string>& value) {
	this->additional_subtitles = value;
}

vector<string> DVD::get_bonus_features() const {
	return this->bonus_features;
}

void DVD::set_bonus_features(const vector<string>& value) {
	this->bonus_features = value;
}
