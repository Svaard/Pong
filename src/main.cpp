#include <ncurses.h>
#include <unistd.h>
#include <locale.h>

#define DELAY 70000

int main(int argc, char *argv[]) {
    int x = 0, y = 0;
    int max_y = 0, max_x = 0;
    int next_x = 0;
    int direction = 1;
    char letter[] = "▒";
    //char16_t word = u'▒';
    setlocale(LC_CTYPE,"");
    
    initscr(); // Initializes global variable stdscr
    noecho();
    curs_set(FALSE);
    
    while(1){
        getmaxyx(stdscr, max_y, max_x);
        
        clear(); //Clear the screen of all previously printed characters
        mvprintw(y, x, letter); //Print our "ball" at the current x,y position
        refresh();

        usleep(DELAY); //Shorter delay between movements
        next_x = x + direction;
        if(next_x >= max_x || next_x < 0){
            direction *= -1;
        }
        else{
            x += direction;
        }
    }

    endwin(); // Restore normal terminal behavior
}
