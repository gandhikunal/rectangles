# Build instructions

Build Tool used is Bazel

Installation instructions can be found here:

[https://docs.bazel.build/versions/master/install.html](https://docs.bazel.build/versions/master/install.html)


To build, use:
```
bazel build //src/main:main
```

To run, use:
```
bazel run //src/main:main -- /path/to/jsondata.json
```

To run tests, use:
```
bazel test //tests:tests
```
# External Libraries used

[Nlohmann Json (JSON for Modern C++)](https://github.com/nlohmann/json)

[Google Test](https://github.com/google/googletest)
