// This free software is licensed under GPL version 3 without any implied or
// explicit warranties. This copyright notice must be included in all
// non-machine-executable copies or derivative works of this software.
#include "TomlProcessor.hpp"

#include <fstream>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

namespace toml {

TomlProcessor::TomlProcessor() {
}

TomlProcessor::~TomlProcessor() {
}

bool TomlProcessor::parse(string filePath) {
    ifstream file(filePath, ifstream::in);
    string line;

    if(file.fail())
        return false;

    while(getline(file, line)) {
        removeFluff(line);

        if(line != "") {
            cout << line << endl;
            vector<string> vecy;
            split(line, vecy);
            printy(vecy);
        }
    }
    file.close();
    return true;
}

bool TomlProcessor::write(string filePath) {
    ofstream file(filePath, ofstream::trunc);

    if(file.is_open()) {
        file << "Something something";
        file.close();
        return true;
    }

    return false;
}

void TomlProcessor::printy(const vector<string> &vec) const {
    for(auto i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << "\n";
    }
}

void TomlProcessor::split(const string &s, vector<string> &output) {
    size_t endIndex = s.find_first_of('=');

    output.push_back(s.substr(0, endIndex));
    output.push_back(s.substr(s.find_first_not_of(m_afterEquals, endIndex),
                              s.length()));
}

// Removes the surrounding white spaces and comments from the string
void TomlProcessor::removeFluff(string &s) {
    size_t first, last;
    int a = 9;

    // First, only retrieve the stuff before the comment charaters
    s = s.substr(0, s.find_first_of(m_comments));

    // Then remove the white spaces around the line.
    first = s.find_first_not_of(m_whiteSpaces);

    if(first == string::npos)    // empty string
        s = "";
    else {
        last = s.find_last_not_of(m_whiteSpaces);
        s    = s.substr(first, last - first + 1);
        a = 10;
    }
}

} // End of namespace toml2
