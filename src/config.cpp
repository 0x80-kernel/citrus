#include "config.h"
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <string>

using namespace std;

//      Private
inline void create_config(string &home) {
    // Create config directory
    string aux = home + "/.config/citrus";
    filesystem::create_directory(aux);

    // Create config file
    aux = home + "/.config/citrus/citrus.conf";
    ofstream config_file(aux);

    // Writing defalt config
    config_file << DEFAULT_CONFIG;

    // Close
    config_file.close();
}

//      Public
void load_config() {
    string home = getenv("HOME"); // Get user home
    string config_path = home + "/.config/citrus/citrus.conf";

    // Create config if not exists
    if (!filesystem::exists(config_path)) {
        create_config(home);
    }

    // Read config file
    ifstream config_file(config_path);
    string line_content;

    while (getline(config_file, line_content)) {

    }

    // Close
    config_file.close();
}
