//name-surname= Saadet Elizaveta BABAL
//In this project, i wanted to create an inventory with the information entered by the user and write a program where i can share this inventory information with the user.
#define _CRT_SECURE_NO_WARNINGS//Here i used this statement to avoid problems with scanfs.
#include <stdio.h>//Here i included stdio.h to use the library under header file.
#include <ctype.h>//Here i included this because the function definitions for the characters are in the header file ctype.h
#define NAME_LEN 25//Here in order to limit the maximum name character to 25, I defined the name_len expression here.
#define MAX_PARTS 100//Here i defined the max_parts expression here to be able to limit the maximum part character to 100.

struct part {//Here i created a struct to store the information of the products in the inventory.
    int number;//Here in order to store the number information of the product in the inventory, I defined the variable number as an integer.
    char name[NAME_LEN + 1];//Here in order to store the name/type information of the product in the inventory, I defined the variable name as char.
    int on_hand;//Here in order to store the remaining amount of the product in the inventory, I defined the on_hand variable as an integer.
    float price;//Here in order to store the price information of the product in the inventory, I defined the price variable as float.
} inventory[MAX_PARTS];//Here i created the inventory array with a maximum number of characters of 100 to be able to store all the information in the inventory.

int num_parts = 0;//I assigned zero to the num_parts variable in order to make the number of products in the inventory zero at first.

int find_part(int number);//I defined the find_part function to check whether the product number entered by the user is in the inventory.
void insert(void);//I have created an insert function to be able to retrieve and store information from the user.
void search(void);//I created this function to check whether the item number entered by the user is in the inventory if the user first enters s
void update(void);//I created this function to store the new information entered by the userand print an error message if any.
void print(void);//Finally, I created this function to be able to print all the information in the inventory to the screen.
int read_line(char str[], int n);//I created a function in the form of a string of length n to store the product name information entered by the user.
int compare_parts(const void* p, const void* q);//I created this function to compare multiple products entered by the user with each other.

int main(void)
{
    char code;//I have defined the code variable as char to store the action that the user will take.

    for (;;) {//I created an infinite loop so that this process can happen continuously.
        printf("Enter operation code: ");//I used the printf function for the user to select the process.
        scanf(" %c", &code);//I used the scanf function to store the process selected by the user.
        while (getchar() != '\n')//I used the while loop so that if any non-space character is entered until the end of the line, it can be read.
            ;
        switch (code) {//I used the switch statement to create options that can be entered by the user.
        case 'i': insert();//If the character entered by the user is i, I used this expression to call the insert function.
            break;//I used this statement to exit the case.
        case 's': search();//If the character entered by the user is s, I used this expression to call the search function.
            break;//I used this statement to exit the case..
        case 'u': update();//I used this expression to call the update function if the character entered by the user is u.
            break;//I used this statement to exit the case.
        case 'p': print();//I used this expression to call the print function if the character entered by the user is p.
            break;//I used this statement to exit the case.
        case 'q': return 0;//If the character entered by the user is q, I used this expression to terminate the program.
        default:  printf("Illegal code\n");//If the user does not enter any of the above statements, I used this statement to print the illegal code on the screen.
        }
        printf("\n");//i used this statement to have the next action start from the next line.
    }
}

int find_part(int number)//I created this function to find if the number entered by the user is matched.
{
    int i;//I will use the variable i to find out if there is a match in the for loop, so I defined it as an integer.

    for (i = 0; i < num_parts; i++)//I used the for loop to find if there are any matches between the numbers.
        if (inventory[i].number == number)//This statement checks for any matches between the numbers.
            return i;//If there is any match between the numbers, the variable i is stored as i again.
    return -1;//If no match is found inside the loop, the function returns -1, that is, the fragment is not in the array.
}


void insert(void)//I created the insert function to store and process the information entered by the user.
{
    int part_number;//I created the part_number variable to be able to control the number of parts.

    if (num_parts == MAX_PARTS) {//If the number of instant fragments is equal to the maximum number of fragments, I used the if statement to inform the user.
        printf("Database is full; can't add more parts.\n");//I used the printf function to inform the user that the database is full.
        return;//I used the return statement to exit the if statement.
    }

    printf("Enter part number: ");//I used the printf function to prompt the user to enter the part number.
    scanf("%d", &part_number);//I used the scanf function to store the part number entered by the user.
    if (find_part(part_number) >= 0) {//I used the if statement to check the dir if the user entered a number that already exists in the inventory.
        printf("Part already exists.\n");//If the user entered the existing number, I used the printf function to give the information.
        return;//I used the return statement to exit the if statement.
    }
    inventory[num_parts].number = part_number;//I have assigned the number to the array so that the user can add the part number entered for the first time to the database.
    printf("Enter part name: ");//I used the print function to have the user enter the part name.
    read_line(inventory[num_parts].name, NAME_LEN);//I used the read_line function instead of scanf so that the track name entered by the user can be read incompletely.
    printf("Enter price: ");//I used the printf function to have the user enter the price of the piece.
    scanf("%f", &inventory[num_parts].price);//I used the scanf function so that the price of the part entered by the user can be stored as the price in the array.
    printf("Enter quantity on hand: ");//I used the printf function for the user to enter the amount for the piece in hand.
    scanf("%d", &inventory[num_parts].on_hand);//I used the scanf function to store the amount of information entered by the user.
    num_parts++;//I used this expression to increase the number of pieces entered after each operation.
}

void search(void)//I created this function to be able to search between tracks if s is entered by the user.
{
    int i, number;//I defined the number entered by the user and the i that I will use in the loop.

    printf("Enter part number: ");//I used the printf function to find the number the user will enter to search.
    scanf("%d", &number);//I used the scanf function to store the number entered by the user.
    i = find_part(number);//I have assigned it to the i statement to be able to use the find_part function.
    if (i >= 0) {//This if statement will work if the number is contained in the find_part function.
        printf("Part name: %s\n", inventory[i].name);//I used the printf function to print the name of the object found in the find_name function.
        printf("Price:$%.2f\n", inventory[i].price);//I used the printf function to print the price of the object found in the find_name function.
        printf("Quantity of hand: %d\n", inventory[i].on_hand);//I used the printf function to print the amount of the object found in the find_name function.
    }
    else
        printf("Part not found.\n");//If the number entered by the user could not be found in the find_part function, I used else and printf statements to provide information about it.
}

void update(void)//I created this function to provide information of the current amount when the user enters the character u.
{
    int i, number, change;//I have defined the i expression as an integer to use in number, change and if.

    printf("Enter part number: ");//I used the printf function so that the user can update and enter the part number.
    scanf("%d", &number);//I used the scanf function to store the number information entered by the user.
    i = find_part(number);//I have assigned it to the i statement to be able to use the find_part function.
    if (i >= 0) {//If the number entered by the user matches any number in the function, I used the if statement to make changes to the number.
        printf("Enter change in quantity on hand: ");//I used the printf function to give the user change information if any number matches.
        scanf("%d", &change);//I used the scanf function to store the amount of change.
        inventory[i].on_hand += change;//I have assigned the change variable to the array so that the change can be reflected in the quantities in the inventory.
    }
    else//If the number entered by the user did not match any number in the find_part function, I used the else statement to make this block work.
        printf("Part not found.\n");//I used the printf function to inform the user that there was no number match.
}


void print(void) {//I created this function to be able to print all the parts to the screen.
    int i;//I created the i statement to be able to use it as a variable in the for loop.

    qsort(inventory, num_parts, sizeof(struct part), compare_parts);//I used the qsort function to sort the parts by number.

    printf("Part Number   Part Name                  Price      Quantity on Hand\n");//I used the printf function to print the headers.
    for (i = 0; i < num_parts; i++)//I used the for loop to be able to create rows for each piece and create a table layout.
        printf("%7d       %-25s$%8.2f%15d\n", inventory[i].number, inventory[i].name, inventory[i].price, inventory[i].on_hand);//I used expressions such as %7d, %-25s to align the track information with the titles.
}

int read_line(char str[], int n)//I created the read_line function to receive and use the track name information entered by the user.
{
    int ch, i = 0;//I created the variables ch and i to use in loops.
    while (isspace(ch = getchar()))// I used the isspace() function to read a character excluding spaces.
        ;

    while (ch != '\n' && ch != EOF) {//I used the while loop so that the ch character can be read to the end of the line.
        if (i < n)//I used the if statement so that the ch character can be read until the string array is full.
            str[i++] = ch;//I assigned it to the array so that the characters used can be added to the string array.
        ch = getchar();//I used the getchar function so that the next character can be read.
    }
    str[i] = '\0';//I used this expression to be able to add the null character to the end of the array.
    return i;//I used this expression to return the number of characters entered inside the function.
}

int compare_parts(const void* p, const void* q) {//I created this function to compare the product information and prices entered by the user.
    const struct part* p1 = p;//In order to compare the two charges, I converted the part type p1 to a pointer with the name.
    const struct part* p2 = q;//In order to compare the two charges, I converted the part type p2 to a pointer with the name.

    if (p1->price < p2->price)//I used the if statement to specify that if p1->price is less than p2->price, p1 must come before p2 in the sorted list.
        return -1;//I returned the function to -1 to indicate this situation.
    else if (p1->price > p2->price)//I used the else statement to indicate that if p1->price is greater than p2->price, p1 should come after p2 in the sorted list.
        return 1;//I have returned the function to 1 to indicate this situation.
    else//If p1->price is equal to p2->price, I used the else statement to indicate that the order of p1 and p2 doesn't matter in the sorted list.
        return 0;//I have returned the function to 0 to indicate that this is not important.
}
