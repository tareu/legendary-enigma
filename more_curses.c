#include <ncurses.h>
#include <string.h>

int main()
{
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);

    while(1)
    {
        /* process input */
        char mesg[]="Just a string";
        int row, col;
        int ch; 
        ch = getch();

        /* update */
        getmaxyx(stdscr, row, col);

        mvprintw(row / 2, ((col - strlen(mesg) )/ 2), "%s", mesg);
        mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);
        if (ch == KEY_F(1)) 
        {
            printw("F1 Key pressed");
            endwin();
            return 0;
        }

        if (ch != KEY_F(1)) 
        {
            printw("The pressed key is ");
            attron(A_BOLD);
            printw("%c", ch);
            attroff(A_BOLD);
        }

        /* render */
        refresh();
    }
    endwin();

    return 0;
}
