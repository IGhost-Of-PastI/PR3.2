#include <iostream>
#include <string>

using namespace std;

template <typename T, typename U, typename V>
class MyClass {
private:
    T** array;
    int rows;
    int cols;
    U* data1;
    V* data2;

public:
   // template <class U, class V>
    MyClass(int rows, int cols, U data1, V data2) : rows(rows), cols(cols) {
        array = new T * [rows];
        for (int i = 0; i < rows; ++i)
            array[i] = new T[cols];

        this->data1 = new U(data1);
        this->data2 = new V(data2);
        cout << "Called constructor" << endl;
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
        cout << "Called copy constructor" << endl;
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
        cout << "called =Operator copy" << endl;
        return *this;
    }

    ~MyClass() {
        for (int i = 0; i < rows; ++i)
            delete[] array[i];
        delete[] array;

        delete data1;
        delete data2;
        cout << "called Destructor"<<endl;
    }
};

int main()
{
   MyClass<int,string,char> a(10, 10, "string",'c');
   MyClass c=a;
   MyClass b(a);
   a = b;
}
