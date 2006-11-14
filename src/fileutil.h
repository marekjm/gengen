#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <iostream>
#include <string>

void open_input_file(const std::string &file_name);
std::istream *open_input_file_stream(const std::string &file_name);
std::ostream &open_output_file(const std::string &file_name);
std::string strip_file_path(const std::string &s);
const std::string create_output_filename(const std::string &file_name, const std::string &ext = "");

#endif // FILEUTIL_H
