/*
Name: Gregory Rodriguez
E-mail: grodriguez13@myseneca.ca
Student ID: 127880227
Workshop 10
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H
namespace sdds {

/*
bool search()
The templated bool search function requires one template class (T)
and takes in a random key type (U). Essentially, this function
will not work without a template class. This template function
will only work if the objects passing through have equivalency
overloads, for example "==" operator overload. 
*/
template <typename T, typename U>
bool search(Collection<T>& collection, T* data, int size, U key) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (data[i] == key) {
            collection.add(data[i]);
            found = true;
        }
    }
    return found;
}

/*
listArrayElements()
This templated function requires an object that inherits
the shift operator overload from the base class "ReadWrite".
Essentially, employee, car, and student are derived from ReadWrite.
*/
template <typename T>
void listArrayElements(const char* title, const T* data, int size) {
    std::cout << title << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << (i + 1) << ": " << data[i] << std::endl;
    }
}
}  // namespace sdds
#endif  // SDDS_SEARCHNLIST_H