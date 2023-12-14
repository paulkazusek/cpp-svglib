# cpp-svglib

## Example

### Color

#### Color from Name

```cpp
constexpr auto alice_blue = Color( ColorName::alice_blue );
std::cout << std::format( R"(color="{}")", alice_blue) << std::endl;
```

#### Color from constants

```cpp
constexpr auto black_color = black;
```

#### Color from hex code

```cpp
constexpr auto white = from_hex( "FFFFFF" );
```
