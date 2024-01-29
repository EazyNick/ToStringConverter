#pragma once

#include <string>
#include <sstream>
#include <vector>

class ToStringConverter {
public:
    // 정수형(int)을 문자열로 변환
    std::string convert(int value) {
        return std::to_string(value);
    }

    // 부동 소수점형(float)을 문자열로 변환
    std::string convert(float value) {
        return std::to_string(value);
    }

    // 더블형(double)을 문자열로 변환
    std::string convert(double value) {
        return std::to_string(value);
    }

    // 문자(char)를 문자열로 변환
    std::string convert(char value) {
        return std::string(1, value);
    }

    // C 스타일 문자열(const char*)을 문자열로 변환
    std::string convert(const char* value) {
        return std::string(value);
    }

    // 이미 문자열인 경우 (std::string)
    std::string convert(const std::string& value) {
        return value;
    }
    // 템플릿 함수 : 하나의 함수 정의를 사용하여 다양한 타입에 대해 같은 기능을 수행하는 함수를 생성
    // T는 플레이스홀더, T에는 다양한 값을 호출 받을 수 있다.
    template <typename T>
    // std::vector<T> 타입의 객체를 입력받아 std::string 타입으로 변환하는 함수
    // 참조로서 벡터를 전달받음
    // const는 이 벡터가 함수에 의해 수정되지 않음을 보장
    std::string convert(const std::vector<T>& vec) {
        std::stringstream ss; // 문자열 스트림 객체 ss를 생성
        // vec의 각 요소를 순회
        for (size_t i = 0; i < vec.size(); ++i) {
            // 벡터의 i번째 요소를 문자열 스트림 ss에 추가
            ss << vec[i];
            // 조건문은 마지막 요소가 아닐 경우에만 참
            if (i < vec.size() - 1) {
                ss << " "; // 요소 사이에 공백을 추가
            }
        }
        return ss.str();
    }

    // n차원
    template <typename T>
    std::string convert(const std::vector<std::vector<T>>& matrix) {
        std::stringstream ss;\
        // matrix라는 2차원 벡터의 각 행을 순회
        // auto 키워드는 컴파일러가 자동으로 row의 타입을 추론하게 함
        // row는 std::vector<T> 타입의 참조(reference)
        for (const auto& row : matrix) {
            // element는 row의 각 요소
            // const와 &(참조자)는 element가 원본 벡터의 각 요소를 복사하지 않고 참조만 함을 의미
            for (const auto& element : row) {
                ss << element << " ";
            }
            ss << "\n"; // 각 행이 끝날 때마다 줄바꿈 추가
        }
        return ss.str();
    }

};
