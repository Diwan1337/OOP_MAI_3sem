# ЛР №1 — Первая программа на C++ (вариант 6)

**Задание:** написать функцию, удаляющую все гласные символы из строки.  
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
cmake .. -G "Visual Studio 16 2019" -A x64 -DCMAKE_TOOLCHAIN_FILE="E:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build . --config Debug
ctest -C Debug
```

## Запуск программы
```powershell
.uild\Debug\lab1.exe
```
**Пример:**
```
Ввод:    This website is for losers LOL!
Вывод:   Ths wbst s fr lsrs LL!
```

## Примечания
- Ввод/вывод через `std::cin`/`std::cout`.
- Тесты на GoogleTest (`find_package(GTest CONFIG REQUIRED)` + vcpkg).
