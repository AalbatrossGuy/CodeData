#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_i();
void string_o();
void format_string();

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
  string_i();
  string_o();
  format_string();
  return 0;
}

void string_i() {
  // fgets() is used to read an entire line from a file or stdin
  // It takes a character array pointer as first argument where the input string is to be stored.
  // accepts two additional arguments, number of characters to read and input stream.
  // char *fgets(char *buffer, int n, FILE *stream);
  // Not recommended for performance reasons and it's DEPRECATED.
  // char buffer[100];
  // int ch = '\0';
  // char *pChar = NULL;
  // if (fgets(buffer, sizeof(buffer), stdin)) {
  //   pChar = strchr(buffer, '\n');
  //   if (pChar) {
  //     *pChar = '\0'; // Basically, if new line is observed, set a null terminator if it's not set, to indicate end of string input.
  //   }
  // }

  printf("\n");

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
  printf("The string was: %s\n", input_buffer);
}


void string_o() {
  // puts() is used to write a line to the output screen, i.e., stdout.
  // Simpler than printf since \n is not needed to be included.
  // printf() interprets the argument as a formatting string. The result will often be the same except for the added \n. If the string
  // doesn't contain any control characters (%).
  // puts() is simple and safe but not very flexible as it does not allow the formatting of the string.
  // puts(const char * string);
  char string[40];
  strcpy(string, "stdout output!");
  puts(string);

  // fputs() writes a line of character is the same as puts() except it accepts a second argument for streaming. It writes to a file.
}

void format_string() {
  // sprintf() is used to write formatted output to a string. It stands for "string print formatted".
  // several data variables can be combined in a character array when using sprintf()
  // int sprintf(char *string, const char *format, ...);
  // It returns the number of characters stored in the string, excluding the terminating null
  char test[100];
  int integer = 20;
  char character = 'H';
  float floating_value = 3.9;
  char buffer[50] = "YourMom is 69";
  char name[10];
  char helping_verb[5];
  int age = 0;
  sprintf(test, "%d is the integer %c is the character and %f is the floating point value\n", integer, character, floating_value);
  puts(test); // Output the string in stdout
  // sprintf() is unsafe as it doesn't check the length of the destination buffer, thus prone to memory overflow.

  // fprintf() does the same thing as printf() except, on a file. fprintf() is generally used when storing stderr into a file.
  // fscanf() does the same thing as scanf() except, on a file. Used to read formatted input from a file.

  // sscanf() reads formatted data from a string rather than stdin or keyboard.
  // int sscanf(const char *str, const char * control_string[arg_1, arg_2, ...]);
  // Example:
  sscanf(buffer, "%s %s %d", name, helping_verb, &age); // 1st argument is a pointer to the string from where we want to read the data.
  // The rest of the arguments of sscanf() is same as scanf(). returns -1 if error is encountered.
  printf("The name extracted from the string is: %s\n", name);
  printf("The age extracted from the string is: %d\n", age);

  // fflush() is used to flush a file or a buffer. It causes any unwritten data in the output buffer to be sent to the output file.
  // The process of writing any unwritten data to the output file is called flushing.
  fflush(buffer);
  // buffer is a temporary variable/pointer which loads/points to the data. If the file is a null pointer, all output buffers are flushed.
  // It can be used with an update stream (read/write modes) given that the most recent operation using the stream was not input.
}