/* * * * * * * * * * * * * * *
 * Created by VSHS on 04/04/2022.
 * * * * */

#ifndef ASSIGNMENT5_DYNAMICARRAY_H
#define ASSIGNMENT5_DYNAMICARRAY_H

#include "Tracker.h"

class DynamicArray{
private:
    std::size_t m_capacity;
    std::size_t m_size;
    std::shared_ptr <double[]> m_data;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Reserves, or allocates, more memory in the dynamic array if necessary.
     * @param   size_t             Minimum capacity that must be allocated or reserved.
     */
    void reserve (std::size_t min_capacity);

public:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Creation of a basic dynamic array with n capacity.
     * @param   size_t             The capacity chosen for array of type size_t.
     */
    explicit DynamicArray (std::size_t capacity);

     // Creation of a default dynamic array with default capacity.
    DynamicArray();

    // Destructor of aforementioned arrays.
    ~DynamicArray();

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Gets data from created array.
     * @return  double*            Current data from the array, the array.
     */
    double* get();

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Gets data from created array (Const overloaded).
     * @return  const double*      Current data from the array, the array.
     */
    [[nodiscard]] const double* get() const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Gets data from created array at a certain index.
     * @param   size_t             The chosen index to get data from.
     * @return  double&            Current data from the array at a certain index.
     */
    double& at (std::size_t index);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Gets data from created array at a certain index (Const overloaded).
     * @param   size_t             The chosen index to get data from.
     * @return  const double&      Current data from the array at a certain index.
     */
    [[nodiscard]] const double& at (std::size_t index) const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Gets the size of the current array.
     * @return  size_t             The current size of the array.
     */
    [[nodiscard]] std::size_t size() const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Gets the capacity of the current array.
     * @return  std::size_t        The current capacity of the array.
     */
    [[nodiscard]] std::size_t capacity() const;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Pushes an n amount of the same, chosen value into the array.
     * @param   size_t             The chosen amount of pushes of value.
     * @param   double             The chosen value to push.
     */
    void push_n (std::size_t count, double val);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Pushes a value to the end of the array while allocating necessary memory.
     * @param   double             The chosen value to push.
     */
    void push_back (double val);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Pops, or removes, the last element in the array.
     * @return  double             The current size after popping an element from the array.
     */
    double pop_back();

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * Inserts a value to a certain, chosen index and allocates necessary space for it.
    * @param   size_t              The chosen index.
    * @param   double              The chosen value to push.
    */
    void insert (std::size_t index, double val);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Removes a value at a certain, chosen index.
     * @param   size_t             The chosen index to remove the element from.
     * @return  double             The value that has been removed.
     */
    double remove (std::size_t index);

    // Initialising a tracker object.
    static inline Tracker tracker{};

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Makes a deep copy of an existing array, while pushing the elements of the new array to the
     * original data value.
     * @return  DynamicArray       The new copy of the array.
     */
    [[nodiscard]] DynamicArray deep_copy() const;
};


#endif //ASSIGNMENT5_DYNAMICARRAY_H
