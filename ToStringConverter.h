#pragma once

#include <string>
#include <sstream>
#include <vector>

class ToStringConverter {
public:
    // ������(int)�� ���ڿ��� ��ȯ
    std::string convert(int value) {
        return std::to_string(value);
    }

    // �ε� �Ҽ�����(float)�� ���ڿ��� ��ȯ
    std::string convert(float value) {
        return std::to_string(value);
    }

    // ������(double)�� ���ڿ��� ��ȯ
    std::string convert(double value) {
        return std::to_string(value);
    }

    // ����(char)�� ���ڿ��� ��ȯ
    std::string convert(char value) {
        return std::string(1, value);
    }

    // C ��Ÿ�� ���ڿ�(const char*)�� ���ڿ��� ��ȯ
    std::string convert(const char* value) {
        return std::string(value);
    }

    // �̹� ���ڿ��� ��� (std::string)
    std::string convert(const std::string& value) {
        return value;
    }
    // ���ø� �Լ� : �ϳ��� �Լ� ���Ǹ� ����Ͽ� �پ��� Ÿ�Կ� ���� ���� ����� �����ϴ� �Լ��� ����
    // T�� �÷��̽�Ȧ��, T���� �پ��� ���� ȣ�� ���� �� �ִ�.
    template <typename T>
    // std::vector<T> Ÿ���� ��ü�� �Է¹޾� std::string Ÿ������ ��ȯ�ϴ� �Լ�
    // �����μ� ���͸� ���޹���
    // const�� �� ���Ͱ� �Լ��� ���� �������� ������ ����
    std::string convert(const std::vector<T>& vec) {
        std::stringstream ss; // ���ڿ� ��Ʈ�� ��ü ss�� ����
        // vec�� �� ��Ҹ� ��ȸ
        for (size_t i = 0; i < vec.size(); ++i) {
            // ������ i��° ��Ҹ� ���ڿ� ��Ʈ�� ss�� �߰�
            ss << vec[i];
            // ���ǹ��� ������ ��Ұ� �ƴ� ��쿡�� ��
            if (i < vec.size() - 1) {
                ss << " "; // ��� ���̿� ������ �߰�
            }
        }
        return ss.str();
    }

    // n����
    template <typename T>
    std::string convert(const std::vector<std::vector<T>>& matrix) {
        std::stringstream ss;\
        // matrix��� 2���� ������ �� ���� ��ȸ
        // auto Ű����� �����Ϸ��� �ڵ����� row�� Ÿ���� �߷��ϰ� ��
        // row�� std::vector<T> Ÿ���� ����(reference)
        for (const auto& row : matrix) {
            // element�� row�� �� ���
            // const�� &(������)�� element�� ���� ������ �� ��Ҹ� �������� �ʰ� ������ ���� �ǹ�
            for (const auto& element : row) {
                ss << element << " ";
            }
            ss << "\n"; // �� ���� ���� ������ �ٹٲ� �߰�
        }
        return ss.str();
    }

};
