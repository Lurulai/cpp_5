/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Assignment 5
 * Name: Victoria Stephany Huisman Sigcha
 * Student nr.: 491775@student.saxion.nl
 * Class: ETI1V.ID
 *      I don't personally understand the connection between Dynamic Array & Trackers, and the FileWriter.
 * Was I supposed to use Tracker within FileWriter? Or make dynamic arrays relating to files..?
 *      Anyway. Comments relating to each class functionality is on each .cpp file. Params and such are on
 * header files.
 * * * * * * * * * * * * * * */

#include <iostream>

#include "Tracker.h"
#include "DynamicArray.h"
#include "FileWriter.h"


int main() {
    // DynamicArray test.
    DynamicArray da1{1024*768};
    std::cout << "Instances: " << DynamicArray::tracker.get_m_instance_count() << " memory: " << DynamicArray::tracker.get_m_memory_count() << "\n";

    DynamicArray da2{1024 * 255};
    std::cout << "Instances: " << DynamicArray::tracker.get_m_instance_count() << " memory: " << DynamicArray::tracker.get_m_memory_count() << "\n";
    {
        // new scope
        DynamicArray da3{128};
        std::cout << "Instances: " << DynamicArray::tracker.get_m_instance_count() << " memory: " << DynamicArray::tracker.get_m_memory_count() << "\n";
    }

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * */

    // FileWriter tests.
    FileWriter fw{"test.txt"};
    fw.write("Alice has ").and_then(3).and_then(" rats.").newline();

    std::cout << "Written " << fw.size() << " chars and "
              << fw.lines() << " lines.\n";

    fw.write("True of false: does Alice like rats?\n")
                     .and_then("Answer: ")
                     .and_then(true)
                     .and_then("\n");
    std::cout << "Written " << fw.size() << " chars and " << fw.lines() << " lines.\n";
}
