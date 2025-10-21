# cpp06

C++ exercises - Casts, Serialization, and RTTI (42 school)

## Project Structure

- **ex00**: ScalarConverter
  - Static class for conversion of scalar types (char, int, float, double) from string.
- **ex01**: Serializer
  - Serialization and deserialization of pointers using reinterpret_cast.
- **ex02**: RTTI & Dynamic Cast
  - Identification of the real type of objects using dynamic_cast and RTTI.

Each exercise contains:
- Source and header files for the classes
- `main.cpp` to test functionalities
- `Makefile` for compilation

## Compilation

To compile each exercise:

```sh
cd ex00 && make
cd ex01 && make
cd ex02 && make
```

## Execution

Each executable is in its respective folder. Example:

```sh
./ex00/scalarConverter
./ex01/serializer
./ex02/rtti
```

## Author
Project developed for 42 school.
