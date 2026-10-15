
#include <stdio.h>
#include <string.h>

int main()
{
    char names[5][100];
    char emails[5][100];
    char phones[5][30];
    char towns[5][50];

    char searchName[100];
    char backup[100];
    char description[250];

    int choice;
    int count = 0;
    int i;
    int found;

    do
    {
        printf("\n====================================\n");
        printf("   MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("       SUPPLIER MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Copy Supplier Name\n");
        printf("6. Construct Supplier Description\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                if (count >= 5)
                {
                    printf("Maximum of 5 suppliers reached.\n");
                    break;
                }

                printf("\nEnter supplier name: ");
                fgets(names[count], sizeof(names[count]), stdin);
                names[count][strcspn(names[count], "\n")] = '\0';

                printf("Enter email: ");
                fgets(emails[count], sizeof(emails[count]), stdin);
                emails[count][strcspn(emails[count], "\n")] = '\0';

                printf("Enter phone number: ");
                fgets(phones[count], sizeof(phones[count]), stdin);
                phones[count][strcspn(phones[count], "\n")] = '\0';

                printf("Enter town: ");
                fgets(towns[count], sizeof(towns[count]), stdin);
                towns[count][strcspn(towns[count], "\n")] = '\0';

                count++;

                printf("Supplier added successfully.\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("No suppliers available.\n");
                    break;
                }

                printf("\n===== SUPPLIER DETAILS =====\n");

                for (i = 0; i < count; i++)
                {
                    printf("\nSupplier %d\n", i + 1);
                    printf("Name  : %s\n", names[i]);
                    printf("Email : %s\n", emails[i]);
                    printf("Phone : %s\n", phones[i]);
                    printf("Town  : %s\n", towns[i]);
                }
                break;

            case 3:
                if (count == 0)
                {
                    printf("No suppliers available to search.\n");
                    break;
                }

                printf("Enter supplier name to search: ");
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = '\0';

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (strcmp(names[i], searchName) == 0)
                    {
                        printf("\nSupplier found.\n");
                        printf("Name  : %s\n", names[i]);
                        printf("Email : %s\n", emails[i]);
                        printf("Phone : %s\n", phones[i]);
                        printf("Town  : %s\n", towns[i]);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Supplier not found.\n");
                }
                break;

            case 4:
                if (count == 0)
                {
                    printf("No suppliers available.\n");
                    break;
                }

                for (i = 0; i < count; i++)
                {
                    printf("\nSupplier: %s\n", names[i]);
                    printf("Supplier name length: %lu\n",
                           (unsigned long)strlen(names[i]));
                    printf("Email length: %lu\n",
                           (unsigned long)strlen(emails[i]));
                    printf("Town length: %lu\n",
                           (unsigned long)strlen(towns[i]));
                }
                break;

            case 5:
                if (count == 0)
                {
                    printf("No suppliers available to copy.\n");
                    break;
                }

                printf("Enter supplier name to copy: ");
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = '\0';

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (strcmp(names[i], searchName) == 0)
                    {
                        strcpy(backup, names[i]);

                        printf("Original name: %s\n", names[i]);
                        printf("Copied name  : %s\n", backup);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Supplier not found.\n");
                }
                break;

            case 6:
                if (count == 0)
                {
                    printf("No suppliers available.\n");
                    break;
                }

                printf("Enter supplier name: ");
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = '\0';

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (strcmp(names[i], searchName) == 0)
                    {
                        strcpy(description, names[i]);
                        strcat(description, " operates in ");
                        strcat(description, towns[i]);
                        strcat(description, ".");

                        printf("%s\n", description);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Supplier not found.\n");
                }
                break;

            case 7:
                printf("Exiting Supplier Management System.\n");
                break;

            default:
                printf("Invalid choice. Please select 1 to 7.\n");
        }

    } while (choice != 7);

    return 0;
}
