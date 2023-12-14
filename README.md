﻿# cpp-svglib

## Example

### Color

```cpp
constexpr auto alice_blue = Color( ColorName::alice_blue );
std::cout << "color=\"" << alice_blue.serialize() << "\"" << std::endl;
```

```cpp
constexpr auto white = from_hex( "FFFFFF" );
```
