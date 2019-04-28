#pragma once

#include <string>

#include "UserInput.h"
#include "Util.h"

using namespace std;

class Material {
public:
	// Constructor & deconstructor
	Material();
	Material(unsigned int id, unsigned int project_id, string title, string video_format, string audio_format, string run_time, string language, string retail_price, string subtitles, string frame_aspect, string packaging_material);
	~Material();

	// Getters and setters for member attributes
	unsigned int get_id() const;
	unsigned int get_project_id() const;

	string get_title() const;
	void set_title(const string& value);

	string get_video_format() const;
	void set_video_format(const string& value);

	string get_audio_format() const;
	void set_audio_format(const string& value);

	string get_run_time() const;
	void set_run_time(const string& value);

	string get_language() const;
	void set_language(const string& value);

	string get_retail_price() const;
	void set_retail_price(const string& value);

	string get_subtitles() const;
	void set_subtitles(const string& value);

	string get_frame_aspect() const;
	void set_frame_aspect(const string& value);

	string get_packaging_material() const;
	void set_packaging_material(const string& value);

	// Methods
	virtual void print() const = 0;
	virtual string get_savable() = 0;

protected:
	// General material information
	unsigned int id;
	unsigned int project_id;
	string title;
	string video_format;
	string audio_format;
	string run_time;
	string language;
	string retail_price;
	string subtitles;
	string frame_aspect;
	string packaging_material;
	// PackagingMaterial packaging_material;
};