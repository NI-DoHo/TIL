# Regular Expression Matching

Ref : https://leetcode.com/problems/regular-expression-matching/

### Analyze
- 매개변수로 전달받는 문자열 2개
- 문자열 s - string과 문자열 p - pattern
- S가 P 패턴에 부합하는지 검사
- *는 모든 문자열 .은 모든 문자
- *은 앞의 문자가 아예 없거나 무한히 반복될 수 있다
> *과 .에 대한 로직이 나뉘게 된다. <br>
> 문자의 경우 

### Example
```
[True]
s = "aa"
p = "a."

[False]
s = "aaa"
p = "a."

[True]
s = "aaa"
p = "a*"
```

### NOTE
hrome