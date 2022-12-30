#ifndef XML_PARSER_H
#define XML_PARSER_H

#include "xml_parser.c"

/// @brief Function to parse the configurations from the XML file: it checks if the format is correct/ if the path is right
///         then reads the configuration if the format is right, path is right, else, it sets the parameters to default values
/// @param myconfig The configuration parameters
/// @param counter counter to count errors for parsing XML before loading default values if we reach counter = 3
void parseXML(configurations *myconfig, int *counter);


/// @brief Function to check if the file is corrupted or if the format is incorrect
/// @param myconfig The configuration parameters
/// @param config_file the XML file pointer
/// @param counter the counter that counts number of tries to parse the file
int isFileCorrupt(configurations * myconfig, FILE * config_file, int *counter);

#endif