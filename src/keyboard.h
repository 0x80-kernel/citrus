#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <string>
#include <list>

using namespace std;

void get_panel_input(unsigned short &key, list<string> &dirs_and_files, string &current_dir, unsigned short &current_file);
void get_editor_input(unsigned short &key);
void get_command_input(unsigned short &key, list<string> &command_history, string &command_line, unsigned char &current_command);

#endif
