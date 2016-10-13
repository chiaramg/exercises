#include <stdio.h>

char GRADE_MAP[] = { 'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};

// class definition:

class Grade{
public:
    int percent;
    char letter;

    void setByPercent(int p){
        percent = p;
        letter = GRADE_MAP[p/10];
    }

    void print(){
        printf("Grade : %d: %c\n", percent, letter);
    };

    void setByLetter(char l) {
        percent = 100 - (l - 'A') * 10 -5;
        letter = l;
    }
};


int main(){
    Grade g;
    int percent;

    printf("Enter two grades separated by a space. Use a percentage for the first and letter for the second: ");
    scanf("%d", &percent);
    scanf("\n");

    g.setByPercent(percent);
    g.print();

    g.setByLetter(getchar());
    g.print();

    return 0;
}
