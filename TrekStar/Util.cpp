#include "Util.h"

// TODO: Find a better location/file to store this method as well as better file name is it remains as its own file...
ostream& operator<< (ostream& out, const vector<string>& v) {
	if (!v.empty()) {
		for (size_t i = 0; i < v.size(); i++) {
			cout << v[i] << ", ";
		}
	}
	return out;
}