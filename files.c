#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//function prototypes
int readfile();
int diffreadfile();
int writefile();
int CountNumberOfLines();
int ReverseText();
// main 

int main(){
    CountNumberOfLines();
    ReverseText();
    return 0;
}

int readfile(){
    FILE *pfile = NULL;
    char *fname = "Dockerfile";
    int n;
    pfile = fopen(fname, "r");

    if (pfile == NULL){
        perror("Can't open file"); // if fopen() cannot open a file it perror() will print a custom error message on the stderr
        exit(-1);
    }
    // printf("%i\n", n);
    while ((n = fgetc(pfile)) != EOF){ // reads recursively through each and every character until it hits EOF
        printf("%c", n);
    }
    fclose(pfile); // the connection between the pointer and the file is closed
    pfile = NULL; // set back to NULL for safety.
    // remove("File name") deletes a file. Do it carefully as it can damage system integrity.
}

int diffreadfile(){
    
    FILE *file = NULL;
    char buff[60];
    file = fopen("loremipsum.txt", "r");

    if (file == NULL){
        perror("Can't open file");
        exit(-1);
    }
    if (fgets(buff, 60, file) != NULL) // it will stop reading when it hits a newline or input feed.
        printf("%s\n", buff);
    int pos = ftell(file); // ftell returns the position of the pointer/cursor by values in offset of bytes. Opening a file, seeking the cursor to the end and then using ftell() will give us the size of the file in bytes.
    printf("%i\n", pos);
    printf("\n\n");

    if (fgets(buff, 60, file) != NULL) // will print the next line.
        printf("%s", buff);

    // rewind(file); // rewinds the pointer to the beginning of the file.
    
    fseek(file, 0, SEEK_END);
    int len = ftell(file);
    printf("The size of the file is %i bytes", len);
    fclose(file);
    file = NULL;
}

int writefile(){
    FILE *file = NULL;
    file = fopen("index.js", "a");
    
    if (file == NULL){
        perror("Can't open file");
        exit(-1);
    }
        
    fputc('A', file); // takes character. Can take ASCII codes too
    fputs("Hi. This is written in C", file); // example of fputs(). It writes a string in a file.
    fprintf(file,"%s %s %s %s %s %i", "Hello", "I", "Am", "Kishaloy", "Roy", 13); // writes in formatted text in a file.
    fclose(file);
    file = NULL;
}

int CountNumberOfLines(){
    FILE *pfile = NULL;
    char *fname = "keep_alive.py";
    int ch;
    int linesCount = 0;

    pfile = fopen(fname, "r");

    if (pfile == NULL){
        perror("Can't open file");
        exit(-1);
    }

    while ((ch = fgetc(pfile))!= EOF){
        if (ch == '\n')
            linesCount++;
    }

    fclose(pfile);
    pfile = NULL;
    printf("The number of lines in the file is: %i\n", ++linesCount); // it does not increment the last empty line so we have to do it manually until it hits EOF.
}

int ReverseText(){
    FILE *file = NULL;
    int count = 0;
    int i = 0;

    file = fopen("keep_alive.py", "r");
    if (file == NULL){
        perror("Cannot open file");
        exit(-1);
    }

    fseek(file, 0, SEEK_END);
    count = ftell(file);
    //printf("%i\n", count);

    while(i<count){
        i++;
        fseek(file, -i, SEEK_END); // pos is -i so that it can record data from the end to the beginning of the file.
        printf("%c", fgetc(file));
    }
    printf("\n");
    fclose(file);
}
