/*
 * rps.c - Rock-Paper-Scissors game for Linux
 * 实现人机对战的剪刀石头布游戏，支持输入验证和结果判断
 *
 * 作者：你的名字
 * 版本：1.0
 * 日期：2026-06-05
 * 编译：gcc -o rps rps.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
/*
 * get_user_gesture - 获取用户输入的手势
 *
 * 提示用户输入0-2的数字，验证输入合法性
 * 返回值：0=剪刀，1=石头，2=布，-1=输入无效
 */
int get_user_gesture(void)
{
	int ret, input;

	printf("\nInput your gesture (0-scissor 1-stone 2-cloth):\n");
	ret = scanf("%d", &input);
	if (ret != 1 || input < 0 || input > 2) {
		printf("Invalid input! Please input 0, 1 or 2.\n");
		// 清空输入缓冲区，避免非数字输入导致无限循环
		while (getchar() != '\n');
		return -1;
	}

	return input;
}

/*
 * get_computer_gesture - 生成电脑的随机手势
 *
 * 返回值：0=剪刀，1=石头，2=布
 */
int get_computer_gesture(void)
{
	return rand() % 3;
}

/*
 * judge_result - 判断比赛结果
 * @user: 用户的手势（必须是0-2）
 * @computer: 电脑的手势（必须是0-2）
 *
 * 根据剪刀石头布的规则判断胜负
 * 返回值：1=用户赢，0=平局，-1=用户输
 */
int judge_result(const int user, const int computer)
{
    // 断言参数在合法范围内，开发阶段会捕获非法调用
    assert(user >= 0 && user <= 2);
    assert(computer >= 0 && computer <= 2);

    return (user - computer + 4) % 3 - 1;
}
int main(void)
{


	const char gesture[3][10] = { "scissor", "stone", "cloth" };
	int user, computer, result;
        // 尝试修改手势映射表，编译器会报错

	srand(time(NULL));

	while (1) {
		user = get_user_gesture();
		if (user == -1)
			continue;

		computer = get_computer_gesture();

		printf("Your gesture: %s\tComputer's gesture: %s\n",
		       gesture[user], gesture[computer]);

		result = judge_result(user, computer);
		if (result > 0)
			printf("You win!\n");
		else if (result == 0)
			printf("Draw!\n");
		else
			printf("You lose!\n");
	}

	return 0;
}
