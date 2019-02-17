/*��� ����, ���������� �������� � �������� ������ ���������.
��������� ������: ���, ����� ��������, �������, �����.
�������� �������� � ����� ������ �������, ����������� ����� ��������� �����.*/

#include <stdio.h>
#include <stdlib.h>

struct person {
    char name[30];
    char phone[11];
    int age;
    float money;
};

typedef struct person DataType;

struct List {
    DataType data;
    struct List *next;
};

typedef struct List *list;

DataType input_client(void);

list read_file(char *filename, list begin);

list add(list begin, DataType person);

void write_file(char *filename, list begin);

void delete_list(list begin);

void redact(list);

void show(list);

void sum(list begin);

list del(list);

int main(void) {
    char file[50];
    char menu;
    list clients = NULL;
    puts("Enter the file name");
    gets(file);
    clients = read_file(file, clients);
    do {
        system("CLS");
        puts("1. Add");
        puts("2. Redact record");
        puts("3. Show");
        puts("4. Summa");
        puts("5. Delete record");
        puts("6. Exit");
        menu = getchar();
        switch (menu) {
            case '1':
                clients = add(clients, input_client());
                break;
            case '2':
                redact(clients);
                break;
            case '3':
                show(clients);
                break;
            case '4':
                sum(clients);
                break;
            case '5':
                clients = del(clients);
        }
    } while (menu != '6');
    getchar();
    puts("Enter the file name");
    gets(file);
    write_file(file, clients);
    delete_list(clients);
    return 0;
}

DataType input_client(void) {
    DataType client;
    getchar();
    puts("Name");
    gets(client.name);
    puts("Phone");
    gets(client.phone);
    puts("Age");
    scanf("%d", &client.age);
    puts("Money");
    scanf("%f", &client.money);
    return client;
}

list add(list begin, DataType person) {
    list temp;
    if (begin == NULL) {
        begin = (list) malloc(sizeof(struct List));
        temp = begin;
    } else {
        temp = begin;
        while (temp->next) temp = temp->next;
        temp->next = (list) malloc(sizeof(struct List));
        temp = temp->next;
    }
    temp->data = person;
    temp->next = NULL;
    return begin;
}

list read_file(char *filename, list begin) {
    FILE *f;
    DataType client;
    if ((f = fopen(filename, "rb")) == NULL) {
        perror("Error open file");
        getch();
        return begin;
    }
    while (fread(&client, sizeof(client), 1, f))
        begin = add(begin, client);
    fclose(f);
    return begin;
}

void delete_list(list begin) {
    list temp = begin;
    while (temp) {
        begin = temp->next;
        free(temp);
        temp = begin;
    }
}

void write_file(char *filename, list begin) {
    FILE *f;
    if ((f = fopen(filename, "wb")) == NULL) {
        perror("Error create file");
        system("pause");
        return;
    }
    while (begin) {
        fwrite(&begin->data, sizeof(DataType), 1, f);
        begin = begin->next;
    }
}

void print1(list pos) {
    printf("Name : %s\nPhone : %s\nAge : %d\nMoney : %.2f\n", pos->data.name,
           pos->data.phone, pos->data.age, pos->data.money);
}

void redact(list begin) {
    int n, k = 1;
    char yes;
    system("CLS");
    if (begin == NULL) {
        puts("List is empty");
        system("pause");
        return;
    }
    puts("Number record for redact?");
    scanf("%d", &n);
    if (n < 1) {
        puts("Error");
        system("pause");
        return;
    }
    while (begin && k < n) {
        begin = begin->next;
        k++;
    }
    if (begin == NULL) {
        puts("Error");
        system("pause");
        return;
    }
    print1(begin);
    puts("Redact? (y/n)");
    do
        yes = getchar();
    while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
    if (yes == 'y' || yes == 'Y')
        begin->data = input_client();
}

void show(list begin) {
    int k = 0;
    system("CLS");
    if (begin == NULL) {
        puts("List is empty");
        system("pause");
        return;
    }
    puts("|  � |          Name                 |    Phone   |   Age   |   Money   |");
    puts("-------------------------------------------------------------------------");
    while (begin) {
        printf("|%3d | %-29s |%11s |%8d |%10.2f |\n", ++k, begin->data.name,
               begin->data.phone, begin->data.age, begin->data.money);
        begin = begin->next;
    }
    puts("-------------------------------------------------------------------------");
    system("pause");
}

void sum(list begin) {
    float money;
    int max_age = 0, k = -1;
    list pos;
    system("CLS");
    if (begin == NULL) {
        puts("List is empty");
        system("pause");
        return;
    }
    puts("Money?");
    scanf("%f", &money);
    while (begin) {
        k++;
        if (begin->data.money > money && begin->data.age > max_age) {
            max_age = begin->data.age;
            pos = begin;
        }
        begin = begin->next;
    }
    if (max_age == 0) puts("Net takih");
    else print1(pos);
    system("pause");
}

list del(list begin) {
    int n, k = 1;
    char yes;
    list temp, temp1;
    system("CLS");
    if (begin == NULL) {
        puts("List is empty");
        system("pause");
        return NULL;
    }
    puts("Number record for delete?");
    scanf("%d", &n);
    if (n < 1) {
        puts("Error");
        system("pause");
        return begin;
    }
    if (n == 1) {
        print1(begin);
        puts("Delete? (y/n)");
        do
            yes = getchar();
        while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
        if (yes == 'y' || yes == 'Y') {
            temp = begin->next;
            free(begin);
            return temp;
        } else return begin;
    }
    if (begin->next == NULL && n > 1) {
        puts("Error");
        system("pause");
        return begin;
    }
    temp = begin;
    temp1 = temp->next;
    while (temp1->next && k < n - 1) {
        temp = temp1;
        temp1 = temp->next;
        k++;
    }
    if (k < n - 1) {
        puts("Error");
        system("pause");
        return begin;
    }
    print1(temp1);
    puts("Delete? (y/n)");
    do
        yes = getchar();
    while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
    if (yes == 'y' || yes == 'Y') {
        temp->next = temp1->next;
        free(temp1);
    }
    return begin;
}
