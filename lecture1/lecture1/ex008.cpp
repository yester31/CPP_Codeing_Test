#include <iostream>
#include <vector>
using namespace std;

// ¿Ã¹Ù¸¥ °ýÈ£

void ex008() {
    char a[] = "(()(()))(()";
    int cnt = 0;

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '(')
        {
            cnt++;
        }
        else if (a[i] == ')') {
            cnt--;
        }
        else
        {
            break;
        }

        if (cnt < 0)
        {
            break;
        }
    }
    if (cnt == 0)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

//int main() {
//    ex008();
//    std::cout << "done!" << std::endl;
//}
// no