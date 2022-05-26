#include <iostream>
#include <sstream>
#include <algorithm>

template <typename T>
class dynamic_array
{
    T* data;	// �迭 �ּ�
    size_t n;	// �迭 ũ�� 

public:
    dynamic_array(int n) { // �迭�� ũ�⸦ ���ڷ� �޴� ������ 
        this->n = n;
        data = new T[n];
    }

    dynamic_array(const dynamic_array<T> & other) { //���� ������
        n = other.n;
        data = new T[n];
        for (int i = 0; i < n; i++)
            data[i] = other.data[i];
    }

    T& operator[](int index) { // ��� �����Ϳ� �����ϱ� ���� [] ������ �����ε�
        return data[index]; // �Ϻη� ���� ó�� ����
    }

    const T& operator[](int index) const { // cosnt�� ���ǵ� ��ü�� ��� �����Ϳ� �����ϱ� ���� [] ������ �����ε�
        return data[index]; // �Ϻη� ���� ó�� ����
    }

    T& at(int index) { // ��� �����Ϳ� �����ϱ� ���� at() �Լ� 
        if (index < n)
            return data[index];
        throw "Index out of range";
    }

    size_t size() const { //�迭�� ũ�⸦ ��ȯ�ϴ� �Լ�
        return n;
    }

    ~dynamic_array() { // �Ҹ���
        delete[] data; // �޸� �� ����
    }

    // ���۰� �� ��ȯ�ڸ� ����
    T* begin() { return data; }
    const T* begin() const { return data; }
    T* end() { return data + n; }
    const T* end() const { return data + n; }

    // �� �迭�� ��ġ�� + ������ �Լ� ����
    friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2){
        dynamic_array<T> result(arr1.size() + arr2.size());
        std::copy(arr1.begin(), arr1.end(), result.begin());
        std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());
        return result;
    }

    // �迭�� ����� ��� �����͸� ���ڿ��� ��ȯ�ϴ� to_string() �Լ� 
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
    std::cout << "1�� �л� ���� �Է��ϼ��� : ";
    std::cin >> nStudents;

    dynamic_array<student> class1(nStudents);
    for (int i = 0; i < nStudents; i++){
        std::string name;
        int standard;
        std::cout << i + 1 << "��° �л� �̸��� ���̸� �Է��ϼ��� : ";
        std::cin >> name >> standard;
        class1[i] = student{ name, standard };
    }

    // �迭 ���� ū �ε����� �л��� ���ٽ�
    try{
        //class1[nStudents] = student{ "TT", 18 };	// ���� �� �� ���� ����
        class1.at(nStudents) = student{ "TT", 18 }; // ���� �߻�
    }
    catch (...)
    {
        std::cout << "���� �߻�!!! : " << std::endl;
    }

    //���� ����
    auto class2 = class1;
    std::cout << "1���� �����Ͽ� 2�� ����" << class2.to_string() << std::endl;

    // �� �б��� ���ļ� ���ο� ū �б��� ����
    auto class3 = class1 + class2;
    std::cout << "1�ݰ� 2���� ���� 3�� ����" << class3.to_string() << std::endl;

    return 0;
}