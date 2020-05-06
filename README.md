# 42sv_ft_printf

```diff
+ Final result: 100/100
```

## Summury

Ft_printf is a project where you should recode libc printf function

## Parameters

A format specifier follows this prototype: 

**%**[flags][width][.precision]**specifier**

specifier | Output
--- | ---
d or i | Signed decimal integer
u | Unsigned decimal integer
p | Pointer address
x | Unsigned hexadecimal integer
X | Unsigned hexadecimal integer (uppercase)
c | Character
s | String of characters
% | A % followed by another % character will write a single % to the stream.

___

flags | Description
--- | ---
`-` | Left-justify within the given field width; Right justification is the default
0 | Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).

___

width | Description
--- | ---
(number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.
`*` | The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.

___

.precision | Description
--- | ---
.number | **For integer specifiers (d, i, u, x, X)**: precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. **For s:** this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. **If the period is** specified without an explicit value for precision, 0 is assumed.
.* | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.

## Links

* [Formatted Output and the printf function](https://www.eecs.wsu.edu/~cs150/reading/printf.htm)
* [printf](http://www.cplusplus.com/reference/cstdio/printf/)
* [printf - man](https://linux.die.net/man/3/printf)
* [stdarg - man](https://linux.die.net/man/3/stdarg)
* [Function Dispatch Tables in C](https://blog.alicegoldfuss.com/function-dispatch-tables/)
* [Tests for 42 projects for the new curriculum](https://github.com/Kwevan/42-Tests/blob/master/README.md)


