#include <stdio.h>  
#include <stdlib.h>
#include <math.h> // pow() 함수 사용을 위한 헤더파일z
#include <Windows.h> // system()함수 사용을 위한 헤더파일
#include <time.h> // clock()함수 사용을 위한 헤더파일
#pragma warning(disable:4996)
void print_start();
void start_game();
void print_explain();
void print_maker();
int main() {
	print_start();
	return 0;
}
void start_game() {
	int *card;
	int card_cnt, num_cnt;
	char c;
	// double start, end, time_result;
	while (1) {
		system("cls");
		printf("카드의 장수를 선택하시오 : ");
		scanf("%d", &card_cnt);
		num_cnt = (int)pow(2, card_cnt);
		card = (int *)malloc(sizeof(int)*num_cnt);
		printf("0 부터 %d 까지의 숫자중 하나를 생각하세요!\n", num_cnt - 1);
		system("pause");
		system("cls");
		int result = 0;
		int card_find;
		int count = 0;
		if (card_cnt < 15) {
			for (int i = 0; i < card_cnt; i++) {
				int n_count = 0;
				printf("┏");
				for (int i = 0; i < card_cnt; i++)
					printf("━━━━━━━━━");
				printf("┓\n");
				printf("┃");
				for (int j = 1; j < num_cnt; j++) {
					if ((j >> i) % 2 == 1) {
						card[j] = j;
						if (n_count == card_cnt) {
							printf("┃\n┃");
							n_count = 0;
						}
						printf("%8d ", card[j]);
						n_count++;
					}
				}
				for (int i = 0; i < card_cnt - ((num_cnt / 2) % card_cnt); i++) {
					if (n_count - card_cnt == 0)
						break;
					printf("         ");
				}
				printf("┃\n");
				printf("┗");
				for (int i = 0; i < card_cnt; i++)
					printf("━━━━━━━━━");
				printf("┛\n");
				//end = clock();
				//time_result = end - start;
				//printf("걸린시간 : %lf초\n", time_result / CLOCKS_PER_SEC);
				for (int i = 0; i < card_cnt / 2; i++)
					printf("        ");
				printf("%c", 65 + i);
				printf("\n");
				printf("생각한 숫자가 있나요? 있다면 yes(1) 없다면 no(0) : ");
				scanf("%d", &card_find);
				if (card_find == 1) {
					result += (int)pow(2, count);
					count++;
				}
				else
					count++;
				system("cls");
				n_count = 0;
			}
		}
		else {
			// 카드 장수가 15장 이상인 경우
			int new_num = 15;
			for (int i = 0; i < new_num; i++) {
				int n_count = 0;
				printf("┏");
				for (int i = 0; i < new_num; i++)
					printf("━━━━━━━━━");
				printf("┓\n");
				printf("┃");
				for (int j = 1; j < num_cnt; j++) {
					if ((j >> i) % 2 == 1) {
						card[j] = j;
						if (n_count == new_num) {
							printf("┃\n┃");
							n_count = 0;
						}
						printf("%9d ", card[j]);
						n_count++;
					}
				}
				for (int i = 0; i < new_num - n_count; i++) {
					if (n_count - new_num == 0)
						break;
					printf("          ");
				}
				printf("┃\n");
				printf("┗");
				for (int i = 0; i < new_num; i++)
					printf("━━━━━━━━━━");
				printf("┛\n");
				//end = clock();
				//time_result = end - start;
				//printf("걸린시간 : %lf초\n", time_result / CLOCKS_PER_SEC);
				for (int i = 0; i < new_num / 2; i++)
					printf("        ");
				printf("%c", 65 + i);
				printf("\n");
				printf("생각한 숫자가 있나요? 있다면 yes(1) 없다면 no(0) : ");
				scanf("%d", &card_find);
				if (card_find == 1) {
					result += (int)pow(2, count);
					count++;
				}
				else
					count++;
				system("cls");
				n_count = 0;
			}
		}
		printf("당신이 생각한 숫자는 %d입니다.\n", result);
		int x;
		printf("계속하시겠습니까? 계속하려면 1 멈추려면 0 : ");
		scanf("%d", &x);
		if (x == 1)
			continue;
		else {
			free(card);
			return;
		}
	}
}
void print_start()
{                          // ┏ ┃ ━  ┓ ┗ ┛
	int x;
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃      ■■■■■      ■■■      ■■■■■   ■■■■■    ■■■■■       ┃\n");
	printf("┃      ■  ■  ■    ■      ■    ■      ■       ■        ■      ■       ┃\n");
	printf("┃      ■  ■  ■    ■      ■    ■               ■        ■               ┃\n");
	printf("┃      ■  ■  ■    ■■■■■    ■  ■■■       ■        ■               ┃\n");
	printf("┃      ■  ■  ■    ■      ■    ■      ■       ■        ■      ■       ┃\n");
	printf("┃      ■  ■  ■    ■      ■    ■■■■■   ■■■■■    ■■■■■       ┃\n");
	printf("┃                    신비한 마술세계에 오신것을 환영합니다                     ┃\n");
	printf("┃                                                                              ┃\n");
	printf("┃                         1.게임시작 2.게임설명                                ┃\n");
	printf("┃                         3.제작자  4.게임 나가기                              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("옵션을 선택해 주세요 : ");
	scanf("%d", &x);
	if (x == 1)
		start_game();
	else if (x == 2)
		print_explain();
	else if (x == 3)
		print_maker();
	else
		return 0;
}			// system("mode con:cols=100 lines=10");
void print_explain() {
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	for (int i = 0; i < 7; i++)
		printf("┃\t\t\t\t\t┃\n");
	printf("┃         사용자가 생각한 숫자를        ┃\n");
	printf("┃      이산수학의 원리를 이용하여       ┃\n");
	printf("┃           맞추는 게임입니다.          ┃\n");
	printf("┃     사용자가 카드 장수를 선택하면     ┃\n");
	printf("┃      해당되는 카드를 출력합니다.      ┃\n");
	printf("┃         사용자가 생각한 카드를        ┃\n");
	printf("┃     프로그램이 맞추는 게임입니다.     ┃\n");
	for (int i = 0; i < 7; i++)
		printf("┃\t\t\t\t\t┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	int x;
	printf("마술 세계로 떠나시겠습니까? (1:게임시작 2:게임나가기)");
	scanf("%d", &x);
	if (x == 1)
		start_game();
	else
		return 0;
}
void print_maker() {
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃   ============= 제작자 =============  ┃\n");
	printf("┃           학교 : 순천향대학교         ┃\n");
	printf("┃    전공 : 컴퓨터소프트웨어공학과      ┃\n");
	printf("┃             이름 : 김민욱             ┃\n");
	printf("┃             학번 : 20194024           ┃\n");
	printf("┃             과목 : 이산수학           ┃\n");
	printf("┃        담당 교수 : 박두순 교수님      ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	int x;
	printf("마술 세계로 떠나시겠습니까? (1:게임시작 2:게임나가기)");
	scanf("%d", &x);
	if (x == 1)
		start_game();
	else
		return 0;
}
