#include <stdio.h>  
#include <stdlib.h>
#include <math.h> // pow() �Լ� ����� ���� �������z
#include <Windows.h> // system()�Լ� ����� ���� �������
#include <time.h> // clock()�Լ� ����� ���� �������
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
		printf("ī���� ����� �����Ͻÿ� : ");
		scanf("%d", &card_cnt);
		num_cnt = (int)pow(2, card_cnt);
		card = (int *)malloc(sizeof(int)*num_cnt);
		printf("0 ���� %d ������ ������ �ϳ��� �����ϼ���!\n", num_cnt - 1);
		system("pause");
		system("cls");
		int result = 0;
		int card_find;
		int count = 0;
		if (card_cnt < 15) {
			for (int i = 0; i < card_cnt; i++) {
				int n_count = 0;
				printf("��");
				for (int i = 0; i < card_cnt; i++)
					printf("������������������");
				printf("��\n");
				printf("��");
				for (int j = 1; j < num_cnt; j++) {
					if ((j >> i) % 2 == 1) {
						card[j] = j;
						if (n_count == card_cnt) {
							printf("��\n��");
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
				printf("��\n");
				printf("��");
				for (int i = 0; i < card_cnt; i++)
					printf("������������������");
				printf("��\n");
				//end = clock();
				//time_result = end - start;
				//printf("�ɸ��ð� : %lf��\n", time_result / CLOCKS_PER_SEC);
				for (int i = 0; i < card_cnt / 2; i++)
					printf("        ");
				printf("%c", 65 + i);
				printf("\n");
				printf("������ ���ڰ� �ֳ���? �ִٸ� yes(1) ���ٸ� no(0) : ");
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
			// ī�� ����� 15�� �̻��� ���
			int new_num = 15;
			for (int i = 0; i < new_num; i++) {
				int n_count = 0;
				printf("��");
				for (int i = 0; i < new_num; i++)
					printf("������������������");
				printf("��\n");
				printf("��");
				for (int j = 1; j < num_cnt; j++) {
					if ((j >> i) % 2 == 1) {
						card[j] = j;
						if (n_count == new_num) {
							printf("��\n��");
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
				printf("��\n");
				printf("��");
				for (int i = 0; i < new_num; i++)
					printf("��������������������");
				printf("��\n");
				//end = clock();
				//time_result = end - start;
				//printf("�ɸ��ð� : %lf��\n", time_result / CLOCKS_PER_SEC);
				for (int i = 0; i < new_num / 2; i++)
					printf("        ");
				printf("%c", 65 + i);
				printf("\n");
				printf("������ ���ڰ� �ֳ���? �ִٸ� yes(1) ���ٸ� no(0) : ");
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
		printf("����� ������ ���ڴ� %d�Դϴ�.\n", result);
		int x;
		printf("����Ͻðڽ��ϱ�? ����Ϸ��� 1 ���߷��� 0 : ");
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
{                          // �� �� ��  �� �� ��
	int x;
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��      ������      ����      ������   ������    ������       ��\n");
	printf("��      ��  ��  ��    ��      ��    ��      ��       ��        ��      ��       ��\n");
	printf("��      ��  ��  ��    ��      ��    ��               ��        ��               ��\n");
	printf("��      ��  ��  ��    ������    ��  ����       ��        ��               ��\n");
	printf("��      ��  ��  ��    ��      ��    ��      ��       ��        ��      ��       ��\n");
	printf("��      ��  ��  ��    ��      ��    ������   ������    ������       ��\n");
	printf("��                    �ź��� �������迡 ���Ű��� ȯ���մϴ�                     ��\n");
	printf("��                                                                              ��\n");
	printf("��                         1.���ӽ��� 2.���Ӽ���                                ��\n");
	printf("��                         3.������  4.���� ������                              ��\n");
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("�ɼ��� ������ �ּ��� : ");
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
	printf("����������������������������������������������������������������������������������\n");
	for (int i = 0; i < 7; i++)
		printf("��\t\t\t\t\t��\n");
	printf("��         ����ڰ� ������ ���ڸ�        ��\n");
	printf("��      �̻������ ������ �̿��Ͽ�       ��\n");
	printf("��           ���ߴ� �����Դϴ�.          ��\n");
	printf("��     ����ڰ� ī�� ����� �����ϸ�     ��\n");
	printf("��      �ش�Ǵ� ī�带 ����մϴ�.      ��\n");
	printf("��         ����ڰ� ������ ī�带        ��\n");
	printf("��     ���α׷��� ���ߴ� �����Դϴ�.     ��\n");
	for (int i = 0; i < 7; i++)
		printf("��\t\t\t\t\t��\n");
	printf("����������������������������������������������������������������������������������\n");
	int x;
	printf("���� ����� �����ðڽ��ϱ�? (1:���ӽ��� 2:���ӳ�����)");
	scanf("%d", &x);
	if (x == 1)
		start_game();
	else
		return 0;
}
void print_maker() {
	system("cls");
	printf("����������������������������������������������������������������������������������\n");
	printf("��   ============= ������ =============  ��\n");
	printf("��           �б� : ��õ����б�         ��\n");
	printf("��    ���� : ��ǻ�ͼ���Ʈ������а�      ��\n");
	printf("��             �̸� : ��ο�             ��\n");
	printf("��             �й� : 20194024           ��\n");
	printf("��             ���� : �̻����           ��\n");
	printf("��        ��� ���� : �ڵμ� ������      ��\n");
	printf("����������������������������������������������������������������������������������\n");
	int x;
	printf("���� ����� �����ðڽ��ϱ�? (1:���ӽ��� 2:���ӳ�����)");
	scanf("%d", &x);
	if (x == 1)
		start_game();
	else
		return 0;
}
