# 네임드, 기본 인자

## Default parameter
```
fun max(a: Int = 0, b: Int = 0) = if (a > b) a else b
```
기본인자는 함수 호출 시 값이 들어오지 않는 경우 기본인자 값을 할당합니다.

해당 기능이 있어 메소드 오버로드의 일부를 해결 가능합니다.
> eg. 함수 인자의 구성 개수만 달라지는 경우(타입은 동일)

## Named parameter
```
fun max(a: Int = 0, b: Int = 0) = if (a > b) a else b

fun main() {
    val maxValue = max(a = 6, b = 8)
}
```
네임드 인자는 함수 호출 시 함수 인자를 직접 명시하여 인자를 넘깁니다.

이를 통해 인자의 순서가 바뀌더라도 의도한 순서대로 인자가 넘어갑니다.
> eg. max(b = 8, a = 6)

## Annotation : @JvmOverloads
코틀린 패키지를 자바에서 사용하는 경우 자바에 없는 기본인자 개념 때문에 모든 경우의 오버로딩 메소드를 정의해줘야 한다. 이를 자동으로 생성해주는 어노테이션이 JvmOverloads이다.

> 코틀린과 자바를 함께 사용하는 경우가 아니라면 사용할 필요는 없다.