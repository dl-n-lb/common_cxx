# types
## index 
- [type aliases](#type-aliases)
- [vecn](#vecn)

## type aliases 
### idea
This is a file full of useful simplifications of common types and some simd type aliases 
in order to make them more convenient for the end user.
### NOTE 
This can obfuscate some error messages so be sure to read the whole message!

## vecn
### idea
A complete N-tuple vector for use in linear algebra.
Implementation uses an `std::array` under the hood (TODO: low dimension template 
specializations to increase speed, i.e. n=2,3,4).
### linking
This is a header only resource so there is no need to link anything
### Testing
It is tested using the unit tests found in ../test/, under the `VectorTest` test suite.
