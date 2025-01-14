#include <stdio.h>
#include <string.h>

int main() {
    double num1, num2, result;
    char operator;
    char input[50]; // ユーザー入力を保存するバッファ

    printf("電卓アプリ\n");
    printf("使用可能な演算子: +, -, *, /\n");
    printf("計算を続ける場合は式を入力してください (例: 81.92 + 19.05)。終了するには 'exit' と入力してください。\n");

    while (1) {
        printf("\n式を入力してください: ");
        // ユーザー入力を取得
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("入力エラーです。\n");
            continue;
        }

        // "exit" が入力されたらプログラム終了
        if (strncmp(input, "exit", 4) == 0) {
            printf("プログラムを終了します。\n");
            break;
        }

        // 入力を解析して計算
        if (sscanf_s(input, "%lf %c %lf", &num1, &operator, 1, &num2) != 3) {
            printf("入力が正しくありません。例: 81.92 + 19.05\n");
            continue;
        }

        // 演算を実行
        switch (operator) {
        case '+':
            result = num1 + num2;
            printf("結果: %.2lf\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("結果: %.2lf\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("結果: %.2lf\n", result);
            break;
        case '/':
            if (num2 == 0) {
                printf("エラー: 0で割ることはできません。\n");
            }
            else {
                result = num1 / num2;
                printf("結果: %.2lf\n", result);
            }
            break;
        default:
            printf("エラー: 無効な演算子です。\n");
        }
    }

    return 0;
}