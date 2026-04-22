#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    
    printf("I love Kanye\n");
    
    FILE *file = fopen("kanye_data.txt", "r");
    if (!file) {
        printf("Error: Run the yt-dlp harvest command first!\n");
        //yt-dlp --flat-playlist --print "%(title)s|%(id)s" "URL" > kanye_data.txt
        return 1;
    }

    char data[500][200];
    int count = 0;

    while (fgets(data[count], sizeof(data[count]), file) && count < 500) {
        data[count][strcspn(data[count], "\n")] = 0;
        count++;
    }
    fclose(file);

    srand(time(NULL));
    while(1){
    int random_index = rand() % count;
    char line[200];
    strcpy(line, data[random_index]);
    char *title = strtok(line, "|");
    char *id = strtok(NULL, "|");
    char command[100];
    system("clear");
    sprintf(command, "mpv https://youtu.be/%s", id);
    printf("Ye Random: Playing %s track %d of %d...\n", title,random_index + 1, count);

    int status = system(command);
        if (status != 0) {
            break;
        }
    }

    return 0;
}
