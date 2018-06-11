#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>
#include <fcntl.h>
#include <curses.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>


/*
void deal(int s)
{
	printf("alarm.\n");
}

int main()
{
	struct itimerval v={0};
	signal(SIGALRM, deal);
	//alarm(5);
	v.it_value.tv_sec = 0;
	v.it_value.tv_usec = 1;
	v.it_interval.tv_sec = 1;
	setitimer(ITIMER_REAL, &v, 0);
	while(1)
	{
		sleep(1);
	}
	return 0;
}
*/

WINDOW *wtime, *wnumb;
int num;
int i;
void showtime(int s)
{
	time_t tt;
	struct tm *t;
	if(s == SIGALRM)
	{
		tt = time(0);
		t = localtime(&tt);
		mvwprintw(wtime,1,1,"%02d:%02d:%02d",
			t->tm_hour,t->tm_min,t->tm_sec);
		refresh();
		wrefresh(wtime);
		wrefresh(wnumb);
	}
}

int main()
{
	struct itimerval v={0};
	initscr();
	curs_set(0);
	signal(SIGALRM, showtime);
	v.it_value.tv_sec = 0;
	v.it_value.tv_usec = 1;
	v.it_interval.tv_sec = 1;
	
	wnumb = derwin(stdscr,3,11,(LINES-3)/2,(COLS-11)/2);
	wtime = derwin(stdscr,3,10,0,COLS-10);
	box(wnumb, 0, 0);
	box(wtime, 0, 0);
	setitimer(ITIMER_REAL, &v, 0);

	refresh();
	wrefresh(wtime);
	wrefresh(wnumb);
	while (1)
	{
		num = 0;
		
		for(i = 0;i<7;i++)
		{
			num = num*10+ rand()%10;
		}
		mvwprintw(wnumb,1,2,"%07d",num);
		refresh();
		wrefresh(wnumb);
		wrefresh(wtime);
		usleep(100000);
	}
	endwin();
}