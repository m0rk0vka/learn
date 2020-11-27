#include <iostream>


#define MAX_N 1000000


class stackArrays {
    int *m_array;
    int m_top;
public:
    stackArrays();
    stackArrays(int length);
    ~stackArrays();
    void push(int value);
    int pop();
    int show_top();
};


stackArrays::stackArrays() {
    m_array = new int[MAX_N];
    m_top = -1;
}


stackArrays::stackArrays(int length) {
    assert(length > 0 && length < MAX_N);

    m_array = new int[length];
    m_top = -1;
}


stackArrays::~stackArrays() {
    delete [] m_array;
}


void stackArrays::push(int value) {
    //assert(m_top < length);

    m_array[++m_top] = value;
    std::cout << "Push " << value << std::endl;
}


int stackArrays::pop() {
    assert(m_top > -1);

    return m_array[m_top--];
}


int stackArrays::show_top() {
    assert(m_top > -1);

    return m_array[m_top];
}

int main() {
    stackArrays X;
    //std::cout << X.show_top() << std::endl;
    //std::cout << X.pop() << std::endl;
    X.push(10);
    X.push(20);
    std::cout << "On top " << X.show_top() << std::endl;
    std::cout << "Pop " << X.pop() << std::endl;
    std::cout << "On top " << X.show_top() << std::endl;
    stackArrays Y;
    Y.push(10);
    Y.push(20);
    std::cout << "On top " << Y.show_top() << std::endl;
    std::cout << "Pop " << Y.pop() << std::endl;
    std::cout << "On top " << Y.show_top() << std::endl;
    return 0;
}