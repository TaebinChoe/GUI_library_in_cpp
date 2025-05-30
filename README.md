# GUI Library in C++

Java의 GUI 라이브러리 구조를 모티브로 하여 C++로 직접 구현한 GUI 프레임워크입니다.  
객체지향적 설계 원칙과 디자인 패턴을 실제 프로젝트에 적용해보기 위해,  
1학년 2학기 **객체지향 프로그래밍 2** 강의의 기말 프로젝트로 진행되었습니다.

---

## 프로젝트 개요

- **목표**: 객체지향적 설계 원칙과 디자인 패턴을 실제 코드에 적용해 보기
- **언어**: C++
- **진행 시기**: 대학 1학년 2학기 기말 프로젝트
- **주요 구현 내용**:
  - Java의 `Swing` 구조를 참고한 **GUI 컴포넌트 시스템**
  - 직접 구현한 라이브러리를 이용하여 **그림판(Paint)**, **계산기(Calculator)** 등 간단한 GUI 응용프로그램 제작
  - **Composite Pattern**을 활용한 컴포넌트 그룹핑 기능
  - **테스트 기반 개발 방식**으로 점진적인 기능 확장
  - **자료구조 또한 STL 없이 직접 구현**하여 기초 역량 강화

---

## 주요 기능 및 기술

| 기능 | 설명 |
|------|------|
| GUI 컴포넌트 시스템 | 버튼, 레이블, 패널 등의 기본 요소 직접 구현 |
| 그림판, 계산기 구현 | 자체 GUI 프레임워크 기반의 예제 앱 |
| Composite Pattern | 컨테이너-컴포넌트 구조 구현에 사용 |
| 객체지향 설계 | 상속, 다형성, 캡슐화 등 OOP 원칙 중심 |
| 점진적 개발 | 테스트 → 리팩토링 → 확장 형태의 반복적 개발 |

---

## 배운 점

- GUI와 같은 복잡한 구조일수록 **디자인 패턴의 필요성**을 체감함
- 프로젝트가 커질수록 **작고 반복적인 테스트와 확장**이 중요하다는 것을 느낌
- 추상화와 인터페이스 분리를 통해 **유지보수와 확장성**이 좋아진다는 경험
