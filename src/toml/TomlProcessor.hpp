#ifndef TOMLPROCESSOR_HPP
#define TOMLPROCESSOR_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;

class TomlProcessor {
public:
    TomlProcessor();
    ~TomlProcessor();

    bool parse(string filePath);
    bool write(string filePath);

private:
    void printy();
    void clean(string &s);

    // No copy constructor or assignment operator
    TomlProcessor(const TomlProcessor &) = delete;
    TomlProcessor& operator=(const TomlProcessor &) = delete;

private:
    vector<string> m_data;
    // Variables for file parsing
    const string m_comments = "#";
    const string m_whiteSpaces = "\n\t ";
};

#endif // TOMLPROCESSOR_HPP
