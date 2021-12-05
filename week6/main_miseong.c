#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <cType.h>
#include <stdbool.h>
#include "P5-16.h"
#include "linkListADT.h"


void printInstr(void);
LIST* buildList(void);
void process(LIST* list);
char getChoice(void);
void printList(LIST* list);
void search(LIST* list);

int cmpYear(void* pYear1, void* pYear2);

int main(void)
{
	LIST* list;

	printInstr(); //인트로 출력
	list = buildList();
	process(list);

	printf("End Best Pictures\n"
		"Hope you found your favorite!\n");
	return 0;
}

void printInstr(void)
{
	printf("This program prints the Academy Awards \n"
		"Best Picture of the Year and its director.\n"
		"the rest. Enjoy.\n");
	return;
}

LIST* buildList(void)
{
	FILE* fpData1, * fpData2;
	LIST* list;

	short yearIn;
	int addResult;

	PICTURE* pPic;

	list = createList(cmpYear);
	if (!list) //리스트 생성X
		printf("\aCannot create list\n"),
		exit(100);
	fpData1 = fopen("input.txt", "r");
	if (!fpData1) //파일이 존재X
		printf("\aError opening input file\n"),
		exit(110);

	fpData2 = fopen("pictures.dat", "wb");
	if (fpData2 == NULL)
	{
		printf("\aError opening input file\n"),
			exit(110);
	}

	while (fscanf(fpData1, "%hd", &yearIn) == 1) //fpData1에서 읽을 short형 자료형이 있고 읽기에 성공하면 아래 실행
	{
		pPic = (PICTURE*)malloc(sizeof(PICTURE));

		if (!(pPic)) //pPic 생성되지 X = 메모리 할당에 실패했을 경우
			printf("\aOut of Memory in build list\n"),
			exit(100);

		pPic->year = yearIn;
		fwrite(&yearIn, sizeof(short), 1, fpData2);

		//Skip tabs and quote
		while ((fgetc(fpData1)) != '\t')
			;
		while ((fgetc(fpData1)) != '"')
			;
		fscanf(fpData1, " %40[^\"], %*c", pPic->picture); //%[*][width][modifiers]type
		fwrite(pPic->picture, sizeof(pPic->picture), 1, fpData2);
		while ((fgetc(fpData1)) != '\t')
			;
		while ((fgetc(fpData1)) != '"')
			;
		fscanf(fpData1, " %40[^\"], %*c", pPic->director);
		fwrite(pPic->director, sizeof(pPic->director), 1, fpData2);

		//Insert into list
		addResult = addNode(list, pPic);
		if (addResult != 0)
			if (addResult == -1)
				printf("Memory overflow adding movie\a\n"),
				exit(120);
			else
				printf("Duplicate year %hd not added\n\a",
					pPic->year);
		while (fgetc(fpData1) != '\n')
			;
	}
	fclose(fpData2);
	return list;
}

void process(LIST* list)
{
	char choice;

	do
	{
		choice = getChoice();

		switch (choice)
		{
		case 'P': printList(list);
			break;
		case 'S': search(list);
		case 'Q': break;
		}
	} while (choice != 'Q');
	return;
}

char getChoice(void)
{
	char choice;
	bool valid;

	printf("======= MENU ======= \n"
		"Hear are your choices:\n"
		" S: search for a year\n"
		" P: Print all years\n"
		" Q: Quit \n\n"
		"Enter your choice:");

	do
	{
		scanf("%c", &choice);
		choice = toupper(choice); //<cType.h> 내장 함수, 소문자->대문자로 변환해줌
		switch (choice)
		{
		case 'S':
		case 'P':
		case 'Q': valid = true;
			break;
		default: valid = false;
			printf("\aInvalid choice\n"
				"Please try again: ");
			break;
		}
	} while (!valid);
	return choice;
}

void printList(LIST* list)
{
	PICTURE* pPic;

	if (listCount(list) == 0)
		printf("Sorry, nothing in list\n\a");
	else
	{
		printf("\nBest Pictures List\n");
		traverse(list, 0, (void**)&pPic);
		do
		{
			printf("%hd %-40s %s\n",
				pPic->year, pPic->picture,
				pPic->director);
		} while (traverse(list, 1, (void**)&pPic));
	}
	printf("End of Best Pictures List\n\n");
}

void search(LIST* list)
{
	short year;
	bool found;

	PICTURE pSrchArgu;
	PICTURE *pPic;

	printf("Enter a four digit year: ");
	scanf("%hd", &year);
	pSrchArgu.year = year;

	found = searchList(list, &pSrchArgu,
		(void**)&pPic);

	if (found)
		printf("%hd %-40s %s\n",
			pPic->year, pPic->picture, pPic->director);
	else
		printf("Sorry, but %d is not available.\n", year);
	return;
}

int cmpYear(void* pYear1, void* pYear2)
{
	int result;
	short year1;
	short year2;

	year1 = ((PICTURE*)pYear1)->year;
	year2 = ((PICTURE*)pYear2)->year;

	if (year1 < year2)
		result = -1;
	else if (year1 > year2)
		result = +1;
	else
		result = 0;
	return result;
}
