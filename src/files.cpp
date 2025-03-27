#include <fstream>
#include <iterator>
#include <list>
#include <string>
#include <tuple>

using namespace std;

class File_Object {
    public:
        //      Attributes
        // File
        string file_name;
        list<string> content_buffer;
        fstream file_content;
        list<tuple<unsigned short, string>> changes;

        // Cursor
        unsigned short current_line;
        unsigned char curs_y, curs_x;

        //      Functions
        void save();
        void save_as();
        void load_buffer();
};

void File_Object::save() {}
void File_Object::save_as() {}
void File_Object::load_buffer() {
    file_content.seekp(0, ios::beg); // Set file pointer to 0
    string line_content;
    unsigned short line_counter;
    while(getline(file_content, line_content)) {}
}

void add_file(list<File_Object*> &file_list, string &file_path) {
    // Create new file
    File_Object *new_file = new File_Object;

    //      Setting values
    // Setting file name
    if (file_path.empty()) {
        new_file->file_name = "New File";
    }
    else {
        size_t pos = file_path.find_last_of('/'); // Get last / in file path
        if (pos != string::npos) {
            new_file->file_name = file_path.substr(pos + 1);
        }
        else {
            new_file->file_name = file_path;
        }
    }
    // Opening file
    new_file->file_content.open(file_path);

    // Setting cursor position
    new_file->curs_y = 0;
    new_file->curs_x = 0;
    new_file->current_line = 0;

    // Add new file
    file_list.push_back(new_file);
}

void remove_file(list<File_Object> &file_list, unsigned char &index) {
    auto remove = file_list.begin();
    advance(remove, index);
    remove->file_content.close(); // Close file
    file_list.erase(remove); // Delete from file list
}
