# cpp-svglib

## Example

### Color

#### Color from Name

```cpp
constexpr auto alice_blue_color = Color( ColorName::alice_blue );
std::cout << std::format( R"(color="{}")", alice_blue_color ) << std::endl;
```

#### Color from constants

```cpp
constexpr auto black_color = black;
```

#### Color from hex code

```cpp
constexpr auto white_color = from_hex( "FFFFFF" );
```
