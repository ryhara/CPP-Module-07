#include <ctime>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 10
int main(int, char**)
{
    std::cout << "---- subject test ----" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand() % 100;
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "---- numbers ----" << std::endl;
    std::cout << "size: " << numbers.size() << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    std::cout << "---- mirror ----" << std::endl;
    std::cout << "size: " << numbers.size() << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << mirror[i] << " ";
    std::cout << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "---- tmp ----" << std::endl;
        std::cout << "size: " << tmp.size() << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
            std::cout << tmp[i] << " ";
        std::cout << std::endl;
        std::cout << "---- test ----" << std::endl;
        std::cout << "size: " << test.size() << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
            std::cout << test[i] << " ";
        std::cout << std::endl;
        std::cout << "---- tmp[0] = 42 ----" << std::endl;
        tmp[0] = 42;
        std::cout << "--- numbers ---" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;
        std::cout << "---- tmp ----" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
            std::cout << tmp[i] << " ";
        std::cout << std::endl;
        std::cout << "---- test ----" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
            std::cout << test[i] << " ";
        std::cout << std::endl << std::endl;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << "---- numbers change ----" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand() % 100;
    }
    std::cout << "---- numbers ----" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    delete [] mirror;//
    // ----------------------------------------------------------------------------------------------------------------
    std::cout << "---------------------" << std::endl << std::endl;

    std::cout << "---- my test ----" << std::endl;
    std::cout << "---- size0 arr ----" << std::endl;
    Array<int> arr;
    try {
        for (int i = 0; i < 5; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << "size: " << arr.size() << std::endl;
    std::cout << std::endl;
    std::cout << "--- string ---" << std::endl;
    Array<std::string> str(5);
    str[0] = "hello";
    str[1] = "world";
    str[2] = "42";
    str[3] = "tokyo";
    str[4] = "!";
    std::cout << "---- str ----" << std::endl;
    std::cout << "size: " << str.size() << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << str[i] << " ";
    std::cout << std::endl;
    std::cout << "--------------" << std::endl << std::endl;
    const Array<int> arr2(5);
    std::cout << "---- const arr2 ----" << std::endl;
    std::cout << "size: " << arr2.size() << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;
    // cannot compile because arr2 is const
    // arr2[0] = 42;
    std::cout << "--------------" << std::endl << std::endl;
    return 0;
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }