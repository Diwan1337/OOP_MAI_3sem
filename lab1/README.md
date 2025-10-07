# ЛР №1 — Первая программа на C++ (вариант 6)

**Задание:** написать функцию, удаляющую все гласные символы из строки.  
<img width="663" height="144" alt="image" src="https://github.com/user-attachments/assets/570649c4-a05f-44b2-86d0-60ad77f0fb83" />

Гласные: `a e i o u y` (оба регистра).

## Структура
```
lab1/
 ├─ CMakeLists.txt
 ├─ include/
 │   └─ remove_vowels.h
 ├─ src/
 │   ├─ main.cpp
 │   └─ remove_vowels.cpp
 └─ tests/
     └─ test_remove_vowels.cpp
```

## Сборка (Windows, MSVC + vcpkg)
```powershell
mkdir build
cd build
cmake .. 
cmake --build . 
```

## Запуск программы
## Запуск программы
```
ctest -C Debug --verbose
```
Или
```powershell
.\Debug\lab1_tests.exe
.\Debug\lab1.exe
```
**Пример:**
```
Ввод:    This website is for losers LOL!
Вывод:   Ths wbst s fr lsrs LL!
```

## Примечания
- Ввод/вывод через `std::cin`/`std::cout`.
- Тесты на GoogleTest (`find_package(GTest CONFIG REQUIRED)` + vcpkg).
