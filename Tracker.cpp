/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Created by VSHS on 04/04/2022.
 * Constructor used to initialise values accordingly.
 * Functions are pretty self-explanatory - Mostly used to keep track of memory & instances,
 * to-do with class-handling.
 * * * * * * * * * * * * * * */

#include "Tracker.h"


Tracker::Tracker():
        m_instance_count{0},
        m_memory_count{0}
{ }

// increments "m_instance_count"
void Tracker::add_instance() {
    this->m_instance_count++;
}

// decrements "m_instance_count"
void Tracker::remove_instance() {
    this->m_instance_count--;
}

// adds memory to "m_memory_count"
void Tracker::add_memory (std::size_t memory) {
    this->m_memory_count += memory;
}

// subtracts memory
void Tracker::remove_memory (std::size_t memory) {
    this->m_memory_count -= memory;
}

size_t Tracker::get_m_instance_count() const {
    return m_instance_count;
}

void Tracker::set_m_instance_count (size_t mInstanceCount) {
    m_instance_count = mInstanceCount;
}

size_t Tracker::get_m_memory_count() const {
    return m_memory_count;
}

void Tracker::set_m_memory_count (size_t mMemoryCount) {
    m_memory_count = mMemoryCount;
}
