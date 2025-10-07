# ЛР №2 — Изучение базовых приемов работы с классами

**Тема:** Работа с динамическими контейнерами на основе динамических массивов.  
**Вариант:** Класс для работы с восьмеричными числами (Octal).

## Цели работы
1. Закрепление навыков работы с классами
2. Закрепление навыков работы с динамической памятью на «куче»
3. Закрепление навыков работы с массивами

## Описание задачи

Реализовать класс `Octal` для представления чисел в восьмеричной системе счисления. Каждая цифра хранится в отдельном элементе массива типа `unsigned char`. Младшая цифра находится в нулевом элементе массива (little-endian порядок).

### Основные возможности
- Создание чисел из строки, списка инициализации
- Арифметические операции: сложение, вычитание
- Операции сравнения: больше, меньше, равно
- Копирование и перемещение объектов
- Автоматическое управление памятью

## Структура проекта
```
lab2/
├─ CMakeLists.txt
├─ README.md
├─ include/
│   └─ Octal.h
├─ src/
│   └─ Octal.cpp
└─ tests/
    └─ test_octal.cpp
```
## Сборка проекта

### Шаг 1: Создание папки для сборки
````
mkdir build
cd build
````
### Шаг 2: Генерация проекта с помощью CMake
````
cmake ..
````
### Шаг 3: Компиляция проекта
````
cmake --build .
````
## Запуск тестов

### Через CTest
````
ctest -C Debug --verbose
````
### Напрямую исполняемый файл
````
.\Debug\octal_tests.exe
````

### Ожидаемый результат
````
[==========] Running 8 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 8 tests from OctalTest
[ RUN ] OctalTest.DefaultConstructor
[ OK ] OctalTest.DefaultConstructor (0 ms)
[ RUN ] OctalTest.StringConstructor
[ OK ] OctalTest.StringConstructor (0 ms)
[ RUN ] OctalTest.InitializerListConstructor
[ OK ] OctalTest.InitializerListConstructor (0 ms)
[ RUN ] OctalTest.Addition
[ OK ] OctalTest.Addition (0 ms)
[ RUN ] OctalTest.Subtraction
[ OK ] OctalTest.Subtraction (0 ms)
[ RUN ] OctalTest.Comparison
[ OK ] OctalTest.Comparison (0 ms)
[ RUN ] OctalTest.InvalidDigit
[ OK ] OctalTest.InvalidDigit (0 ms)
[ RUN ] OctalTest.NegativeSubtraction
[ OK ] OctalTest.NegativeSubtraction (0 ms)
[----------] 8 tests from OctalTest (3 ms total)

[----------] Global test environment tear-down
[==========] 8 tests from 1 test suite ran. (4 ms total)
[ PASSED ] 8 tests.
````