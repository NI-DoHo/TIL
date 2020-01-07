# 코틀린 커맨드 라인에서 컴파일하기

Ref. : https://kotlinlang.org/docs/tutorials/command-line.html

### Compile source file to runnable binary
```
$ kotlinc hello.kt -include-runtime -d hello.jar
```

- *-d* 옵션은 컴파일 결과로 출력되는 파일의 경로를 나타낸다. (디렉토리 경로 혹은 파일의 경로가 될 수 있다)
- *-incude-runtime* 을 추가하여 kotlin 런타임을 포함한 실행가능한 .jar 파일을 생성한다.

### Launch .jar file, contain kotlin runtime
```
$ java -jar hello.jar
```

- 위 명령어를 통해 kotlin 런타임을 포함한 .jar 파일을 실행할 수 있다.

### Compile source file to library
```
$ kotlinc hello.kt -d hello.jar
```

- *-include-runtime* 옵션 없이 컴파일 하면 kotlin 애플리케이션에서 사용할 수 있는 라이브러리 형태의 .jar 파일을 생성한다.

### Launch .jar file, compiled by library
```
$ kotlin -classpath hello.jar HelloKt
```

- *-classpath* 옵션은 .jar 파일에서 사용자 클래스를 찾는다.
- HelloKt는 hello.kt를 컴파일할 때 생성된 main 클래스 이름이다.
- vi를 통해 jar 파일을 열어보면 jar 파일이 담고 있는 정보들을 볼 수 있다.
- 위 명령어를 통해 kotlin 런타임을 포함하지 않는 .jar 파일을 실행할 수 있다.

### NOTE

- 컴파일 시 class 이름은 소스파일 이름에 의해 결정되더라 그렇다면 소스파일 하나에 여러 클래스가 있다면 어떨까?
- 소스파일 이름이 hello.kt라면 클래스 이름은 HelloKt가 되고 hello_wolrd.kt라면 Hello_wolrdKt가 되더라 (.jar 파일을 열어 확인한 내용)
