#include "TomlProcessor.hpp"

#include <fstream>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;


TomlProcessor::TomlProcessor() {
}

TomlProcessor::~TomlProcessor() {
}

bool TomlProcessor::parse(string filePath) {
    ifstream file (filePath, ifstream::in);
    string line;

    if (file.fail())
        return false;

    while (getline (file,line)) {
        clean(line);
        if(line != "")
            m_data.push_back(line);
    }
    printy();
    file.close();
    return true;
}

bool TomlProcessor::write(string filePath) {
    ofstream file(filePath, ofstream::app);
    if(file.is_open()) {
//        file << "Something something";
        file.close();
        return true;
    }
    return false;
}

void TomlProcessor::printy() {
    for(auto i = m_data.begin(); i != m_data.end(); ++i) {
        cout << *i << "\n";
    }
}

// Removes white spaces and comments from the string
void TomlProcessor::clean(string &s) {
    std::size_t first, last;

    // First, only retrieve the stuff before the comment charaters
    s = s.substr(0, s.find_first_of(m_comments));

    // Then remove the white spaces around the line.
    first = s.find_first_not_of(m_whiteSpaces);

    if (first == std::string::npos) // empty string
        s = "";
    else {
        last = s.find_last_not_of(m_whiteSpaces);
        s    = s.substr(first, last - first + 1);
    }
}
