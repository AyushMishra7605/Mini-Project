#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Bus_Places= 5, Car_Places = 5, Bike_Places = 20, Auto_places = 15;// number of parking places available in parking stand for each vechile in parking lot.

int Fees=0;

int BusCount = 0, CarCount = 0, BikeCount = 0, AutoCount = 0; //number of each vehicle parked in the parking stands.      

int index1 = 0, index2 = 0, index3 = 0;         // index1 is for vehicle number & index2 is for customer name & index3 is for today's date

struct customer                                 
{
    char customerName[10][20],date[10][13];
    int vehicleNumber[10];
} p1;  //variable p1 is declared with 'Point'

// this function is to print the receipt
void print_receipt(int charges_of_vehicle_parking)
{
    printf("\nHere is your's receipt!\n");
    printf("\n");
    printf("Your Name: %s\n", p1.customerName[index2]);
    printf("Your Vehicle numebr: %d\n", p1.vehicleNumber[index1]);
    printf("Date: %s\n", p1.date[index3]);
    printf("Your charges_of_vehicle_parking :%d\n", charges_of_vehicle_parking);
    printf("\n");
}

//this function use to handle bus parking operations
void Bus_parking()
{
    int charges_of_vehicle_parking;
    printf("Please Enter your name: ");
    fflush(stdin);
    gets(p1.customerName[index2]);
    printf("Please Enter vehicle number: ");
    scanf("%d", &p1.vehicleNumber[index1]);
    printf("Please Enter today's date: ");
    fflush(stdin);
    gets(p1.date[index3]);
repeat:
    printf("Please enter charges_of_vehicle_parking: ");
    scanf("%d", &charges_of_vehicle_parking);
    if (charges_of_vehicle_parking < 200 || charges_of_vehicle_parking > 200)
    {
        printf("Please enter valid amount");
        goto repeat;
    }
    else
    {
        Fees = Fees + charges_of_vehicle_parking;
        printf("Your payment is successfully done\n");
    }
    print_receipt(charges_of_vehicle_parking);
    index1++;
    index2++;
    index3++;
    BusCount++;
}

//this function use to handle car parking operations
void car_park()
{
    int charges_of_vehicle_parking;
    printf("Please Enter your name: ");
    fflush(stdin);
    gets(p1.customerName[index2]);
    printf("Please Enter vehicle number: ");
    scanf("%d", &p1.vehicleNumber[index1]);
    printf("Please Enter today's date: ");
    fflush(stdin);
    gets(p1.date[index3]);
repeat:
    printf("Enter parking charges_of_vehicle_parking: ");
    scanf("%d", &charges_of_vehicle_parking);
    if (charges_of_vehicle_parking < 150 || charges_of_vehicle_parking > 150)
    {
        printf("Please enter valid amount");
        goto repeat;
    }
    else
    {
        Fees = Fees + charges_of_vehicle_parking;
        printf("Your payment is successfully done\n");
    }
    print_receipt(charges_of_vehicle_parking);
    index1++;
    index2++;
    index3++;
    CarCount++;
}

//this function use to handle bike parking operations
void bike_park()
{
    int charges_of_vehicle_parking;
    printf("Please Enter your name: ");
    fflush(stdin);
    gets(p1.customerName[index2]);
    printf("Please Enter vehicle number: ");
    scanf("%d", &p1.vehicleNumber[index1]);
    printf("please Enter today's date: ");
    fflush(stdin);
    gets(p1.date[index3]);
repeat:
    printf("Enter parking charges_of_vehicle_parking: ");
    scanf("%d", &charges_of_vehicle_parking);
    if (charges_of_vehicle_parking < 50 || charges_of_vehicle_parking > 50)
    {
        printf("Please enter valid amount");
        goto repeat;
    }
    else
    {
        Fees = Fees + charges_of_vehicle_parking;
        printf("Your payment is successfully done\n");
    }
    print_receipt(charges_of_vehicle_parking);
    index1++;
    index2++;
    index3++;
    BikeCount++;
}

   //this function use to handle auto parking operations
void auto_park()
{
    int charges_of_vehicle_parking;
    printf("Please Enter your name: ");
    fflush(stdin);
    gets(p1.customerName[index2]);
    printf("Please Enter vehicle number: ");
    scanf("%d", &p1.vehicleNumber[index1]);
    printf("Please Enter today's date: ");
    fflush(stdin);
    gets(p1.date[index3]);
repeat:
    printf("Enter parking charges_of_vehicle_parking: ");
    scanf("%d", &charges_of_vehicle_parking);
    if (charges_of_vehicle_parking < 100 || charges_of_vehicle_parking > 100)
    {
        printf("Please enter valid amount");
        goto repeat;
    }
    else
    {
        Fees = Fees + charges_of_vehicle_parking;
        printf("Your payment is successfully done\n");
    }
    print_receipt(charges_of_vehicle_parking);
    index1++;
    index2++;
    index3++;
    AutoCount++;
}

// This function is used to handle parking operation
void park_vehicle()
{
    int choose;
again:
    printf("\n1.Bus                     2.Car\n");
    printf("3.Bike                    4.Auto\n");
    printf("Please tell which vehicle do you want to park: ");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        if (Bus_Places == 0)
        {
            printf("\nSorry! Bus parking slot is not available\n");
        }
        else
        {
            Bus_parking();
            Bus_Places--;
        }
        break;
    case 2:
        if (Car_Places == 0)
        {
            printf("\nSorry! Car parking slot is not available\n");
        }
        else
        {
            car_park();
            Car_Places--;
        }
        break;
    case 3:
        if (Bike_Places == 0)
        {
            printf("\nSorry! Bike parking slot is not available\n");
        }
        else
        {
            bike_park();
            Bike_Places--;
        }
        break;
    case 4:
        if (Auto_places == 0)
        {
            printf("\nSorry! Auto parking slot is not available\n");
        }
        else
        {
            auto_park();
            Auto_places--;
        }
        break;
    default:
        printf("Invalid number try again\n");
        goto again;
    }
}

void check_vehicle()
{
    //This function use to check your vehicle is available or not
    char customerName1[20], date1[13];
    int vehicleNumber;
    int i = 0, check1, check2, check3;
    printf("\nPlease enter some details\n");
    printf("Enter Name: ");
    fflush(stdin);
    gets(customerName1);
    printf("Enter vehicle number: ");
    scanf("%d", &vehicleNumber);
    printf("Enter date: ");
    fflush(stdin);
    gets(date1);
    while (1)
    {
        check1 = strcmp(customerName1, p1.customerName[i]);
        check3 = strcmp(date1, p1.date[i]);
        if (vehicleNumber == p1.vehicleNumber[i])
        {
            check2 = 0;
        }
        if (check1 == 0 && check2 == 0 && check3 == 0)
        {
            printf("\nYour vehicle is available here\n");
            break;
        }
        else
        {
            if (index1 == 9)  // if vehicle number is invalids
            {
                printf("\nSorry! your vehicle is not available here\n");
                break;
            }
        }
        i++;
    }
}

// This is our main function in the code
void main()
{
    int choose;
      do
    {
      printf("\n             Welcome to ROYAL parking          \n");
        printf(" vehicle charges_of_vehicle_parking chart in ROYAL stands is given below: \n");
        printf("Bus charges_of_vehicle_parking: 200               Car charges_of_vehicle_parking: 150\n");
        printf("Bike charges_of_vehicle_parking: 50               Auto charges_of_vehicle_parking: 100\n");
        printf("\nEnter 1 to park your vehicle\n");
        printf("Enter 2 to check your vehicle\n");
        printf("Enter 3 to show today insight\n");
        printf("Enter 4 to exit\n");
    again:
        printf("Please choose any option from the given above choice: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            park_vehicle();
            break;
        case 2:
            check_vehicle();
            break;
        case 3:
            printf("Thank you for using our parking stand\n");
            exit(0);
            break;
        default:
            printf("Invalid number try again\n");
           goto again;
            break;
        }
    }while (choose != 3);
}