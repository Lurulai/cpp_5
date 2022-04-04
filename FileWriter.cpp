/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Created by VSHS on 04/04/2022.
 * Constructor used to initialise values and open the file. Destructor will close & flush it accordingly.
 * Two main functions; "write", and "and_then".
 * "write" will write on to a file (and create it if non-existent), depending on the type.
 * "and_then" is virtually the same, it's just a neat way to add on to "write".
 *
 * "newLine" adds a new-line character.
 * "lines" checks how many lines were written,
 * and "size" checks how many characters have been written, with the help of "fprints".
 * * * * * * * * * * * * * * */

#include "FileWriter.h"


FileWriter::FileWriter (const char* file_name):
    new_lines{0},
    char_count{0}
{
    this->file = std::fopen(file_name, "a+");
}

FileWriter::~FileWriter() {
    std::fflush(this->file);
    std::fclose(this->file);
}

bool FileWriter::is_open() {
    return this->file != nullptr;
}

FileWriter &FileWriter::write (std::string str) {
    auto counter {0};
    add_char_count(std::fprintf(this->file, "%s", str.c_str()));

    size_t nPos = str.find('\n', 0);
    while (nPos != std::string::npos) {
        counter++;
        nPos = str.find('\n', nPos + 1);
    }
    add_new_lines(counter);
    return *this;
}

FileWriter &FileWriter::write (const char* str) {
    auto counter {0};
    auto str_length = strlen(str);
    for (auto c{0}; c < str_length; ++c) {
        char ch = str[c];
        if (ch == '\n') {
            counter++;
        }
    }
    add_char_count(std::fprintf(this->file, "%s", str));
    add_new_lines(counter);
    return *this;
}

FileWriter &FileWriter::write (char ch) {
    add_char_count(std::fprintf(this->file, "%c", ch));
    if (ch == '\n') {
        add_new_lines (1);
    }
    return *this;
}

FileWriter &FileWriter::write (int num) {
    add_char_count(std::fprintf(this->file, "%d", num));
    return *this;
}

FileWriter &FileWriter::write (double doub) {
    add_char_count(std::fprintf(this->file, "%f", doub));
    return *this;
}

FileWriter &FileWriter::write (bool boo) {
    add_char_count(std::fprintf(this->file, "%d", boo));
    return *this;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * */

FileWriter &FileWriter::and_then (std::string str) {
    auto counter {0};
    add_char_count(std::fprintf(this->file, "%s", str.c_str()));

    size_t nPos = str.find('\n', 0);
    while (nPos != std::string::npos) {
        counter++;
        nPos = str.find('\n', nPos + 1);
    }
    add_new_lines(counter);
    return *this;
}

FileWriter &FileWriter::and_then (const char* str) {
    auto counter {0};
    auto str_length = strlen(str);
    for (auto c{0}; c < str_length; ++c) {
        char ch = str[c];
        if (ch == '\n') {
            counter++;
        }
    }
    add_char_count(std::fprintf(this->file, "%s", str));
    add_new_lines(counter);
    return *this;
}

FileWriter &FileWriter::and_then (char ch) {
    add_char_count(std::fprintf(this->file, "%c", ch));
    if (ch == '\n') {
        add_new_lines(1);
    }
    return *this;
}

FileWriter &FileWriter::and_then (int num) {
    add_char_count(std::fprintf(this->file, "%d", num));
    return *this;
}

FileWriter &FileWriter::and_then (double doub) {
    add_char_count(std::fprintf(this->file, "%f", doub));
    return *this;
}

FileWriter &FileWriter::and_then (bool boo) {
    add_char_count(std::fprintf(this->file, "%d", boo));
    return *this;
}

FileWriter &FileWriter::newline() {
    std::fputs("\n", this->file);
    add_new_lines(1);
    add_char_count(1);
    return *this;
}

int FileWriter::lines() const {
    return this->new_lines;
}

int FileWriter::size() const {
    return this->char_count;
}

void FileWriter::add_new_lines (int newLines) {
    this->new_lines += newLines;
}

void FileWriter::add_char_count (int charCount) {
    this->char_count += charCount;
}
