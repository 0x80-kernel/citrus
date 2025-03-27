#ifndef TERMINAL_UI
#define TERMINAL_UI

//      Color screens
#define PANEL_COLORS 0
#define EDITOR_COLORS 1
#define STATUS_COLORS 2
#define COMMAND_COLORS 3

void setup();
void draw_tui(unsigned short &cols, unsigned short &rows, unsigned short &key);
void close();

#endif
