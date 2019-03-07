#include <iostream>

#include "Material.h"

// Constructor & deconstructor
Material::Material(unsigned int id, string title, string video_format, string audio_format, string run_time, string language, string retail_price, string subtitles, string frame_aspect, PackagingMaterial packaging_material)
	: id(id), title(title), video_format(video_format), audio_format(audio_format), run_time(run_time), language(language), retail_price(retail_price), subtitles(subtitles), frame_aspect(frame_aspect), packaging_material(packaging_material) {
}

Material::~Material() {
}

// Methods
void Material::print() const {
	cout << "ID: " << this->id << endl
		<< "Title: " << this->title << endl
		<< "Video Format: " << this->video_format << endl
		<< "Audio Format: " << this->audio_format << endl
		<< "Run Time: " << this->run_time << endl
		<< "Default Language: " << this->language << endl
		<< "Retail Price: " << this->retail_price << endl
		<< "Default Subtitles: " << this->subtitles << endl
		<< "Aspect Ratio: " << this->frame_aspect << endl
		<< "Packaging Material: " << this->packaging_material << endl;
}

// Getters and setters for member attributes
unsigned int Material::get_id() const {
	return this->id;
}

string Material::get_title() const {
	return this->title;
}

void Material::set_title(const string& value) {
	this->title = value;
}

string Material::get_video_format() const {
	return this->video_format;
}

void Material::set_video_format(const string& value) {
	this->video_format = value;
}

string Material::get_audio_format() const {
	return this->audio_format;
}

void Material::set_audio_format(const string& value) {
	this->audio_format = value;
}

string Material::get_run_time() const {
	return this->run_time;
}

void Material::set_run_time(const string& value) {
	this->run_time = value;
}

string Material::get_language() const {
	return this->language;
}

void Material::set_language(const string& value) {
	this->language = value;
}

string Material::get_retail_price() const {
	return this->retail_price;
}

void Material::set_retail_price(const string& value) {
	this->retail_price = value;
}

string Material::get_subtitles() const {
	return this->subtitles;
}

void Material::set_subtitles(const string& value) {
	this->subtitles = value;
}

string Material::get_frame_aspect() const {
	return this->frame_aspect;
}

void Material::set_frame_aspect(const string& value) {
	this->frame_aspect = value;
}

PackagingMaterial Material::get_packaging_material() const {
	return this->packaging_material;
}

void Material::set_packaging_material(const PackagingMaterial& value) {
	this->packaging_material = value;
}