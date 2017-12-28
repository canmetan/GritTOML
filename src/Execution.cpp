// This free software is licensed under GPL version 3 without any implied or
// explicit warranties. This copyright notice must be included in all
// non-machine-executable copies or derivative works of this software.
#include <iostream>
#include <vector>
#include <string>

#include "toml/TomlProcessor.hpp"

using namespace std;

int main() {
    const string path = "example.toml";

    toml::TomlProcessor processor;
    if(processor.parse(path))
        cout << "Successful Execution." << endl;

//    processor.write(path);
//    getchar();
    return 0;
}
