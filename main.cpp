#include <iostream>  // Для std::cout
#include <vector>    // Для std::vector
#include <algorithm> // Для std::find_if

// Task 1. Имеется отсортированный массив целых чисел. Необходимо разработать функцию
// insert_sorted, которая принимает вектор и новое число и вставляет новое число в
// определенную позицию в векторе, чтобы упорядоченность контейнера сохранялась.
// Реализуйте шаблонную функцию insert_sorted, которая сможет аналогично работать с любым
// контейнером, содержащим любой тип значения.
template <typename Container, typename Type>
void insert_sorted(Container& arr, const Type in){
    auto it = std::find_if(arr.begin(), arr.end(), [in](int i){
        return (in <= i);
    });
    arr.insert(it, in);
}

#include <iterator>

// Task 2. Сгенерируйте вектор a, состоящий из 100 вещественный чисел, представляющий собой
// значения аналогового сигнала. На основе этого массива чисел создайте другой вектор целых
// чисел b, представляющий цифровой сигнал, в котором будут откинуты дробные части чисел.
// Выведите получившиеся массивы чисел. Посчитайте ошибку, которой обладает цифровой
// сигнал по сравнению с аналоговым по формуле:
// 𝑖=0; 𝑁−1; ∑ (𝑎𝑖 − 𝑏𝑖) ^ 2
// где:
// N - количество элементов в векторе,
// a - элемент вектора с дробными числами,
// b - элемент вектора с целыми числами
// Постарайтесь воспользоваться алгоритмическими функциями, не используя циклы.
void Task2(){
    const unsigned int SIZE = 10;
    std::vector<double> a(SIZE, 0.0);
    std::generate(a.begin(), a.end(), [](){ return double(rand()%1000)/double(10); });
    std::cout << "Arr 'a': ";
    for(const auto& it : a) std::cout << it << ", "; std::cout << std::endl;
    std::vector<int> b;
    std::copy(a.begin(), a.end(), std::back_inserter(b));
    std::cout << "Arr 'b': ";
    for(const auto& it : b) std::cout << it << ", "; std::cout << std::endl;
    std::cout << "Result:  ";
    for(auto i = 0; i < a.size(); ++i) std::cout << a[i] - b[i] << ", "; std::cout << std::endl;
}

int main(){
    
    // Task 1 ====================
    std::cout << "Task 1:" << std::endl;
    std::vector<int> array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(const auto& it : array) std::cout << it << ' '; std::cout << std::endl;
    insert_sorted(array, 5);
    for(const auto& it : array) std::cout << it << ' '; std::cout << std::endl;
    std::cout << std::endl << std::endl;
    // ===========================

    // Task 2 ====================
    std::cout << "Task 2:" << std::endl;
    Task2();
    std::cout << std::endl;
    // ===========================

    return 0;
}