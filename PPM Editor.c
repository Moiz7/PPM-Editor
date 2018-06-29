#include <stdio.h>
#include <strings.h>
#include <stdlib.h> // For exit()

void grayscale(int lines,int elements_in_line[], int line[][100]){
    int i,j;
    for (i=3; i<lines; i++) {           //  convert to
        for (j=0; j<elements_in_line[i]; j+=3){
            int gray_average=(line[i][j]+line[i][j+1]+line[i][j+2])/3;
            line[i][j+2]=line[i][j+1]=line[i][j]=gray_average;
        }
    }
}
void negate_red(int lines,int elements_in_line[], int line[][100]){
    int i,j;
    for (i=3; i<lines; i++) {           //  negate red
        for (j=0; j<elements_in_line[i]; j+=3){
            line[i][j]=255-line[i][j];
        }
    }
}
void negate_green(int lines,int elements_in_line[], int line[][100]){
    int i,j;
    for (i=3; i<lines; i++) {           //  negate red
        for (j=1; j<elements_in_line[i]; j+=3){
            line[i][j]=255-line[i][j];
        }
    }
}
void negate_blue(int lines,int elements_in_line[], int line[][100]){
    int i,j;
    for (i=3; i<lines; i++) {           //  negate red
        for (j=2; j<elements_in_line[i]; j+=3){
            line[i][j]=255-line[i][j];
        }
    }
}
void flatten_red(int lines,int elements_in_line[], int line[][100]){
    int i,j;
    for (i=3; i<lines; i++) {           //  negate red
        for (j=0; j<elements_in_line[i]; j+=3){
            line[i][j]=0;
        }
    }
}
void flatten_green(int lines,int elements_in_line[], int line[][100]){
    int i,j;
    for (i=3; i<lines; i++) {           //  negate red
        for (j=1; j<elements_in_line[i]; j+=3){
            line[i][j]=0;
        }
    }
}
void flatten_blue(int lines,int elements_in_line[], int line[][100]){
    int i,j;
    for (i=3; i<lines; i++) {           //  negate red
        for (j=2; j<elements_in_line[i]; j+=3){
            line[i][j]=0;
        }
    }
}
void swap(char a[], int b, int c) {
    char temp = a[b];
    a[b] = a[c];
    a[b] = temp;
}
int main()
{
    FILE *fptr1, *fptr2, *fptr3;
    char filename[100], c;

    printf("Enter the filename to open for reading \n");
    scanf("%s", &filename);

    // Open one file for reading
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    printf("Enter the filename to open for writing \n");
    scanf("%s", &filename);

    // Open another file for writing
    fptr2 = fopen(filename, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr1);
    int i=0,j=0;
    char a[200][200];
    while (c != EOF)
    {
        if (c!='\n') {
            a[i][j]=c;
            j++;

        } else {
            a[i][j]=0;
            i++;
            j=0;
        }
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    int lines = i;
    printf("\n\n%d\n\n",lines);
    int horizontal, vertical;
    int d[100];
    sscanf(a[1], "%d %d", &horizontal, &vertical);

    printf("\n%d    %d\n", horizontal, vertical);
    int horizontal2=horizontal;
    int vertical2=vertical;

    for (i=0; i<lines; i++) {
        printf("%s\n\n", a[i]);
    }
        int line[100][100];

    int elements_in_line[3000];
    for (i=3; i<lines; i++) {
        char *pch;
        pch = strtok (a[i]," ");
        j=0;
        while (pch != NULL)
        {
            printf ("%s ",pch);
            line[i][j]=atoi(pch);
            printf(" %d\n",line[i][j]);
            pch = strtok (NULL, " ");
            j++;
        }
        elements_in_line[i]=j;
        printf("\nElements in line are %d\n", elements_in_line[3000]);
        int location=j;
        j=0;
        printf("\n");
        while (j<location) {
            printf("%d  ", line[i][j]);
            j++;
        }
    }

    printf("\nContents copied to %s", filename);

    printf("\nSize is %d\n", elements_in_line[3000]);
    char new_line='\n';
    printf("Enter the filename to open for writing \n");
    scanf("%s", filename);

    printf("What do you want to do?\n");
    printf("\t[1] convert to greyscale\t[2] flip horizontally\n");
    printf("\t[3] negative of red\t[4] negative of green\t[5] negative of blue\n");
    printf("\t[6] just the reds\t[7] just the greens\t[8] just the blues\n");
    printf("\nEnter your choice:");
    int choice;
    scanf("%d", &choice);

    char pixels[40][40];
    int k,l;
    switch(choice) {
        case 1:
            grayscale(lines, elements_in_line, line);
            break;
        case 2:

            for (i=3,k=0,l=0; i<lines; i++) {           //  negate red
                for (j=0; j<elements_in_line[i]; j+=3){
                    sprintf(pixels[k], "%d %d %d", line[i][j], line[i][j+1], line[i][j+2]);
                    printf("Pixels[%d][%d] = %s\n", k,l,pixels[k]);
                    l++;
                    if (l==horizontal2) {
                        k++;
                        l=0;
                    }
                }
            }

            char temp[30];
            for (i=0, k=0; i<vertical2; i++, k+=horizontal2) {
                for (j=0; j<horizontal2; j++) {
                    swap(pixels, k, horizontal2-j);
                    k++;
                }
            }
            break;

        case 3:
            negate_red(lines, elements_in_line, line);
            break;
        case 4:
            negate_green(lines, elements_in_line, line);
            break;
        case 5:
            negate_blue(lines, elements_in_line, line);
            break;
        case 6:
            flatten_red(lines, elements_in_line, line);
            break;
        case 7:
            flatten_green(lines, elements_in_line, line);
            break;
        case 8:
            flatten_blue(lines, elements_in_line, line);
            break;
    }
    fptr3 = fopen(filename, "w+");
    fprintf(fptr3, "P3\n%s\n255\n",a[1]);
    for (i=3; i<lines; i++) {
        for (j=0; j<elements_in_line[i]; j++){
            fprintf(fptr3, "%d ", line[i][j]);
        }
        fprintf(fptr3, "%c", new_line);
    }


    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    return 0;
}
