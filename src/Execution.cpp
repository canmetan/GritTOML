#include <iostream>
#include <vector>
#include <string>

#include "toml/TomlProcessor.hpp"

using namespace std;

int main() {
    const string path = "example.toml";

    TomlProcessor processor;
    if(processor.parse(path))
        cout << "===> Successful Execution." << endl;

//    processor.write(path);
//    getchar();
    return 0;
}
