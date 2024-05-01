#include <stdio.h>
#define NUM_SCHOOLS 12

// defining struct
struct Student {
  int month;
  int day;
  int school[3]; // Array to store school assignment for 3 years
};

// function to assign zodiac to a student based on date/month
int get_zodiac(struct Student student) {
    if ((student.month == 3 && (student.day >= 21 && student.day <= 31)) || (student.month == 4 && (student.day >= 1 && student.day <= 19))) return 0; //Aries
    else if ((student.month == 4 && (student.day >= 20 && student.day <= 30)) || (student.month == 5 && (student.day >= 1 && student.day <= 20))) return 1; //Taurus
    else if ((student.month == 5 && (student.day >= 21 && student.day <= 31)) || (student.month == 6 && (student.day >= 1 && student.day <= 20))) return 2; //Gemini
    else if ((student.month == 6 && (student.day >= 21 && student.day <= 30)) || (student.month == 7 && (student.day >= 1 && student.day <= 22))) return 3; //Cancer
    else if ((student.month == 7 && (student.day >= 23 && student.day <= 31)) || (student.month == 8 && (student.day >= 1 && student.day <= 22))) return 4; //Leo
    else if ((student.month == 8 && (student.day >= 23 && student.day <= 31)) || (student.month == 9 && (student.day >= 1 && student.day <= 22))) return 5; //Virgo
    else if ((student.month == 9 && (student.day >= 23 && student.day <= 30)) || (student.month == 10 && (student.day >= 1 && student.day <= 22))) return 6; //Libra
    else if ((student.month == 10 && (student.day >= 23 && student.day <= 31)) || (student.month == 11 && (student.day >= 1 && student.day <= 21))) return 7; //Scorpio
    else if ((student.month == 11 && (student.day >= 22 && student.day <= 30)) || (student.month == 12 && (student.day >= 1 && student.day <= 21))) return 8; //Saggitarius
    else if ((student.month == 12 && (student.day >= 22 && student.day <= 31)) || (student.month == 1 && (student.day >= 1 && student.day <= 19))) return 9; //Capricorn
    else if ((student.month == 1 && (student.day >= 20 && student.day <= 31)) || (student.month == 2 && (student.day >= 1 && student.day <= 18))) return 10; //Aquarius
    else if ((student.month == 2 && (student.day >= 19 && student.day <= 29)) || (student.month == 3 && (student.day >= 1 && student.day <= 20))) return 11; //Pisces // includes leap year
    else return -1; // invalid bdate
}

// assigns schools to each student for the current year based on their zodiac sign
// pass by reference since we're changing the struct's school values
void assign_school(struct Student* student, int year) {
  int zodiac_sign = get_zodiac(*student);
  if (zodiac_sign == -1) {
    printf("Invalid birthdate\n");
    return;
  }
  student->school[year % 3] = (zodiac_sign + year) % NUM_SCHOOLS; // assigns sschool for current year
}

int main() {

    // keeps track of student count
    struct Student student;
    printf("Enter the number of students you want to enter in the school database: ");
    int n;
    scanf("%d", &n);

    // loops until n becomes 0
    while (n){
      int day, month;

      printf("Enter your date of birth (day/month): ");
      scanf("%d/%d", &day, &month);

      student.day = day;
      student.month = month;

      assign_school(&student, 0);
      assign_school(&student, 1);
      assign_school(&student, 2);

      // adding 1 to get a value in the range of 1 to 12
      printf("School assignments for the next 3 years:\n");
      printf("Year 1: School S%d\n", student.school[0] + 1);
      printf("Year 2: School S%d\n", student.school[1] + 1);
      printf("Year 3: School S%d\n", student.school[2] + 1);

      n--;
    }
  return 0;
}
