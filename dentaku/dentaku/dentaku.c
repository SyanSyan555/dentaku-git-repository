#include <stdio.h>
#include <string.h>

int main() {
    double num1, num2, result;
    char operator;
    char input[50]; // ���[�U�[���͂�ۑ�����o�b�t�@

    printf("�d��A�v��\n");
    printf("�g�p�\�ȉ��Z�q: +, -, *, /\n");
    printf("�v�Z�𑱂���ꍇ�͎�����͂��Ă������� (��: 81.92 + 19.05)�B�I������ɂ� 'exit' �Ɠ��͂��Ă��������B\n");

    while (1) {
        printf("\n������͂��Ă�������: ");
        // ���[�U�[���͂��擾
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("���̓G���[�ł��B\n");
            continue;
        }

        // "exit" �����͂��ꂽ��v���O�����I��
        if (strncmp(input, "exit", 4) == 0) {
            printf("�v���O�������I�����܂��B\n");
            break;
        }

        // ���͂���͂��Čv�Z
        if (sscanf_s(input, "%lf %c %lf", &num1, &operator, 1, &num2) != 3) {
            printf("���͂�����������܂���B��: 81.92 + 19.05\n");
            continue;
        }

        // ���Z�����s
        switch (operator) {
        case '+':
            result = num1 + num2;
            printf("����: %.2lf\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("����: %.2lf\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("����: %.2lf\n", result);
            break;
        case '/':
            if (num2 == 0) {
                printf("�G���[: 0�Ŋ��邱�Ƃ͂ł��܂���B\n");
            }
            else {
                result = num1 / num2;
                printf("����: %.2lf\n", result);
            }
            break;
        default:
            printf("�G���[: �����ȉ��Z�q�ł��B\n");
        }
    }

    return 0;
}