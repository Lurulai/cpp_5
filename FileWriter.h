/* * * * * * * * * * * * * * *
 * Created by VSHS on 04/04/2022.
 * * * * */

#ifndef ASSIGNMENT5_FILEWRITER_H
#define ASSIGNMENT5_FILEWRITER_H

#include <string>
#include <cstring>


class FileWriter {
private:
    std::FILE* file;
    int new_lines;
    int char_count;

public:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Creation of a basic file writer object which will open a file to write in.
     * @param   const char*         Name desired for created file.
     */
    explicit FileWriter (const char* file_name);

    // Destructor that will close the file.
    ~FileWriter();

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Will check if the file is open or not.
     * @return  bool                Boolean, true if file open, false otherwise.
     */
    bool is_open();


    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function used to write into a file.
     * @param   std::string         Takes a string to write into the file.
     * @return  FileWriter&         Returns the file writer.
     */
    FileWriter& write (std::string str);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function used to write into a file.
     * @param   const char*         Takes a string to write into the file.
     * @return  FileWriter&         Returns the file writer.
     */
    FileWriter& write (const char* str);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function used to write into a file.
     * @param   char                Takes a character to write into the file.
     * @return  FileWriter&         Returns the file writer.
     */
    FileWriter& write (char ch);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function used to write into a file.
     * @param   int                 Takes an integer to write into the file.
     * @return  FileWriter&         Returns the file writer.
     */
    FileWriter& write (int num);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function used to write into a file.
     * @param   double              Takes a double-precision floating point to write into the file.
     * @return  FileWriter&         Returns the file writer.
     */
    FileWriter& write (double doub);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function used to write into a file.
     * @param   bool                Takes a boolean to write into the file.
     * @return  FileWriter&         Returns the file writer.
     */
    FileWriter& write (bool boo);


    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function used to write into a file.
     * @param   std::string         Takes a string to write into the file.
     * @return  FileWriter&         Returns the file writer.
     */
    FileWriter& and_then (std::string str);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function used to write into a file.
     * @param   const char*         Takes a string to write into the file.
     * @return  FileWriter&         Returns the file writer.
     */
    FileWriter& and_then (const char* str);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function used to write into a file.
     * @param   char                Takes a character to write into the file.
     * @return  FileWriter&         Returns the file writer.
     */
    FileWriter& and_then (char ch);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function used to write into a file.
     * @param   int                 Takes an integer to write into the file.
     * @return  FileWriter&         Returns the file writer.
     */
    FileWriter& and_then (int num);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function used to write into a file.
     * @param   double              Takes a double-precision floating point to write into the file.
     * @return  FileWriter&         Returns the file writer.
     */
    FileWriter& and_then (double doub);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function used to write into a file.
     * @param   bool                Takes a boolean to write into the file.
     * @return  FileWriter&         Returns the file writer.
     */
    FileWriter& and_then (bool boo);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function used to write a new line character into the file.
     * @return  FileWriter&         Returns the file writer.
     */
    FileWriter& newline();

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Counts how many lines are present in the current file.
     * @param   int                 Takes an amount to add to a line counter.
     */
    void add_new_lines (int newLines);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Counts how many characters are present in the current file.
     * @param   int                 Takes an amount to add to a character counter.
     */
    void add_char_count (int charCount);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function to return how many lines are written within a file.
     * @return  int                 Returns an integer showing amount of lines in the file.
     */
    [[nodiscard]] int lines() const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Function to return how many characters are written within a file.
     * @return  int                 Returns an integer showing amount of characters in the file.
     */
    [[nodiscard]] int size() const;
};


#endif //ASSIGNMENT5_FILEWRITER_H
