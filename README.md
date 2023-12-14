# cpp-svglib

## Example

### Color

```cpp
constexpr auto alice_blue = Color( ColorName::alice_blue );
std::cout << std::format( R"(color="{}")", alice_blue) << std::endl;
```

```cpp
constexpr auto white = from_hex( "FFFFFF" );
```
