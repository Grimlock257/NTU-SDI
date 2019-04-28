#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// TODO: Find a better location/file to store this method as well as better file name is it remains as its own file...
ostream& operator<< (ostream& out, const vector<string>& v);

string vector_to_string(const vector<string>& input);