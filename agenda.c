#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50

struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct Contact contacts[MAX_CONTACTS];
int numContacts = 0;

void addContact() {
    if (numContacts >= MAX_CONTACTS) {
        printf("A agenda está cheia.\n");
        return;
    }

    struct Contact newContact;

    printf("Nome: ");
    fgets(newContact.name, MAX_NAME_LENGTH, stdin);
    printf("Telefone: ");
    fgets(newContact.phone, MAX_PHONE_LENGTH, stdin);
    printf("Email: ");
    fgets(newContact.email, MAX_EMAIL_LENGTH, stdin);

    // Remove a quebra de linha (\n) do final das strings
    newContact.name[strcspn(newContact.name, "\n")] = '\0';
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';
    newContact.email[strcspn(newContact.email, "\n")] = '\0';

    contacts[numContacts] = newContact;
    numContacts++;

    printf("Contato adicionado com sucesso.\n");
}

void displayContacts() {
    if (numContacts == 0) {
        printf("A agenda está vazia.\n");
        return;
    }

    printf("Agenda de Contatos:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("Contato %d:\n", i + 1);
        printf("Nome: %s\n", contacts[i].name);
        printf("Telefone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
        printf("--------------------\n");
    }
}

void deleteContact() {
    if (numContacts == 0) {
        printf("A agenda está vazia.\n");
        return;
    }

    int index;
    printf("Digite o número do contato que deseja excluir: ");
    scanf("%d", &index);
    getchar(); // Limpa o buffer do teclado

    if (index < 1 || index > numContacts) {
        printf("Número de contato inválido.\n");
        return;
    }

    printf("Contato excluído:\n");
    printf("Nome: %s\n", contacts[index - 1].name);
    printf("Telefone: %s\n", contacts[index - 1].phone);
    printf("Email: %s\n", contacts[index - 1].email);
    printf("--------------------\n");

    // Movendo os contatos restantes para preencher o espaço vazio
    for (int i = index - 1; i < numContacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    numContacts--;

    printf("Contato excluído com sucesso.\n");
}

int main() {
    int choice;

    do {
        printf("Escolha uma opção:\n");
        printf("1. Adicionar Contato\n");
        printf("2. Mostrar Contatos\n");
        printf("3. Excluir Contato\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &choice);
        getchar(); // Limpa o buffer do teclado

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                deleteContact();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
