#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("\n");
    printf("------------------------------------------------------------------\n");
    printf("|      S I M P L E  F I L E  H A N D L I N G  E X A M P L E      |\n");
    printf("------------------------------------------------------------------\n");
    printf("|  1) Write New File                                             |\n");
    printf("|  2) Open File                                                  |\n");
    printf("|  0) Exit                                                       |\n");
    int choice;
    printf("------------------------------------------------------------------\n");

    printf("|  Enter your choice -> ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            makeFile();
            break;
        case 2 :
            readFile();
            break;
        case 0 :
            exit(0);
        default:
            main();
    }
    return 0;
}

int makeFile() {
    char fileName[20];
    char content[500];
    FILE *fp;
    printf("------------------------------------------------------------------\n");
    printf("|  Enter file name -> ");
    gets(fileName);
    scanf("%s", fileName);

    while (strlen(fileName) > 50) {
        printf("|  Maximum file name size 20 Enter file name -> ");
        gets(fileName);
        scanf("%s", fileName);
    }

    int file_name = strcat(fileName, ".txt");
    fp = fopen(file_name, "w");

    gets(content);

    while (strlen(content)<=0 || strlen(content)>=501){
        printf("|  Enter Content maximum size 500 letters -> ");
        gets(content);
    }

    fputs(content, fp);
    fputs("\n", fp) ;
    fclose(fp);
    main();
    return 0;
}

int readFile(){
    FILE *fp;
    char fileData[600];
    char fileName[20];
    printf("|  Enter file name  you wish to open -> ");
    gets(fileName);
    scanf("%s", fileName);
    int file_name = strcat(fileName, ".txt");


    if ( fp == NULL )
    {
        printf( "Wrong file name" ) ;
        printf("|  Enter file name  you wish to open -> ");
        gets(fileName);
        scanf("%s", fileName);
        int file_name = strcat(fileName, ".txt");
        return 1;
    }

    fp = fopen( file_name, "r" ) ;

    printf( "\n--------------------------------------------------------\n" ) ;
    printf(file_name);
    printf( "\n--------------------------------------------------------\n" ) ;
    while( fgets ( fileData, 600, fp ) != NULL )
        printf( "%s" , fileData ) ;
    fclose(fp) ;
    return 0;
}