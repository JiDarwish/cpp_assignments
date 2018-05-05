## Somethings only work with the std of c++ version 11
Which is why when you run a file with one of these features it should be run with this script instean of the normal one.

```bash
c++ -std=c++11 -o <COMPILED_FILE_NAME> <FILE_TO_BE_COMPILED>.cpp
```

An example of these features is the `std::to_string()` method.