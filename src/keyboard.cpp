#include "keyboard.h"
#include <list>
#include <string>
#include <ncurses.h>

using namespace std;

void get_panel_input(unsigned short &key, list<string> &dirs_and_files, string &current_dir, unsigned short &current_file) {
    switch (key) {
        case KEY_ENTER:
            break;
    }
}
void get_editor_input(unsigned short &key) {

}
void get_command_input(unsigned short &key, list<string> &command_history, string &command_line, unsigned char &current_command) {

}
