// This free software is licensed under GPL version 3 without any implied or
// explicit warranties. This copyright notice must be included in all
// non-machine-executable copies or derivative works of this software.
#ifndef TOMLPROCESSOR_HPP
#define TOMLPROCESSOR_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace toml {

    class TomlProcessor {
public:
    TomlProcessor();
    ~TomlProcessor();

    bool parse(string filePath);
    bool write(string filePath);

private:
    void printy();
    void removeFluff(string &s);

    // No copy constructor or assignment operator
    TomlProcessor(const TomlProcessor &) = delete;
    TomlProcessor& operator=(const TomlProcessor &) = delete;

private:
    vector<string> m_data;
    // Variables for file parsing
    const string m_comments = "#";
    const string m_whiteSpaces = "\n\t ";
};

} // End of namespace toml

#endif // TOMLPROCESSOR_HPP
