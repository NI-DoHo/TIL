# 변수 선언과 정의

코틀린에서 변수를 선얼할 때 사용하는 키워드에 크게 두 가지가 있다.
* __val__
* __var__


## val
val 키워드는 value의 약어로 자바의 final 키워드로 선언된 상수이다.
```
val foo = 42
```
val 키워드로 선언된 변수는 read-only, assigned-once로 동작한다.

## var
var 키워드는 variable의 약어로 일반적인 수정 가능한 변수이다.
```
var foo = 0
foo = 42
```

프로그래밍이 런타임 중에 변하는 데이터를 저장하고자 한다면 var 키워드를 사용한다.

## Recommendation rule of variable declare
변수를 선언할 때 기본 val을 통해 선언한다.

소스 코드 작성 시 사이드 이펙트를 줄이고 문맥 이해에 도움이 되어 결과적으로 유지보수가 쉬워진다.

## Pop Quiz
```
val foo = ...
const val foo = ...
```

Q. 위 선언된 두 변수의 차이는 무엇인가?

> 첫 번째 경우 프로그램이 런타임 중에 실행되며 값이 할당되는 반면에 두 번째 경우는 빌드 타임에서 변수에 값이 할당된다.

> 때문에 const 키워드를 사용하여 선언하는 변수의 경우 primitive 혹은 String 타입의 데이터만 들어갈 수 있으며 함수의 값을 리턴 받거나 class 생성자를 통한 데이터 할당이 불가하다.

```
var foo = 42
foo = "The answer is 42"
println(foo)
```

Q. 위의 코드의 빌드 결과는?

> 컴파일 에러, 코틀린 코드를 작성할 때 타입을 생략해도 되지만 런타임 중에 타입이 정해지고 변하는 파이썬에 반해 코틀린은 빌드타임에 변수의 타입이 정해지고 런타임 중 타입이 변하지 않는다.

> Duck typing 언어이긴 하지만 하나의 변수에는 한 가지 종류의 타입만 담을 수 있다.

```
class foo {
    var data: Int

    constructor(data: Int) {
        this.data = data
    }
}

fun main () {
    val foobar = foo(0)

    foobar.data = 42

    println(foobar.data)
}
```

Q. 위 코드의 실행 결과는?

> 위 코드의 실행 결과는 42다. 문제에서 확인하고자 하는 것은 val로 선언된 오브젝트의 멤버 변수를 수정할 수 있는냐이다.

> 정답은 val로 선언된 오브젝트의 멤버 변수는 수정할 수 있다이며 val로 선언된 것은 오브젝트 자체이지 오브젝트 내에 포함된 멤버 변수까지 영향을 주지 않는다. 또한, 멤버 변수의 수정가능 유무는 멤버 변수를 선언할 때 사용한 키워드이다. val data가 아닌 var data로 선언했기 때문에 수정이 가능하다.

## NOTE
Array, ArrayList, List, MutableList
* 차이점
* 성능