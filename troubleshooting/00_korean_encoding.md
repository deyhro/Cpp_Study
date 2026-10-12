
# VS Code C++ 터미널 한글 깨짐 해결

## 1. 문제 상황

VS Code에서 C++ 프로그램 실행 시 `cout`으로 출력한 한글이 정상적으로 표시되지 않고 깨지는 현상이 발생함.

**문제 예시**

```cpp
cout << "정수를 입력하세요: ";
```

**예상 출력**

```text
정수를 입력하세요:
```

**실제 현상**

한글이 알아볼 수 없는 문자로 출력됨.

---

## 2. 원인 분석

1. C++ 코드 자체에는 문제가 없는 것을 확인
2. VS Code 내부 터미널에서 한글 출력이 깨지는 현상 확인
3. Windows 터미널의 코드 페이지와 소스 파일의 문자 인코딩이 일치하지 않을 가능성 확인
4. 터미널의 코드 페이지를 UTF-8로 변경하여 정상 출력되는 것을 확인

**원인:** 터미널의 문자 인코딩 설정 문제

Windows 콘솔은 환경에 따라 UTF-8이 아닌 다른 코드 페이지를 사용할 수 있으며, UTF-8로 저장된 소스 파일의 한글 출력과 호환되지 않을 수 있음.

---

## 3. 해결 방법

### 3-1. 터미널 코드 페이지 변경

VS Code 내부 터미널에서 다음 명령어 실행

```powershell
chcp 65001
```

- `chcp`: Windows 콘솔의 코드 페이지를 확인하거나 변경하는 명령어
- `65001`: UTF-8 코드 페이지

명령어 실행 후 C++ 프로그램의 한글이 정상적으로 출력되는 것을 확인함.

### 3-2. VS Code 터미널 기본 설정 변경

새로운 터미널을 열 때마다 `chcp 65001`을 입력하는 불편함을 해결하기 위해 `settings.json` 수정

**파일명: `settings.json`**

```json
{
    "terminal.integrated.profiles.windows": {
        "PowerShell": {
            "source": "PowerShell",
            "args": ["-NoExit", "-Command", "chcp 65001 > $null"],
            "icon": "terminal-powershell"
        },
        "Command Prompt": {
            "path": [
                "${env:windir}\\Sysnative\\cmd.exe",
                "${env:windir}\\System32\\cmd.exe"
            ],
            "args": ["/K", "chcp 65001 > nul"],
            "icon": "terminal-cmd"
        }
    },
    "terminal.integrated.defaultProfile.windows": "PowerShell"
}
```

**설정 설명**

| 설정 | 역할 |
|---|---|
| `-NoExit` | PowerShell 명령 실행 후 터미널 유지 |
| `-Command` | PowerShell에서 명령어 실행 |
| `/K` | CMD 명령 실행 후 터미널 유지 |
| `chcp 65001` | 콘솔 코드 페이지를 UTF-8로 변경 |
| `> $null`, `> nul` | 명령어 실행 결과 출력 숨김 |
| `defaultProfile.windows` | 기본 터미널 지정 |

---

## 4. 해결 결과

- C++ 프로그램의 한글 출력 정상화
- PowerShell과 CMD에서 UTF-8 코드 페이지 자동 적용 설정
- 매번 `chcp 65001`을 입력할 필요가 없도록 개선

**확인 명령어**

```powershell
chcp
```

**정상 출력 예시**

```text
Active code page: 65001
```

---

## 5. 배운 점

- 프로그램 코드에 문제가 없어도 실행 환경에 따라 출력 오류가 발생할 수 있다.
- UTF-8은 한글을 포함한 다양한 문자를 표현할 수 있는 문자 인코딩 방식이다.
- `chcp 65001`을 사용하면 Windows 콘솔의 코드 페이지를 UTF-8로 변경할 수 있다.
- VS Code의 `settings.json`을 이용하면 터미널 실행 환경을 설정할 수 있다.
- 터미널 출력 인코딩 문제와 컴파일 과정에서 발생하는 한글 경로 문제는 구분해야 한다.

> **참고:** 해당 설정은 VS Code에서 새로 생성하는 터미널에 적용되며, Windows 전체의 문자 인코딩을 변경하는 것은 아니다.
