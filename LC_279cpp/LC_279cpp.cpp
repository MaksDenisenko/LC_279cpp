// LC_279cpp.cpp Учитывая целое число n, верните наименьшее количество чисел в идеальных квадратах, сумма которых равна n.

// Идеальный квадрат - это целое число, равное квадрату целого числа; другими словами, это произведение некоторого 
// целого числа на себя.Например, 1, 4, 9, и 16 являются идеальными квадратами, в то время как 3 и 11 таковыми не являются.

#include <iostream>
int find(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n < 0) return INT_MAX;
    int minSquares = INT_MAX;
    for (int i = 1; i * i <= n; ++i) {
        int result = find(n - (i * i));
        if (result != INT_MAX) {
            minSquares = std::min(minSquares, result + 1);
        }
    }
    return minSquares;
}

int numSquares(int n) {
    return find(n);
}


int main()
{
    int N = 18;
    std::cout << numSquares(N);
}

/*
 13 = 9 + 4;
 13 = 1 + 4 + 4 + 4;
 13 = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1;
*/