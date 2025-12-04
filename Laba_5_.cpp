#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// ==========================================================
// === ФУНКЦІЇ КОРЕКТНОГО ВВЕДЕННЯ ДАНИХ =====================
// ==========================================================

int inputInt(const string& msg, int minVal = INT_MIN, int maxVal = INT_MAX) {
    int x;
    while (true) {
        cout << msg;
        if (cin >> x && x >= minVal && x <= maxVal) return x;
        cout << "Помилка! Введіть коректне ціле число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double inputDouble(const string& msg, double minVal = -1e308, double maxVal = 1e308) {
    double x;
    while (true) {
        cout << msg;
        if (cin >> x && x >= minVal && x <= maxVal) return x;
        cout << "Помилка! Введіть коректне дійсне число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// ==========================================================
// === ЗАВДАННЯ 1 — ПІДРАХУНОК ТОЧОК У ФІГУРІ ================
// ==========================================================

// ДЕМОНСТРАЦІЙНА ФІГУРА (бо у файлі немає фігури №32):
// область = КОЛО радіусом 2 або ПРЯМОКУТНИК |x|≤1, 0≤y≤2

bool insideFigure(double x, double y) {
    bool circle = (x * x + y * y <= 4.0);
    bool rect = (fabs(x) <= 1.0 && y >= 0 && y <= 2);
    return circle || rect;
}

void task1() {
    cout << "\n=== ЗАВДАННЯ 1 ===\n";
    int n = inputInt("Введіть кількість точок: ", 1);

    int count = 0;
    for (int i = 0; i < n; i++) {
        double x = inputDouble("x = ");
        double y = inputDouble("y = ");
        if (insideFigure(x, y)) count++;
    }

    cout << "Кількість точок, що потрапили у фігуру: " << count << "\n";
}

// ==========================================================
// === ЗАВДАННЯ 2 — ОБЧИСЛЕННЯ РЯДУ ==========================
// ==========================================================

// ДЕМОНСТРАЦІЙНИЙ РЯД (бо формули №18 немає у файлі):
//     u_k = x^k / k!
// парний n → вивести кожний 3-й елемент
// непарний n → вивести кожний 4-й елемент

double factorial(int k) {
    double r = 1;
    for (int i = 2; i <= k; i++) r *= i;
    return r;
}

void task2() {
    cout << "\n=== ЗАВДАННЯ 2 ===\n";

    double x = inputDouble("Введіть x: ");
    int n = inputInt("Введіть n: ", 1);

    cout << "Обраний ряд: u_k = x^k / k!\n";

    for (int k = 1; k <= n; k++) {
        double uk = pow(x, k) / factorial(k);

        if (n % 2 == 0) {
            if (k % 3 == 0)
                cout << "k=" << k << "   u_k=" << uk << endl;
        }
        else {
            if (k % 4 == 0)
                cout << "k=" << k << "   u_k=" << uk << endl;
        }
    }
}

// ==========================================================
// === ЗАВДАННЯ 3 — ЗБІЖНІСТЬ / РОЗБІЖНІСТЬ РЯДУ =============
// ==========================================================

// ДЕМОНСТРАЦІЙНИЙ РЯД (бо №33 у файлі немає):
//     u_n = (-1)^n / (n+1)
// критерії:
// |u_n| < eps → збіжність
// |u_n| > g   → розбіжність

void task3() {
    cout << "\n=== ЗАВДАННЯ 3 ===\n";

    double eps = 1e-6;
    double g = 1e3;
    double sum = 0;

    for (int n = 1;; n++) {
        double un = pow(-1, n) / (n + 1);

        if (fabs(un) < eps) {
            cout << "Ряд ЗБІЖНИЙ, досягнуто при n = " << n << endl;
            cout << "Наближена сума: " << sum << endl;
            break;
        }

        if (fabs(un) > g) {
            cout << "Ряд РОЗБІЖНИЙ, досягнуто при n = " << n << endl;
            break;
        }

        sum += un;
    }
}

// ==========================================================
// === МЕНЮ — ЗАВДАННЯ 4 =====================================
// ==========================================================

void menu() {
    while (true) {
        cout << "\n======= М Е Н Ю =======\n";
        cout << "1 — Завдання 1 (точки у фігурі)\n";
        cout << "2 — Завдання 2 (ряд)\n";
        cout << "3 — Завдання 3 (збіжність ряду)\n";
        cout << "0 — Вихід\n";

        int ch = inputInt("Виберіть пункт: ");
        if (ch == 1) task1();
        else if (ch == 2) task2();
        else if (ch == 3) task3();
        else if (ch == 0) break;
        else cout << "Невірний пункт меню.\n";
    }
}

// ==========================================================
// === MAIN ==================================================
// ==========================================================

int main() {
    setlocale(LC_ALL, "ukr");
    menu();
    return 0;
}