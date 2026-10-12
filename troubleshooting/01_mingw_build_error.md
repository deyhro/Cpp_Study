# MinGW-w64 C++ 빌드 실패 해결

## 1. 문제 상황

VS Code에서 C++ 파일 실행 시 빌드 작업이 실패함.

### 오류 메시지

```text
The preLaunchTask 'C/C++: g++.exe build active file'
terminated with exit code -1.

ld.exe: cannot open output file
No such file or directory
```

---

## 2. 원인 분석

1. `tasks.json`의 g++ 컴파일러 경로 확인
2. `Ctrl + Shift + B`로 빌드 작업 단독 실행
3. 링커(`ld.exe`)가 실행 파일을 생성하지 못하는 현상 확인
4. 프로젝트 경로에 포함된 한글이 깨져 출력되는 현상 발견

**추정 원인:** MinGW-w64 도구의 한글 경로 처리 문제

---

## 3. 해결 방법

프로젝트 경로를 영문으로 변경함.

**변경 전**

```text
C:\Users\<사용자명>\Desktop\<한글 경로명>\Cpp_Study
```

**변경 후**

```text
C:\Users\<사용자명>\Desktop\Cpp_Study
```

기존 `tasks.json`은 `${fileDirname}`을 사용하므로 별도 수정 없이 빌드를 재시도함.

---

## 4. 해결 결과

- C++ 빌드 정상 완료
- 실행 파일(`.exe`) 생성 성공
- 프로그램 실행 성공

---

## 5. 배운 점

- 컴파일 오류와 링커 오류는 구분해서 확인해야 한다.
- VS Code의 Problems 탭에 오류가 없더라도 빌드 작업이 실패할 수 있다.
- MinGW-w64 환경에서는 한글 경로로 인한 호환성 문제가 발생할 수 있다.
- 개발 프로젝트 경로를 영문으로 관리하면 경로 관련 오류를 예방하는 데 도움이 된다.
