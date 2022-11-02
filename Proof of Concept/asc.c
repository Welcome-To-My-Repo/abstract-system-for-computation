/*
This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public Licens as published by the 
Free Software Foundation, either version 2 of the License, or (at your 
option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for 
more details.

You should have recived a copy of the GNU General Public License along with 
this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <stdio.h>

typedef unsigned long long int Value;
Value *Buffer;
Value Length = 0, Chars = 0;
void Abort () {exit("There was a problem!");}
void Read ();

int main ()
{
	Buffer = malloc(1024);
	Length = 1024;
	Value c = 0, c_1 = 0;
	for (;;)
	{
		c = fgetc(stdin);
		Chars ++;
		if (Chars >= Length)
		{
			Buffer = realloc(Buffer, Length * 2);
			Length = Length * 2;
		}
		Buffer[Chars] = c;
		if (c == '\n' && c_1 == '\n') break;
		c_1 = c;
	}
	for (Value i = 0; i < Chars; i ++)
	{
		printf("%c", Buffer[i]);
	}
	return 0;
}

void Read ()
{
	if (Length == 0) {Buffer = malloc(1024); Length = 1024;}
	for (;;)
	{
		Value c = 0, c_1 = 0;
		for (;;)
		{
			c = fgetc(stdin);
			
		}
	}
}