#include <stdio.h>


// Define locality and prices
char locality[4][20] = {"Kothrud", "Baner", "Karve Nagar", "Balewadi"};
int oneBHK_buy[4] = { 1071400, 1466600, 975000, 1661500 };
int twoBHK_buy[4] = { 2666600, 2900000, 2057000, 2200000 };
int threeBHK_buy[4] = { 3833300, 4410000, 2600000, 4100000 };


// Define the renting prices
int oneBHK_rent[4] = {10714, 14666, 9750, 16615};
int twoBHK_rent[4] = {26666, 29000, 20570, 22000};
int threeBHK_rent[4] = {38333, 44100, 26000, 41000};


int main() 
{
    int rent, budget, buy, area,size,temp,price;
    float loan_amount, monthly_payment;
    int loan_term;


    // Fixed interest rate of 9%
    float interest_rate = 9.0;


    printf("WELCOME\n");
    printf("If you want to buy a property enter 0, if you want to rent press 1: ");
    scanf("%d", &buy);


    switch (buy) 
    {
        case 0: // Buying Section
            printf("Enter your budget for buying:");
            scanf("%d", &budget);


            if (budget <= 0) 
            {
                printf("Error,Budget can not be less than or equal to zero.\n");
            } 
            else 
            {
                for (int j = 0; j < 4; j++) 
                {
                    if (oneBHK_buy[j] <= budget) 
                    {
                        printf("One BHK available at %s locality for %d\n", locality[j], oneBHK_buy[j]);
                    }
                    if (twoBHK_buy[j] <= budget) 
                    {
                        printf("Two BHK available at %s locality for %d\n", locality[j], twoBHK_buy[j]);
                    }
                    if (threeBHK_buy[j] <= budget) 
                    {
                        printf("Three BHK available at %s locality for %d\n", locality[j], threeBHK_buy[j]);
                    }
                    if (budget<975000) 
                    {
                        printf("There are no available properties.\n");
                        printf("Thank you for visiting!\n");
                        return 0;
                    }
                }


                printf("\n\nChoose the area you want to buy the property,\n");
                printf("Enter 1 for Kothrud, 2 for Baner, 3 for Karve Nagar, 4 for Balewadi:");
                scanf("%d", &area);
                area-=1;
                //temp=locality[area]; 
                printf("\n\nChoose the size of the property,\n");
                printf("Enter 1 for OneBHK, 2 for TwoBHK, 3 for ThreeBHK:");
                scanf("%d", &size);
                switch (size) 
                {
                    case 1:
                        price=oneBHK_buy[area];
                        printf("You have selected a property of OneBHK at %s of Rs%d.",locality[area],price);
                        break;
                    case 2:
                        price=twoBHK_buy[area];
                        printf("You have selected a property of TwoBHK at %s of Rs%d.",locality[area],price);
                        break;
                    case 3:
                        price=threeBHK_buy[area];
                        printf("You have selected a property of ThreeBHK at %s of Rs%d.",locality[area],price);
                        break;

                    default:
                        printf("Invalid input.\n");
                        break;
                }
                

                // Loan section with fixed interest rate
                printf("\n\nDo you want to pay in full or take a loan? (Enter 1 for full payment, 2 for loan):");
                int payment_choice,creditscore,downpayment;
                scanf("%d", &payment_choice);


                if (payment_choice == 1) 
                {
                    switch (area)

                                {
                                case 0:
                                    printf("Please contact agent Tanishka on mobile number +917843486513\n");
                                    break;
                                case 1:
                                    printf("Please contact agent Keshav on mobile number +919624738759\n");
                                    break;
                                case 2:
                                    printf("Please contact agent Sumedh on mobile number +917324567258\n");
                                    break;
                                case 3:
                                    printf("Please contact agent Soham on mobile number +919879012436\n");
                                    break;
                                default:
                                    printf("Invalid input.\n");
                                    break;
                                }
                } 
                else if (payment_choice == 2) 
                {
                    printf("Please enter your credit score:");
                    scanf("%d", &creditscore);
                    if (creditscore >= 750 && creditscore <= 900)
                    {
                        printf("You are eligible for loan");
                        printf("\nEnter loan term (in years):");                        
                        scanf("%d", &loan_term);
                         printf("\nEnter downpayment in Rs:");                        
                        scanf("%d", &downpayment);

                    // Fixed annual interest rate of 9%
                    price-=downpayment;
                    float total_interest= (9*price) /100;
                    printf("total Interest:%f\n",total_interest);
                    float total_repayment_amount = price+total_interest;
                    monthly_payment=total_repayment_amount/(loan_term * 12);
                    printf("Monthly payment :%f\n",monthly_payment );
                    /*// Calculate (1 + r)^n using a loop
                    float pow_value = 1.0;
                    for (int i = 0; i < total_payments; i++) 
                    {
                        pow_value *= (1 + monthly_rate);
                    }

                    // Calculate monthly payment using the loan formula
                    monthly_payment = (loan_amount * monthly_rate * pow_value) / (pow_value - 1);

                     */
                    printf("\nFor a loan of %d at a fixed interset of 9 percent per year,total interest for %d years, your monthly payment is:%f\n",price,loan_term,monthly_payment);
                    //printf("Thank you for visiting!\n");
                    }
                    else if (creditscore<750)
                    {
                     printf("Sorry, You are not eligible for loan, Please contact our sales advisor:\n 9875XXXXXX");
                    }
                    break; 
                }

            }
            
                        
            break;


         case 1: // Renting Section
            printf("Enter your rent budget: ");
            scanf("%d", &budget);


            if (budget <= 0) {
                printf("Budget can not be less than or equal to zero.\n");
            } else {
                for (int j = 0; j < 4; j++) {
                    if (oneBHK_rent[j] <= budget) {
                        printf("One BHK available at %s locality for %d\n", locality[j], oneBHK_rent[j]);
                    }
                    if (twoBHK_rent[j] <= budget) {
                        printf("Two BHK available at %s locality for %d\n", locality[j], twoBHK_rent[j]);
                    }
                    if (threeBHK_rent[j] <= budget) {
                        printf("Three BHK available at %s locality for %d\n", locality[j], threeBHK_rent[j]);
                    }
                }


                printf("\n\nFor further information in following areas,\n");
                printf("Enter 1 for Kothrud, 2 for Baner, 3 for Karve Nagar, 4 for Balewadi: ");
                scanf("%d", &area);


                switch (area) {
                    case 1:
                        printf("Please contact agent Tanishka on mobile number +917843486513\n");
                        break;
                    case 2:
                        printf("Please contact agent Keshav on mobile number +919624738759\n");
                        break;
                    case 3:
                        printf("Please contact agent Sumedh on mobile number +917324567258\n");
                        break;
                    case 4:
                        printf("Please contact agent Soham on mobile number +919879012436\n");
                        break;
                    default:
                        printf("Invalid input.\n");
                        break;
                }
            }
            break;


        default:
            printf("Error, Please enter only 0 or 1.\n");
            break;
    }


    printf("Thank you for visiting!\n");
    return 0;
}