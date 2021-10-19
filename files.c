#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//function prototypes
int readfile();
int diffreadfile();
int writefile();


// main 

int main(){
    writefile();
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
    file = fopen("datascience.py", "r");

    if (file == NULL){
        perror("Can't open file");
        exit(-1);
    }
    if (fgets(buff, 60, file) != NULL) // it will stop reading when it hits a newline or input feed.
        printf("%s", buff);
    if (fgets(buff, 60, file) != NULL) // will print the next line.
        printf("%s", buff);
    rewind(file); // rewinds the pointer to the beginning of the file.
    if (fgets(buff, 60, file) != NULL)
        printf("%s", buff);

    printf("\n\n");
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

