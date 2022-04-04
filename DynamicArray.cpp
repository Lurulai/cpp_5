/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Created by Dawid Zalewski
 * DynamicArray is responsible for creating just that - A dynamic array.
 * Takes care of memory allocation, capacity, adding and removing elements,
 *      and also includes a tracker.
 * Again, pretty self-explanatory.
 * * * * * * * * * * * * * * */

#include "DynamicArray.h"


const static std::size_t DEFAULT_CAP{16};
const static std::size_t GROWTH_FAC{2};

DynamicArray::DynamicArray (std::size_t capacity):
    m_capacity{capacity? capacity : DEFAULT_CAP},
    m_size{0},
    m_data{new double [m_capacity]}
{
    DynamicArray::tracker.add_instance();
    DynamicArray::tracker.add_memory (this->m_capacity);
}

DynamicArray::DynamicArray():
        DynamicArray{DEFAULT_CAP}
{
    DynamicArray::tracker.add_instance();
    DynamicArray::tracker.add_memory (this->m_capacity);
}

void DynamicArray::reserve (std::size_t min_capacity){
    auto new_capacity = this->m_capacity;
    while (new_capacity < min_capacity){
        new_capacity *= GROWTH_FAC;
    }
    if (new_capacity != this->m_capacity){
// create a new array
        auto new_data = std::make_shared <double[]> (new_capacity);
        std::copy(&this->m_data[0],
                  &this->m_data [(long) this->m_size],
                  &new_data[0]);
        this->m_data.reset();
        this->m_capacity = new_capacity;
    }
}

double* DynamicArray::get(){
    return this->m_data.get();
}
const double* DynamicArray::get() const {
    return this->m_data.get();
}
double& DynamicArray::at (std::size_t index){
    return this->m_data [(long) index];
}
const double& DynamicArray::at (std::size_t index) const {
    return this->m_data [(long) index];
}
std::size_t DynamicArray::size() const {
    return this->m_size;
}
std::size_t DynamicArray::capacity() const {
    return this->m_capacity;
}
void DynamicArray::push_n (std::size_t count, double val){
    reserve(this->m_size + count);
    std::fill_n(&this->m_data [(long) this->m_size],
                count,
                val);
    this->m_size += count;
}
void DynamicArray::push_back (double val){
    reserve (size() + 1);
    this->m_data [(long) this->m_size++] = val;
}
double DynamicArray::pop_back(){
    this->m_size--;
    return m_data[(long) this->m_size];
}
void DynamicArray::insert (std::size_t index, double val){
    reserve (size() + 1);
    std::move(&this->m_data [(long) index],
              &this->m_data [(long) this->m_size],
              &this->m_data [(long) index+1]);
    this->m_data [(long) index] = val;
    this->m_size++;
}

double DynamicArray::remove (std::size_t index){
    auto result {this->m_data [(long) index]};
    std::move(&this->m_data [(long) index+1],
              &this->m_data [(long) this->m_size],
              &this->m_data [(long) index]);
    this->m_size--;
    return result;
}

DynamicArray DynamicArray::deep_copy() const {
    DynamicArray copy {this->m_size};
    auto new_data = std::make_shared <double[]> (this->m_capacity);
    std::copy(&this->m_data[0],
              &this->m_data [(long) this->m_size],
              &new_data[0]);
    copy.m_data = std::move(new_data);
    return copy;
}

DynamicArray::~DynamicArray() {
    DynamicArray::tracker.remove_instance();
    DynamicArray::tracker.remove_memory(this->m_capacity);
}