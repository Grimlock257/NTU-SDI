#include <iostream>

#include "Packaging.h"

using namespace std;

// Constructor & deconstructors
Packaging::Packaging(PackagingMaterial packaging_material, float width, float height, float depth) : packaging_material(packaging_material), width(width), height(height), depth(depth) {
}

Packaging::~Packaging() {
}

// Methods
void Packaging::print() const {
	cout << "Width: " << this->width
		<< "Height: " << this->height
		<< "Depth: " << this->depth
		<< endl;
}

// Getters and setters for member attributes
float Packaging::get_width() const {
	return this->width;
}

void Packaging::set_width(const float & value) {
	this->width = value;
}

float Packaging::get_height() const {
	return this->height;
}

void Packaging::set_height(const float & value) {
	this->height = value;
}

float Packaging::get_depth() const {
	return this->depth;
}

void Packaging::set_depth(const float & value) {
	this->depth = value;
}
