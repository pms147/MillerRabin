#include <iostream>
#include <cmath>
using namespace std;

// Hàm tính (a^b) % m
int power(int a, int b, int m)
{
    int ans = 1;
    a %= m;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return ans;
}

// Hàm kiểm tra tính nguyên tố của n
bool MillerRabin(long n)
{
    if (n == 2)
        return true;

    // Bước 1: Tìm k, q sao cho n-1 = 2^k * q
    int k = 0, q = n - 1;
    while (q % 2 == 0)
    {
        k++;
        q /= 2;
    }

    // Bước 2: Lựa chọn ngẫu nhiên một số a trong khoảng (1, n-1)
    int a = 2 + rand() % (n - 3);

    // Bước 3: Kiểm tra nếu a^q mod n = 1 hoặc a^((2^j)*q) mod n = n-1
    int x = power(a, q, n);
    if (x == 1 || x == n - 1)
        return true;
    for (int j = 1; j < k; j++)
    {
        x = (x * x) % n;
        if (x == n - 1)
            return true;
        if (x == 1)
            return false;
    }

    // Nếu không thoả mãn bước 3 thì n không phải là số nguyên tố
    return false;
}

// Hàm thực thi chương trình
void isPrime(long n, int t)
{
    bool flag = false;

    for (int i = 0; i < t; i++)
    {
        flag = (MillerRabin(n));
        if (flag)
            break;
    }

    if (flag)
        cout << "Prime" << endl;
    else
        cout << "Not Prime" << endl;
}

int main()
{
    srand(time(NULL));
    long n, m;
    int t = 100;

    // cout << "Nhap n: ";
    // cin >> n;

    n = 73939133;
    m = 700001;

    isPrime(n, t);
    isPrime(m, t);

    return 0;
}
