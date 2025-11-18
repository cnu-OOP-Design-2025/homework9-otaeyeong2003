#include <iostream>
#include <string>
#include <list>
using namespace std;

template<typename T>
class MyVector {
private:
    int* data;
    size_t capacity;
    size_t length;
    
    void resize() {
        cout << "Resize: " << capacity << " -> " << capacity * 2 << endl;

        int double_capacity = capacity*2;
        int * arr= new int[double_capacity];

        for (int i=0; i<length; i++) {
            arr[i] = data[i];
        }
        
        delete[] data;
        data = arr;
        }

public:
    
    MyVector() : capacity(2), length(0) {
        data = new int[capacity];
        /* TODO */
        // data는 capacity 크기의 배열을 동적 할당하세요.
    }

    ~MyVector() {
        delete[] data;
        /* TODO */
        // 동적 할당된 data를 해제하세요.
    }

    void push_back(const int& value) {
        if (length == capacity){
            resize();
        }
        /* TODO */
        // length가 capacity에 도달하면 resize()를 호출하세요.
        
        data[length++] = value;
        /* TODO */
        // 새로운 요소를 배열 끝에 추가하고 length를 증가시키세요.
    }

    // 마지막 항목을 리턴하세요.
    int pop_back() {
        if (length == 0)
            throw out_of_range("Vector is empty");
        return data[--length]; // 마지막 요소 제거
    }

    // 주어진 index의 요소를 반환하세요.
    int& operator[](const int index){
        return data[index];
    }

    // 현재 저장된 요소 개수를 반환하세요.
    size_t size() const {
        return length;
    }

};

template<typename T>
void testVector(const string& name, std::list<T> values) {

    cout << "------------------" << endl;
    MyVector<T> vec;
    for (auto& v : values)
        vec.push_back(v);

    cout << name << ": ";
    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";

    cout << endl;
    while(vec.size())
        cout << "Pop: " << vec.pop_back() << "\n";
}

int main() {
    testVector<int>("IntVec", {1, 2, 3, 4, 5, 6});
    testVector<double>("DoubleVec", {1.1, 2.2, 3.3, 4.4, 5.5});
    testVector<char>("CharVec", {'A', 'B', 'C', 'D', 'E', 'F'});
    testVector<string>("StringVec", {"Hello", "World", "C++", "Template", "Vector"});
    return 0;
}
