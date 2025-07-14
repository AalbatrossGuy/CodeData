#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_io();

int main(int argc, char *argv[]){
  // A goto statement causes program control to jump to a particular statement unconditionally upon execution.
  // A label is placed directly before the statement to which the branch is to be made and must appear in the same function as the goto.
  // Syntax: label: <statement> ............... goto label;
  // Label can be located anywhere IN the function. Before or after goto.
  // getc reads a single character from a FILE pointer or from an input stream like stdin. It takes a FILE pointer as argument but since stdin also acts as a file, it works.
  // getc returns an integer value which can be converted easily into a character.
  char c = (char) getc(stdin);
  printf("The character read from stdin is: %c \n", c);

  // getchar() works similarly to getc() but it reads only from stdin.
  printf("%c \n", getchar()); // It works the same way as above

  // putc() writes a single character to a file or stdout.
  // putc(character to be written, file stream). File stream could either be a FILE pointer or stdout.
  char ch = 'F';
  putc(ch, stdout);
  printf("\n");
  // Similar to getchar(), putchar() writes directly in stdout without needing to use it as a parameter.
  char string[] = "It's a string, \nDelimiter";
  int i = 0;
  while (string[i] != '\0') {
    if (string[i] != '\n') {
      putchar(string[i]);
    }
    ++i;
  }
  printf("\n");
  string_io();
  return 0;
}

void string_io() {
  // fgets() is used to read an entire line from a file or stdin
  // It takes a character array pointer as first argument where the input string is to be stored.
  // accepts two additional arguments, number of characters to read and input stream.
  // char *fgets(char *buffer, int n, FILE *stream);
  // Not recommended for performance reasons and it's DEPRECATED.
  char buffer[100];
  int ch = '\0';
  char *pChar = NULL;
  if (fgets(buffer, sizeof(buffer), stdin)) {
    pChar = strchr(buffer, '\n');
    if (pChar) {
      *pChar = '\0'; // Basically, if new line is observed, set a null terminator if it's not set, to indicate end of string input.
    }
  }



  // The latest function for reading a line in C is getline().
  // getline(char **buffer, size_t *size, FILE *stream); The first parameter is a pointer to a block allocated with malloc or calloc (type char**)
  // This pointer type (char **) dynamically allocates space, hence there won't be a shortage of space for the buffer while taking string input.
  // It returns the line read by getline(). The second parameter is a pointer to a variable of size_t. It specifies the size in bytes of the block of memory pointed by the first parameter.
  // It is the address of the variable that holds the size of the buffer. The third parameter is just the input stream, can be FILE pointer or stdin.
  // getline() returns -1 if EOF is reached without reading any bytes. Else, returns the no. of characters it read upto & including \n. NOT the final \0.

  char *input_buffer = NULL; // The string is stored here.
  size_t input_length = 32;
  // Instead of using a character pointer, a character array can also be used which has a pointer. Doing that negates the need for allocating memory dynamically.

  input_buffer = (char *) malloc(input_length * sizeof(char));

  if (input_buffer == NULL) {
    exit(-1);
  }

  printf("Enter string: ");
  size_t characters = getline(&input_buffer, &input_length, stdin);
  printf("%zu characters were read.\n", characters);
  printf("The string was: %s", buffer);
}
