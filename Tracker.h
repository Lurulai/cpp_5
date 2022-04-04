/* * * * * * * * * * * * * * *
 * Created by VSHS on 04/04/2022.
 * Don't feel like changing the comments for this one.
 * * * * */

#ifndef CPP5_TRACKER_H
#define CPP5_TRACKER_H

#include <cstring>
#include <iostream>
#include <memory>


class Tracker {
private:
    std::size_t m_instance_count{};
    std::size_t m_memory_count{};

public:
    // Initialises a default tracker object.
    Tracker();

    // increments "m_instance_count"
    void add_instance();
    // decrements "m_instance_count"
    void remove_instance();
    // adds memory to "m_memory_count"
    void add_memory (std::size_t memory);
    // subtracts memory
    void remove_memory (std::size_t memory);

    [[nodiscard]] size_t get_m_instance_count() const;
    void set_m_instance_count (size_t mInstanceCount);
    [[nodiscard]] size_t get_m_memory_count() const;
    void set_m_memory_count (size_t mMemoryCount);
};


#endif //CPP5_TRACKER_H
