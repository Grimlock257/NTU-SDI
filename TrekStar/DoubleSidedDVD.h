#pragma once

#include <vector>

#include "DVD.h"

class DoubleSidedDVD : public DVD {
public:
	// Constructor & deconstructor
	DoubleSidedDVD(unsigned int id, string title, string video_format, string audio_format, string run_time, string language, string retail_price, string subtitles, string frame_aspect, string packaging_material, vector<string> additional_languages, vector<string> additional_subtitles, vector<string> bonus_features, string side_a_content, string side_b_content);
	~DoubleSidedDVD();

	// Methods
	virtual void print() const;
	virtual string get_savable();

	// Getters and setters for member attributes
	string get_side_a() const;
	void set_side_a(const string& value);

	string get_side_b() const;
	void set_side_b(const string& value);

private:
	string side_a_content;
	string side_b_content;
};