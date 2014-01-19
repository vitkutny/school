#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	int true; char* text;
} answer;

typedef struct{
	char* text; answer* answers;
} question;

typedef struct{
	question question; answer answer;
} result;

int shutdown();
result* test(question*, int, int);
result test_question(question);
void results_view(result*, int);
question* questionsFromFile(char*, int*);
int main(){
	question* questions;
	int questions_count;
	questions = questionsFromFile("uint.txt", &questions_count);
	int length = questions_count + 1;

	printf("Z kolik otazek chcete sestavit test? ");
	while (length > questions_count){
		scanf("%i", &length);
		fflush(stdin);
	}
	system("CLS");
	results_view(test(questions, questions_count, length), length);
	return shutdown();
}

result* test(question* questions, int questions_count, int length){
	result* results;
	int i, j, q;
	results = (result*)malloc(sizeof(result)*length);

	srand(time(NULL));

	for (i = 0; i < length; i++){
		q = -1;
		while (q < 0){
			q = rand() % questions_count;
			for (j = 0; j < length; j++){
				if (results[j].question.text == questions[q].text){
					q = -1;
				}
			}
		}
		printf("%i/%i\t", i + 1, length);
		results[i] = test_question(questions[q]);
	}

	return results;
}

result test_question(question question){
	result result;
	int i;
	char answer = NULL;
	printf("%s\n", question.text);
	for (i = 0; i < 4; i++){
		printf("\t(");
		switch (i){
		case 0:
			printf("a");
			break;
		case 1:
			printf("b");
			break;
		case 2:
			printf("c");
			break;
		case 3:
			printf("d");
			break;
		};
		printf(") %s\n", question.answers[i].text);
	}

	while (answer < 97 || answer > 100){
		printf("Odpoved\t");
		answer = getchar();
		fflush(stdin);
	}
	system("CLS");

	switch (answer){
	case 'a':
		result.answer = question.answers[0];
		break;
	case 'b':
		result.answer = question.answers[1];
		break;
	case 'c':
		result.answer = question.answers[2];
		break;
	case 'd':
		result.answer = question.answers[3];
		break;
	}
	result.question = question;
	return result;
}

void results_view(result* results, int length){
	int i, j, success = 0;

	for (i = 0; i < length; i++){
		if (results[i].answer.true){
			success++;
		}
	}
	printf("Spravne jste odpovedeli na %i z %i otazek.\n\n", success, length);
	if (success == length){
		return;
	}
	printf("Reseni spatne odpovezenych otazek:\n\n");
	for (i = 0; i < length; i++){
		if (!results[i].answer.true){
			printf("%s\n", results[i].question.text);
			printf("Vase odpoved:\t\t%s\n", results[i].answer.text);
			for (j = 0; j < 4; j++){
				if (results[i].question.answers[j].true){
					printf("Spravna odpoved:\t%s\n\n", results[i].question.answers[j].text);
				}
			}
		}
	}

}

question* questionsFromFile(char* filename, int* count){
	question* questions;
	int i = 1;
	char row[512];
	FILE *file;
	*count = 0;

	file = fopen(filename, "r");
	if (!file){
		return NULL;
	}
	questions = (question*)malloc(NULL);
	while (fgets(row, 512, file)){
		if (row[strlen(row) - 1] == '\n'){
			row[strlen(row) - 1] = '\0';
		}
		if (i == 1){
			questions = (question*)realloc(questions, sizeof(question)*(1 + (*count)));
			questions[*count].text = (char*)malloc(sizeof(char)* 512);
			strcpy(questions[*count].text, row);
			questions[*count].answers = (answer*)malloc(sizeof(answer)* 4);
		}
		else if (i > 1 && i <= 5){
			questions[*count].answers[i - 2].text = (char*)malloc(sizeof(char)* 512);
			strcpy(questions[*count].answers[i - 2].text, row+5);
			questions[*count].answers[i - 2].true = (int)row[0] - '0';
		}
		i++;
		if (i > 5){
			i = 1;
			(*count)++;
		}
	}
	if (file) {
		fclose(file);
	}
	return questions;
}

int shutdown(){
	printf("\n\n");
	system("PAUSE");
	return 0;
}