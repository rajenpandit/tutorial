#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person;  // struct declaration

struct Person* getPerson(void);  // function declaration
void display(struct Person* person);
int main()
{
    struct Person* person;   // Ok, since size of struct Person* is 64-bit/8-byte
    person = getPerson();
    // struct Person p1;       // Error, since size of struct Person is not known.
    display(person);
}

struct Person{     // struct definition
    char name[20];
    int age;
};

struct Person* getPerson()
{
    struct Person* p= malloc(sizeof(struct Person));
    strcpy(p->name,"Ram");
    p->age = 20;
    return p;
}
void display(struct Person* person)
{
    printf("Name:%s\n", person->name);
    printf("Age:%d\n",person->age);
}

