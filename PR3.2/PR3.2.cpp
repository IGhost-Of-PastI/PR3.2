#include <iostream>

template <typename T, typename U, typename V>
class MyClass {
private:
    T** array;
    int rows;
    int cols;
    U* data1;
    V* data2;

public:
    MyClass(int rows, int cols, U data1, V data2) : rows(rows), cols(cols) {
        array = new T * [rows];
        for (int i = 0; i < rows; ++i)
            array[i] = new T[cols];

        this->data1 = new U(data1);
        this->data2 = new V(data2);
    }

    MyClass(const MyClass& other) : rows(other.rows), cols(other.cols) {
        array = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            array[i] = new T[cols];
            for (int j = 0; j < cols; ++j)
                array[i][j] = other.array[i][j];
        }

        data1 = new U(*other.data1);
        data2 = new V(*other.data2);
    }

    MyClass& operator=(MyClass& other)
    {
        array = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            array[i] = new T[cols];
            for (int j = 0; j < cols; ++j)
                array[i][j] = other.array[i][j];
        }

        data1 = new U(*other.data1);
        data2 = new V(*other.data2);
    }

    ~MyClass() {
        for (int i = 0; i < rows; ++i)
            delete[] array[i];
        delete[] array;

        delete data1;
        delete data2;
    }
};

int main()
{
    std::cout << "Hello World!\n";

}
