#define NUMBER '0'
#define TOKEN '1' /* signal that a token (word) was found */

void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
void clear(void);
void handleVar(char []);
