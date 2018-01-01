// This free software is licensed under GPL version 3 without any implied or
// explicit warranties. This copyright notice must be included in all
// non-machine-executable copies or derivative works of this software.
#ifndef TOMLPROCESSOR_HPP
#define TOMLPROCESSOR_HPP

#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

namespace toml {

class TomlProcessor {

public:
    TomlProcessor();
    ~TomlProcessor();

    bool parse(string filePath);
    bool write(string filePath);

private:
    void removeFluff(string &s);
    void split(const string &s, const string &delimiter, vector<string> &output);
    void printy(const vector<string> &vec) const;

    // No copy constructor or assignment operator
    TomlProcessor(const TomlProcessor &) = delete;
    TomlProcessor& operator=(const TomlProcessor &) = delete;

private:
    unordered_map<string,string> m_data;
    // Variables for file parsing
    const string m_comments = "#";
    const string m_whiteSpaces = "\n\t ";
    const string m_afterEquals = "=" + m_whiteSpaces;
};

} // End of namespace toml

#endif // TOMLPROCESSOR_HPP
