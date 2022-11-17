/*
 * ASC Portable Bootstrap Interpreter
*/

#include <stdio.h>
#include <stdlib.h>
typedef long long unsigned int Value;
int main () {
Value *Buffer;
Value BufferLength = 0;
Value BufferSize = 512;
Value c, c1 = '\0';
Buffer = malloc(BufferSize);

OuterLoop:

FillBuffer:
	c = getchar();
	if (c == '\n' && c1 == '\n') goto Compute;
	if (! BufferLength < BufferSize) {
		if (BufferSize < BufferSize * 2) BufferSize = BufferSize * 2;
		else {printf("The input is too large!\n"); goto Exit;}
		Value *tmp = malloc(BufferSize);
		for (Value i = 0; i < BufferLength; i ++)
			tmp[i] = Buffer[i];
		free(Buffer);
		Buffer = tmp;
	}
	Buffer[BufferLength] = c;
	BufferLength ++;
	c1 = c;
	goto FillBuffer;
Read:
	Value Pos = 0; 
	
Compute:	


Exit: return 0;
}