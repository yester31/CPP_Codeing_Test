#include <iostream>
#include <sstream>
#include <algorithm>

template <typename T>
class dynamic_array
{
    T* data;	// 배열 주소
    size_t n;	// 배열 크기 

public:
    dynamic_array(int n) { // 배열의 크기를 인자로 받는 생성자 
        this->n = n;
        data = new T[n];
    }

    dynamic_array(const dynamic_array<T> & other) { //복사 생성자
        n = other.n;
        data = new T[n];
        for (int i = 0; i < n; i++)
            data[i] = other.data[i];
    }

    T& operator[](int index) { // 멤버 데이터에 접근하기 위한 [] 연산자 오버로딩
        return data[index]; // 일부러 예외 처리 안함
    }

    const T& operator[](int index) const { // cosnt로 정의된 객체의 멤버 데이터에 접근하기 위한 [] 연산자 오버로딩
        return data[index]; // 일부러 예외 처리 안함
    }

    T& at(int index) { // 멤버 데이터에 접근하기 위한 at() 함수 
        if (index < n)
            return data[index];
        throw "Index out of range";
    }

    size_t size() const { //배열의 크기를 반환하는 함수
        return n;
    }

    ~dynamic_array() { // 소멸자
        delete[] data; // 메모리 릭 방지
    }

    // 시작과 끝 반환자를 리턴
    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() { return data + n; }
    const T* end() const { return data + n; }

    // 두 배열을 합치는 + 연산자 함수 정의
    friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2){
        dynamic_array<T> result(arr1.size() + arr2.size());
        std::copy(arr1.begin(), arr1.end(), result.begin());
        std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());
        return result;
    }

    // 배열에 저장된 모든 데이터를 문자열로 반환하는 to_string() 함수 
    std::string to_string(const std::string& sep = ", "){
        if (n == 0)
            return "";

        std::ostringstream os;
        os << data[0];

        for (int i = 1; i < n; i++)
            os << sep << data[i];

        return os.str();
    }
};

struct student{
    std::string name;
    int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s){
    return (os << "[" << s.name << ", " << s.standard << "]");
}

int main()
{
    int nStudents;
    std::cout << "1반 학생 수를 입력하세요 : ";
    std::cin >> nStudents;

    dynamic_array<student> class1(nStudents);
    for (int i = 0; i < nStudents; i++){
        std::string name;
        int standard;
        std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요 : ";
        std::cin >> name >> standard;
        class1[i] = student{ name, standard };
    }

    // 배열 보다 큰 인덱스의 학생에 접근시
    try{
        //class1[nStudents] = student{ "TT", 18 };	// 예상 할 수 없는 동작
        class1.at(nStudents) = student{ "TT", 18 }; // 예외 발생
    }
    catch (...)
    {
        std::cout << "예외 발생!!! : " << std::endl;
    }

    //깊은 복사
    auto class2 = class1;
    std::cout << "1반을 복사하여 2반 생성" << class2.to_string() << std::endl;

    // 두 학급을 합쳐서 새로운 큰 학급을 생성
    auto class3 = class1 + class2;
    std::cout << "1반과 2반을 합쳐 3반 생성" << class3.to_string() << std::endl;

    return 0;
}