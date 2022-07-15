#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

struct termios pre, n;

typedef unsigned int Char;

Char *Buffer;
unsigned long long int Size = 0;
unsigned long long int Length = 0;

const int SEG = 512;
int input = STDIN_FILENO, output = STDOUT_FILENO;

Char Symbol();
Char Input();

void Reset() {tcsetattr(input, TCSAFLUSH, &pre);}

void Append(Char c);
void Delete(long long unsigned int a, long long unsigned int b);

enum {Plain, Script, Frak, Double, Math, Picker} Mode = Plain;



int main ()
{
	atexit(Reset);
	tcgetattr(input, &pre);
	
	n = pre;
	n.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	n.c_oflag &= ~(OPOST);
	n.c_cflag |= (CS8);
	n.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	n.c_cc[VMIN] = 0;
	n.c_cc[VTIME]= 1;

	tcsetattr(input, TCSAFLUSH, &n);

	Buffer = malloc(SEG);

	Char c;
	write (output, "P>> ", 4);
	while(1) {
		c = 0;
		if (read(input, &c, 1) > 0)
		{
			if (c >= ' ')
				write(output, &c, 1);
			if (c == 10)
			{}
			else if (c == 9)
			{}
			else if (c == 12)
			{}
			else if (c == 4 || c == 17)
			{
				write(output, "Ctrl+D", 6);
				break;
			}
		}
	}
	write(output, "\n", 1);
	exit(0);
}

void Append(Char c)
{
	if (Size == 0 || (Length + 1) > Size)
	{
		Buffer = malloc(SEG);
		Size += SEG;
	}
	Buffer[Length] = c;
	Length ++;
}
void Delete(long long unsigned int a, long long unsigned int b)
{
	if (a >= b) return;
	if (b < Length)
		while (b < Length)
		{
			Buffer[a] = Buffer[b];
			a++; b++;
		}
	
	Length -= b - a;
	if ((Size - Length) > SEG)
	{
		Char *n = malloc ((Length / SEG) + SEG);
		for (int i = 0; i < Length; i ++)
		{
			n[i] = Buffer[i];
		}
		free(Buffer);
		Buffer = n;
	}
}