#pragma once

#include <iostream>
#include <vector>

#include "Material.h"

using namespace std;

class DVD : public Material {
public:
	// Constructor & deconstructor
	DVD(unsigned int id, unsigned int project_id, string title, string video_format, string audio_format, string run_time, string language, string retail_price, string subtitles, string frame_aspect, string packaging_material, vector<string> additional_languages, vector<string> additional_subtitles, vector<string> bonus_features);
	~DVD();

	// Methods
	virtual void print() const;

	// Getters and setters for member attributes
	vector<string> get_additional_languages() const;
	void set_additional_languages(const vector<string>& value);

	vector<string> get_additional_subtitles() const;
	void set_additional_subtitles(const vector<string>& value);

	vector<string> get_bonus_features() const;
	void set_bonus_features(const vector<string>& value);
protected:
	vector<string> additional_languages;
	vector<string> additional_subtitles;
	vector<string> bonus_features;
};