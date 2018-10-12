#include <iostream>
#include "Rational.h"

using namespace std;

int main() {
    int n;
    Rational sum = rational(0, 1);
    Rational list[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        read(list[i]);
        sum = add(list[i], sum);
    }
    print(sum);
    
    puts("");
    sortBI(list, n);
    for (int i = 0; i < n; print(list[i]), i++);
    
    puts("");
    sortBD(list, n);
    for (int i = 0; i < n; print(list[i]), i++);
    
    return 0;
}
