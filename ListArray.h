#include <ostream>
#include <stdexcept>
#include "List.h"


template <typename T> 
class ListArray : public List<T> {
    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE;
        void resize(int new_size);

    public:
        ListArray();
        ~ListArray();
        T operator[](int pos);
        
        // La sobrecarga del operador << en plantillas suele definirse mejor directamente inline
        friend std::ostream& operator<<(std::ostream &out, ListArray<T> &list) {
            out << "[";
            for (int i = 0; i < list.size(); i++) {
                out << list.get(i);
                if (i < list.size() - 1) out << ", ";
            }
            out << "]";
            return out;
        }

        void insert(int pos, T e) override;
        void append(T e) override;
        void prepend(T e) override;
        T remove(int pos) override;
        T get(int pos) override;
        int search(T e) override;
        bool empty() override;
        int size() override;
};

// ==========================================
// IMPLEMENTACIÓN DE LOS MÉTODOS (Templates)
// ==========================================

// Inicialización de la constante estática a 2
template <typename T>
const int ListArray<T>::MINSIZE = 2;

// Constructor
template <typename T>
ListArray<T>::ListArray() {
    n = 0;
    max = MINSIZE;
    arr = new T[max];
}

// Destructor
template <typename T>
ListArray<T>::~ListArray() {
    delete[] arr;
}

// Redimensionar el array
template <typename T>
void ListArray<T>::resize(int new_size) {
    T* new_arr = new T[new_size];
    for (int i = 0; i < n; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    max = new_size;
}

// insert
template <typename T>
void ListArray<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n) {
        throw std::out_of_range("Posición no válida");
    }
    if (n == max) {
        resize(max * 2);
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = e;
    n++;
}

// append
template <typename T>
void ListArray<T>::append(T e) {
    insert(n, e);
}

// prepend
template <typename T>
void ListArray<T>::prepend(T e) {
    insert(0, e);
}

// remove
template <typename T>
T ListArray<T>::remove(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición no válida");
    }
    T removed_element = arr[pos];
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    return removed_element;
}

// get
template <typename T>
T ListArray<T>::get(int pos) {
    if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición no válida");
    }
    return arr[pos];
}

// search
template <typename T>
int ListArray<T>::search(T e) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == e) {
            return i;
        }
    }
    return -1;
}

// empty
template <typename T>
bool ListArray<T>::empty() {
    return n == 0;
}

// size
template <typename T>
int ListArray<T>::size() {
    return n;
}

// Operador []
template <typename T>
T ListArray<T>::operator[](int pos) {
    return get(pos);
}

