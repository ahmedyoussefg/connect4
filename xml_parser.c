#include "output.h"

int isFileCorrupt(configurations * myconfig, FILE * config_file, int *counter)
{
    char xml_line[514];
    char xml_content[514]; // max xml file characters = 512
    int j = 0;
    int open_symbol_counter = 0; // counting '<'
    int close_symbol_counter = 0; // counting '>'
    int slash_counter = 0; // counting '/'
    while(fgets(xml_line, 512, config_file) != NULL)
    {
        for (int i = 0; i < strlen(xml_line) && (xml_line[i] != '\n' || xml_line[i] != '\0'); i++)
        {
            if (isspace(xml_line[i]))
            {
                continue;
            }
            xml_content[j] = tolower(xml_line[i]);
            if (xml_content[j] == '/')
            {
                slash_counter++;
            }
            else if (xml_content[j] == '<')
            {
                open_symbol_counter++;
            }
            else if (xml_content[j] == '>')
            {
                close_symbol_counter++;
            }
            j++;
        }
    }
    if (slash_counter != 4 || open_symbol_counter != 8 || close_symbol_counter != 8)
    {
        red_color();
        printf("File Corrupted.\n");
        reset_color();
        *counter += 1;
        return 1;
    }

    char *ptr1_config; //ptr to first occurence of config (opentags)
    char *ptr2_config; // ptr to second occurence of config (closetags)

    char *ptr1_width;
    char *ptr2_width;

    char *ptr1_height;
    char *ptr2_height;

    char *ptr1_highscores;
    char *ptr2_highscores;

    ptr1_config = strstr(xml_content, "<configurations>"); // first occurence of the word 'configurations' opening tags
    ptr2_config = strstr(ptr1_config + 16, "</configurations>");    // after the first occurence of the opening tags

    ptr1_width = strstr(ptr1_config + 16, "<width>"); // after the configuration opening tags
    ptr2_width = strstr(ptr1_width + 7, "</width>"); // after the first occurence of the opening tags

    ptr1_height = strstr(ptr1_config + 16, "<height>"); // after the configuration opening tags
    ptr2_height = strstr(ptr1_height + 8, "</height>");  // after the first occurence of the opening tags

    ptr1_highscores = strstr(ptr1_config + 16, "<highscores>"); // after the configuration opening tags
    ptr2_highscores = strstr(ptr1_highscores + 12, "</highscores"); // after the first occurence of the opening tags

    if (ptr1_config == NULL || ptr1_height == NULL || ptr1_highscores == NULL || ptr1_width == NULL)
    // if any of the opening tags of configurations are not found
    {
        red_color();
        printf("File Corrupted\n");
        reset_color();
        *counter +=1;
        return 1; // Corrupted
    }
    if (*(ptr1_config + 16) != '<') // the opening tag for either, height/width/highscores
    {
        red_color();
        printf("File Corrupted\n");
        reset_color();
        *counter +=1;
        return 1;
    }
    if (ptr2_config == NULL || ptr2_height == NULL || ptr2_highscores == NULL || ptr2_width == NULL)
    // if any of the closed tags are not found
    {
        red_color();
        printf("File Corrupted\n");
        reset_color();
        *counter +=1;
        return 1;
    }
    if (ptr2_config < ptr1_height || ptr2_config < ptr2_height || ptr2_config < ptr1_width || ptr2_config < ptr2_width)
    {
        red_color();
        printf("File Corrupted\n");
        reset_color();
        *counter +=1;
        return 1;
    }
    if (ptr2_config < ptr1_highscores || ptr2_config < ptr2_highscores)
    {
        red_color();
        printf("File Corrupted\n");
        reset_color();
        *counter +=1;
        return 1;
    }
    if (ptr1_height + 8 == ptr2_height) // There is no number!
    {
        red_color();
        printf("File Corrupted\n");
        reset_color();
        *counter +=1;
        return 1;
    }
    if (ptr1_width + 7 == ptr2_width) // There is no number!
    {
        red_color();
        printf("File Corrupted\n");
        reset_color();
        *counter +=1;
        return 1;
    }
    if (ptr1_highscores + 12 == ptr2_highscores) // There is no number!
    {
        red_color();
        printf("File Corrupted\n");
        reset_color();
        *counter +=1;
        return 1;
    }

    // the part between the '>' opening tags and '</' of closing tags
    char height_as_string[ptr2_height - ptr1_height + 8 + 1];  // MAXIMUM BYTE SIZE OF EACH
    char width_as_string[ptr2_width - ptr1_width + 7 + 1];
    char highscores_as_string[ptr2_highscores - ptr1_highscores + 12 + 1];

    ///             Reading Configurations:
    // Reading height:
    int digit_count = 0; // counter of number of digits
    strncpy(height_as_string, (ptr1_height + 8), (ptr2_height - ptr1_height + 8)); // MAXIMUM count = number of bits
    int i = 0;
    while (height_as_string[i] != '<') // start of close tag '</'
    {
        if (!isdigit(height_as_string[i])) // if this element is not a digit
        {
            red_color();
            printf("File Corrupted\n");
            reset_color();
            *counter +=1;
            return 1;
        }
        else
        {
            digit_count++;
        }
        i++;
    }

    for (int i = 1; i <= digit_count; i++)
    {
        myconfig->height +=  ((int)height_as_string[i - 1] - 48) * pow(10, digit_count - i);
        // first digit_count elements!, 48 is the ASCII for '0'
    }

    digit_count = 0;

    // Reading width:
    strncpy(width_as_string, (ptr1_width + 7), (ptr2_width - ptr1_width + 7));
    i = 0;
    while (width_as_string[i] != '<') // start of the close tag '</'
    {
        if (!isdigit(width_as_string[i])) // if this element is not a digit
        {
            red_color();
            printf("File Corrupted\n");
            reset_color();
            *counter +=1;
            return 1;
        }
        else
        {
            digit_count++;
        }
        i++;
    }
    for (int i = 1; i <= digit_count; i++)
    {
        myconfig->width +=  ((int)width_as_string[i - 1] - 48) * pow(10, digit_count - i);
        // first digit_count elements!, 48 is the ASCII for '0'
    }

    digit_count = 0;

    // Reading highscores:
    strncpy(highscores_as_string, (ptr1_highscores + 12), (ptr2_highscores - ptr1_highscores + 12) / sizeof(int));
    i = 0;                                                                          // count = number of bits
    while(highscores_as_string[i] != '<')                                              // divided by bit size of int
    {       // start of the close tag '</'
        if (!isdigit(highscores_as_string[i])) // if this element is not a digit
        {
            red_color();
            printf("File Corrupted\n");
            reset_color();
            *counter +=1;
            return 1;
        }
        else
        {
            digit_count++;
        }
        i++;
    }

    for (int i = 1; i <= digit_count; i++)
    {
        myconfig->highscores +=  ((int)highscores_as_string[i - 1] - 48) * pow(10, digit_count - i);
        // first digit_count elements!, 48 is the ASCII for '0'
    }
    if (myconfig->height <= 3 || myconfig->width <= 3 || myconfig->highscores < 0)
    {
        red_color();
        printf("File Corrupted\n");
        reset_color();
        *counter +=1;
        return 1;   
    }
    fclose(config_file);
    return 0;
}

void parseXML(configurations *myconfig, int *counter)
{
    FILE *config_file = NULL;
    config_file = fopen("game_config.xml", "r");
    while (config_file == NULL || isFileCorrupt(myconfig, config_file, counter))
    {
        *counter += 1;

        red_color();
        printf("Please, Enter the path of your configuration file (e.g: C:\\Connect 4\\game_config.xml): ");
        reset_color();

        char path[PATH_MAX + 2]; //
        fgets(path, PATH_MAX, stdin);
        if (path[strlen(path) - 1] == '\n')
        {
            path[strlen(path) - 1] = '\0';
        }
        config_file = fopen(path, "r");
        if (*counter == 3)
        {
            break;
        }
    }
    if (*counter == 3)
    {
        yellow_color();
        printf("The user did not enter correct path for configurations file.\n");
        printf("Loading default configurations.. (Height = 9, Width = 7, Highscores = 10)\n");
        reset_color();
        myconfig->height = 9;
        myconfig->width = 7;
        myconfig->highscores = 10;
        fclose(config_file);
        return; // Default Values Assigned
    }
}