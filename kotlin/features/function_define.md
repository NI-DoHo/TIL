# 함수 선언과 정의

## Function declare
함수를 선언할 때는 아래와 같은 룰을 따른다
```
fun max(arg1: Int, arg2: Int): Int {
    return if (arg1 > arg2) arg1 else arg2
}
```
- fun 키워드로 함수 선언문을 시작하고 함수의 이름을 정의한다.
- () 안에는 함수의 인자를 정의하고 : 뒤에 함수의 반환 데이터 형을 정의한다.
- {} 안에 함수의 동작을 정의한다.

## Block body
일반적으로 함수를 정의할 때 아래와 같이 사용한다.
```
fun foo(arg: Int): Int {
    ...
    return
}
```

{}로 묶인 부분을 Block body라고 한다.

## Expression body
Block body외에도 함수 정의가 하나의 표현으로 가능하다면 아래와 같이 사용할 수 있다.
```
fun max(a: Int, b: Int) = if(a > b) a else b
```

이를 Expression body라고 하는데 코틀린 코딩 룰에서는 가급적 사용하지 않고 __하나의 표현으로 가능한 경우__ 사용하는 것을 권장한다.

## Kind of functions (일부만 소개)
### Top-level function 
- 코틀린 패키지에 있는 함수로 어떠한 클래스에도 속하지 않는 함수
> checkUserStatue()
```
package com.chikekotlin.projectx.utils
 
fun checkUserStatus(): String {
    return "online"
}

class foo {
    ...
}
```
### Member function
- 클래스, 오브젝트, 인터페이스에 선언 및 정의된 함수
> calculateArea()
```
class Circle {
 
    fun calculateArea(radius: Double): Double {
        require(radius > 0, { "Radius must be greater than 0" })
        return Math.PI * Math.pow(radius, 2.0)
    }
}
```
### Local function (nested function)
- 다른 함수 안에 선언 및 정의된 함수
> calCircumference(), calArea()
```
fun printCircumferenceAndArea(radius: Double): Unit {
 
    fun calCircumference(radius: Double): Double = (2 * Math.PI) * radius
    val circumference = "%.2f".format(calCircumference(radius))
 
    fun calArea(radius: Double): Double = (Math.PI) * Math.pow(radius, 2.0)
    val area = "%.2f".format(calArea(radius))
 
    print("Circle circumference of $radius radius is $circumference and area is $area")
}
```

## Annotation : @JvmName
JvmName 어노테이션은 top-level 메소드를 포함하는 클래스의 JVM 이름을 변경합니다.


## Pop Quiz
Q. 함수를 선언할 때 인자는 val일까 var일까?

> 코틀린 버전 M5.1 이후 함수 인자 앞에 var, val을 명시하는 것이 불가능해졌다.

> Call by value와 Call by reference 개념에서 온 혼란이었는데 당시 코틀린 런타임에서 지원하지 않는 Call by ref로 생각하는 사용자들이 있었고 이후 함수 인자는 val 즉, Immutable 타입으로 전달돼 인자 값 수정을 시도하면 컴파일 에러가 발생한다.

Ref
- Frequently used annotations in kotlin : https://codechacha.com/ko/kotlin-annotations/

- Kotlin M5.1 release : https://blog.jetbrains.com/kotlin/2013/02/kotlin-m5-1/?_ga=2.257342668.697035720.1580573960-1708821275.1580397269