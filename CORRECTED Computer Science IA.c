/* Name:   and
 * School: Holy Name Convent Secondary School, Port-of-Spain
 * Center #: 160027
 * Candidate Number:
     160027XXXX M
     160027XXX W
 * Subject: Computer Science
 * Proficiency: Coding ************
 * Title:
 * Teacher's Name: Michael Jones
 * Program Completion Date: 15th May, 2021
 * Purpose:
 * Input files:
     Stocks.txt
     temp.txt
     Stocks.bak.txt (this is a back up of the Stocks.txt file)
 * Output file(s):
      Stocks.txt
      temp.txt
      Stocks.bak.txt (this is a back up of the Stocks.txt file)
 * Techniques used:
    - File I/O
    - Data Structures
    - Linear search
    - Bubble sort
    - Arrays
    - Sequential, Conditional and Repetitive Logic
 ***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPLOYEE_INFO_FILE "Employee_Information.txt"
#define TMP1_FILE "Temp1_information.txt"
#define EMPLOYEE_WORK_FILE "Work_Information.txt"
#define TMP2_FILE "Temp2_information.txt"
#define NUM_DEPTS 10
#define MAX_CHARS 50
#define EMPLOYEE_CAPACITY 60
#define NUM_RECORDS_IN_FILE 50
#define dependantsAllowance_rate 0.1
#define personalAllowance_rate 0.5
#define nationalInsurance 0.1
#define medicalPlan 0.05
#define pension 0.02
#define incomeTax 0.1
#define union_rate 0.03
#define NUM_RECORDS_DEPT 8


struct Department
{
    char departmentID[25];
    char departmentName[25];
};

struct Department department[NUM_DEPTS];

struct Employee
{
    char employeeID[MAX_CHARS];
    char firstName[MAX_CHARS];
    char lastName[MAX_CHARS];
    char gender[MAX_CHARS];
    char dob[MAX_CHARS];
    char address[MAX_CHARS];
    char contactNumber[MAX_CHARS];
    int numDependants;
    int startYear;
    char departmentID[MAX_CHARS];
    char jobTitle[MAX_CHARS];
};

struct Employee employees[EMPLOYEE_CAPACITY];

struct MonthlyWageData
{
    char employeeID[25];
    float RateOfPay;
    int hoursWorked;
    int overtimeHoursWorked;
    int daysWorked;
};

struct MonthlyWageData mwages[EMPLOYEE_CAPACITY];

//Globals
int num_records_Employees;
int num_records_Department;


/*
 * Function:  approx_pi
 * --------------------
 * computes an approximation of pi using:
 *    pi/6 = 1/2 + (1/2 x 3/4) 1/5 (1/2)^3  + (1/2 x 3/4 x 5/6) 1/7 (1/2)^5 +
 *
 *  n: number of terms in the series to sum
 *
 *  returns: the approximate value of pi obtained by suming the first n terms
 *           in the above series
 *           returns zero on error (if n is non-positive)
 */
int entry()
{
    system("cls");

    char code[25];
    printf("Please enter password:");
    scanf("%s",&code);
    const char password[8]="abc";

    if (strcmp(code,password)==0 )
    {
        printf("\nAccess Granted..........\n");
        return 1;
    }
    else
    {
        printf("\nAccess Denied...........\n");
        return 0;
    }
}


/*
 * Function:  approx_pi
 * --------------------
 * computes an approximation of pi using:
 *    pi/6 = 1/2 + (1/2 x 3/4) 1/5 (1/2)^3  + (1/2 x 3/4 x 5/6) 1/7 (1/2)^5 +
 *
 *  n: number of terms in the series to sum
 *
 *  returns: the approximate value of pi obtained by suming the first n terms
 *           in the above series
 *           returns zero on error (if n is non-positive)
 */
void exit_message()
{
    system ("cls");
    printf("THANK YOU!\n\n");
    system("pause");
    exit(1);

}


/*
 * Function:  approx_pi
 * --------------------
 * computes an approximation of pi using:
 *    pi/6 = 1/2 + (1/2 x 3/4) 1/5 (1/2)^3  + (1/2 x 3/4 x 5/6) 1/7 (1/2)^5 +
 *
 *  n: number of terms in the series to sum
 *
 *  returns: the approximate value of pi obtained by suming the first n terms
 *           in the above series
 *           returns zero on error (if n is non-positive)
 */
void paySlip()
{
    system("pause");
    system("cls");
    char id_employee[25];
    printf("\nPlease Enter the employess's ID: ");
    scanf("%s",id_employee);
    int i;
    int line_num;
    int find_result;

    float grossPay, dependantsAllowance, personalAllowance, taxFree_income;
    float taxable_income, national_insuranceAMT, medicalPlan_AMT;
    float taxable_remainder, pension_AMT, incomeTax_AMT, union_AMT;
    float total_deductions, overTime_AMT, netPay, wageAMT,overtime_AMT;

    FILE *input1= fopen("Employee_Information.txt","r");

    for(i=0; i<num_records_Employees; i++)
    {
        if((strcmp(id_employee, employees[i].employeeID)) == 0)
        {

            wageAMT=(mwages[i].hoursWorked * mwages[i].RateOfPay) * mwages[i].daysWorked;
            overTime_AMT= mwages[i].overtimeHoursWorked * (1.5 * mwages[i].RateOfPay);
            dependantsAllowance= employees[i].numDependants * dependantsAllowance_rate;
            personalAllowance= wageAMT * personalAllowance_rate;
            grossPay=wageAMT+overTime_AMT;
            taxFree_income= dependantsAllowance + personalAllowance;

            taxable_income= grossPay - taxFree_income;

            //The first $200 of an employee's taxable income is subjected to national insurance rate
            national_insuranceAMT = 200 * nationalInsurance;

            medicalPlan_AMT= (taxable_income - national_insuranceAMT) * medicalPlan;

            //The remainder of the Taxable_income is subjected to pension rate, income tax rate and union rate
            taxable_remainder= taxable_income -(national_insuranceAMT + medicalPlan_AMT);
            pension_AMT= taxable_remainder * pension;
            incomeTax_AMT= (taxable_remainder - pension_AMT) * incomeTax;
            union_AMT= (taxable_remainder - (pension_AMT + incomeTax_AMT)) * union_rate;

            total_deductions= national_insuranceAMT + medicalPlan_AMT + pension_AMT + incomeTax_AMT + union_AMT;

            netPay= grossPay - total_deductions;

            printf("\n----------------------------------------------------------------------------");
            printf("\nEmployee Information\n");
            printf("\nName of Employee: %s %s",employees[i].firstName,employees[i].lastName);
            printf("\nAddress: %s",employees[i].address);
            printf("\nContact: %s",employees[i].contactNumber);
            printf("\nDepartment ID: %s",employees[i].departmentID);
            printf("\nPosition: %s",employees[i].jobTitle);

            printf("\n\n\t\tHours\t    Days    Rate\tCurrent Amount");
            printf("\nEarnings");
            printf("\nStandard pay\t %-10d   %-d     %-10.2f  $%-10.2f",mwages[i].hoursWorked,mwages[i].daysWorked,mwages[i].RateOfPay, wageAMT);
            printf("\nOvertime pay\t %-10d          %-0.2f       $%-10.2f",mwages[i].overtimeHoursWorked,mwages[i].RateOfPay*1.5, overTime_AMT);
            printf("\n----------------------------------------------------------------------------");
            printf("\n\n\t\t\tGross Pay\t\t $%.2f",grossPay);
            printf("\n----------------------------------------------------------------------------");
            printf("\n\n\t\t\t\t\t\tCurrent Amount");
            printf("\n\nDeduction");
            printf("\nNational Insurance\t\t\t\t $%-1.2f",national_insuranceAMT);
            printf("\nMedial Plan\t\t\t\t\t $%-1.2f",medicalPlan_AMT);
            printf("\nPension\t\t\t\t\t\t $%-1.2f",pension_AMT);
            printf("\nIncome Tax\t\t\t\t\t $%-5.2f",incomeTax_AMT);
            printf("\nUnion\t\t\t\t\t\t $%-10.f",union_AMT);
            printf("\n----------------------------------------------------------------------------");
            printf("\n\n\t\tTotal Deductions \t\t $%.2f",total_deductions);
            printf("\n----------------------------------------------------------------------------");
            printf("\n\n\t\tNet Pay\t\t\t\t $%.2f",netPay);
            printf("\n----------------------------------------------------------------------------");

        }

    }
}

/*
 * Function:  approx_pi
 * --------------------
 * computes an approximation of pi using:
 *    pi/6 = 1/2 + (1/2 x 3/4) 1/5 (1/2)^3  + (1/2 x 3/4 x 5/6) 1/7 (1/2)^5 +
 *
 *  n: number of terms in the series to sum
 *
 *  returns: the approximate value of pi obtained by suming the first n terms
 *           in the above series
 *           returns zero on error (if n is non-positive)
 */
void payroll_register()
{
    system("cls");

    int i;
    float grossPay[num_records_Employees], dependantsAllowance[num_records_Employees], personalAllowance[num_records_Employees], taxFree_income[num_records_Employees];
    float taxable_income[num_records_Employees], national_insuranceAMT[num_records_Employees], medicalPlan_AMT[num_records_Employees];
    float taxable_remainder[num_records_Employees], pension_AMT[num_records_Employees], incomeTax_AMT[num_records_Employees], union_AMT[num_records_Employees];
    float total_deductions[num_records_Employees], overTime_AMT[num_records_Employees], netPay[num_records_Employees], wageAMT[num_records_Employees],overtime_AMT[num_records_Employees];

    for(i=0; i<num_records_Employees; i++)
    {
        wageAMT[i]=(mwages[i].hoursWorked * mwages[i].RateOfPay) * mwages[i].daysWorked; //The employee wage was calculated by multiplying their hours worked daily by hourly rate and the total number of days worked in the given month
        overTime_AMT[i]= mwages[i].overtimeHoursWorked * (1.5 * mwages[i].RateOfPay); // the employee overtime wage was calculated by multiply their overtime hours by time and a half of their employee hourly rate
        dependantsAllowance[i]= employees[i].numDependants * dependantsAllowance_rate; // the dependants allowance is part of the employee taxfree income by mutiplying the number of household dependants by the rate per
        personalAllowance[i]= wageAMT[i] * personalAllowance_rate; // The personal allowance is part of the employee taxfree income by multiplying their wage by the personal aloowance rate
        grossPay[i]=wageAMT[i]+overTime_AMT[i]; // the gross par is the sum of the employee wage and overtime wage
        taxFree_income[i]= dependantsAllowance[i] + personalAllowance[i]; // the total taxfree income was the sum of the dependants allowance and personal allowance

        taxable_income[i]= grossPay[i] - taxFree_income[i]; // the taxable income was the differnce of the employee gross pay and the total taxfree income

        //The first $200 of an employee's taxable income is subjected to national insurance rate
        // National insurance is multiplying the national insurance rate by $200
        national_insuranceAMT[i] = 200 * nationalInsurance;

        // Medcial plan is obtained by first subtracting the taxable_income by the national insurance amount then multiplying the differnce by the medical plan rate
        medicalPlan_AMT[i] = (taxable_income[i] - national_insuranceAMT[i]) * medicalPlan;

        // Taxable remainder is the sum of the medical plan amount and the  national insurance amount subtacted from the taxable income
        taxable_remainder[i]= taxable_income[i] -(national_insuranceAMT[i] + medicalPlan_AMT[i]);

        //The remainder of the Taxable_income is subjected to pension rate, income tax rate and union rate
        // Pension Amount is the taxable reminder multiplied by the pension rate
        pension_AMT[i]= taxable_remainder[i] * pension;

        //Income Tax Amount is the first subtracting the taxable remainder by the pension Amount then multiplying the difference by the income tax rate
        incomeTax_AMT[i]= (taxable_remainder[i] - pension_AMT[i]) * incomeTax;

        // Union Amount is first subtracting the taxable income by the sum of the pension Amount and the income tax then multiplying the differnce by the union rate
        union_AMT[i]= (taxable_remainder[i] - (pension_AMT[i] + incomeTax_AMT[i])) * union_rate;

        // The Totla deductions is the sum of the national in surance amount, medical plan amount, pension amount, income tax amount and the union amount
        total_deductions[i]= national_insuranceAMT[i] + medicalPlan_AMT[i] + pension_AMT[i] + incomeTax_AMT[i] + union_AMT[i];

        // Net Pay is the gross pay subtracted by the total deductions
        netPay[i]= grossPay[i] - total_deductions[i];
    }
    printf("\t\t\t\t__________ Payroll Register for Monthly Paid Staff____________\n");
    printf("\n\t\t\t\t   Earnings\t\t\t     Deductions");
    printf("\nEmp ID\t\tEmp Name\t   Total Wage  OT Wage   G Pay\t     Ins.     M. Plan    Pension     I. Tax      Union       Total       Net Pay\n");

    for(i=0; i<num_records_Employees; i++)
    {
        printf("\n%-8s    %-10s %-9s   $%-10.2f $%-9.2f  $%-8.2f  $%-7.2f $%-9.2f $%-10.2f $%-10.2f $%-10.2f $%-10.2f $%-20.2f",employees[i].employeeID,
               employees[i].firstName,
               employees[i].lastName,
               wageAMT[i],
               overTime_AMT[i],
               grossPay[i],
               national_insuranceAMT[i],
               medicalPlan_AMT[i],
               pension_AMT[i],
               incomeTax_AMT[i],
               union_AMT[i],
               total_deductions[i],
               netPay[i]);
    }
}

/*
 * Function:  approx_pi
 * --------------------
 * computes an approximation of pi using:
 *    pi/6 = 1/2 + (1/2 x 3/4) 1/5 (1/2)^3  + (1/2 x 3/4 x 5/6) 1/7 (1/2)^5 +
 *
 *  n: number of terms in the series to sum
 *
 *  returns: the approximate value of pi obtained by suming the first n terms
 *           in the above series
 *           returns zero on error (if n is non-positive)
 */
void search()
{
    system("pause");
    system("cls");

    int i;
    char id_employee[MAX_CHARS];

    FILE *input1= fopen("Employee_Information.txt","r");
    FILE *input2= fopen("Work_Information.txt","r");

    printf("Enter the Employee ID to Search : ");
    scanf("%s",&id_employee);

    system("cls");

    printf("Employee_ID\tEmp_Name\t Emp_Gender DoB Address Contact Nos_Dependants Emp_year Department_ID Position");

    for(i=0; i<num_records_Employees; i++)
    {
        if(strcmp(id_employee,employees[i].employeeID)==0)
        {
            system("cls");
            printf("Employee ID: %s \nEmployee Name: %s %s \nEmployee Gender: %s \nDate of Birth: %s \nAddress: %s \nContact: %s \nNumber of Dependants: %d \nEmployment Year: %d \nDepartment ID: %s \nPosition: %s \nRate of Pay: %.2f \nHours Worked: %d \nDays Worked: %d \nOvertime Hours Worked: %d",
                   employees[i].employeeID,
                   employees[i].firstName,
                   employees[i].lastName,
                   employees[i].gender,
                   employees[i].dob,
                   employees[i].address,
                   employees[i].contactNumber,
                   employees[i].numDependants,
                   employees[i].startYear,
                   employees[i].departmentID,
                   employees[i].jobTitle,
                   mwages[i].RateOfPay,
                   mwages[i].hoursWorked,
                   mwages[i].daysWorked,
                   mwages[i].overtimeHoursWorked);
        }

    }
    fclose(input1);
    fclose(input2);
}

/*
 * Function:  approx_pi
 * --------------------
 * computes an approximation of pi using:
 *    pi/6 = 1/2 + (1/2 x 3/4) 1/5 (1/2)^3  + (1/2 x 3/4 x 5/6) 1/7 (1/2)^5 +
 *
 *  n: number of terms in the series to sum
 *
 *  returns: the approximate value of pi obtained by suming the first n terms
 *           in the above series
 *           returns zero on error (if n is non-positive)
 */
void bubble_sort()
{
    system("cls");
    int n,k,i;
    char temp1[MAX_CHARS];

    struct Employee eTemp;

    for (i=0; i<=num_records_Employees; i++)
    {
        for(k=0; k<=(num_records_Employees-1-i); k++)
        {
            if(strcmp(employees[k].jobTitle,employees[k+1].jobTitle)>0)
            {
                eTemp = employees[k];
                employees[k] = employees[k+1];
                employees[k+1] = eTemp;

                //strcpy(temp1,employees[k].jobTitle);
                //strcpy(employees[k].jobTitle,employees[k+1].jobTitle);
                //strcpy(employees[k+1].jobTitle,temp1);
            }
        }
    }

    printf("__________ Sorted Employee Record____________\n\n");
    printf("\nEmployee ID\t Employee Position    \t Employee Name");


    for(i=0; i<num_records_Employees; i++)
    {
        printf("\n%-8s         %-23s  %-8s %s",
               employees[i].employeeID,
               employees[i].jobTitle,
               employees[i].firstName,
               employees[i].lastName);
    }
}


/*
 * Function:  approx_pi
 * --------------------
 * computes an approximation of pi using:
 *    pi/6 = 1/2 + (1/2 x 3/4) 1/5 (1/2)^3  + (1/2 x 3/4 x 5/6) 1/7 (1/2)^5 +
 *
 *  n: number of terms in the series to sum
 *
 *  returns: the approximate value of pi obtained by suming the first n terms
 *           in the above series
 *           returns zero on error (if n is non-positive)
 */
void delete_record()
{
    system("cls");

    char id_employee[25];

    printf("Enter the Employee ID you wish to delete");
    scanf("%s", &id_employee);


    char tempID1[MAX_CHARS];
    int c, t;
    char tempID2[MAX_CHARS];
    char buffer[num_records_Employees];

    FILE *input1= fopen("Employee_Information.txt","r");
    FILE * temp1= fopen("Temp1_information.txt","w");

    FILE *input2= fopen("Work_Information.txt","r");
    FILE * temp2= fopen("Temp2_information.txt","w");

    if (input1 == NULL || temp1 == NULL || input2 == NULL || temp2 == NULL)
    {
        exit(1);
    }

    // Copy the data from the original to the temp file
    while (!feof(input1))
    {

        if ( fscanf(input1,"%d\n",&tempID1) < 0) break;

        t = 0;  //reset our count var

        do
        {
            c = fgetc (input1);

            if (c == EOF) break;

            if  (c != '\n' ) buffer[t++] = c;

        }
        while (c != '\n');

        buffer[t] = '\0';

        //Skip the line to omit.
        if (tempID1 != id_employee)
            fprintf(temp1,"%d %s\n",tempID1, buffer);
    }

    while (!feof(input2))
    {

        if ( fscanf(input2,"%d\n",&tempID2) < 0) break;

        t = 0;  //reset our count var

        do
        {
            c = fgetc (input2);

            if (c == EOF) break;

            if  (c != '\n' ) buffer[t++] = c;

        }
        while (c != '\n');

        buffer[t] = '\0';

        //Skip the line to omit.
        if (tempID2 != id_employee)
            fprintf(temp2,"%d %s\n",tempID2, buffer);
    }


    fclose(input1);
    fclose(temp1);
    fclose(input2);
    fclose(temp2);
    remove(EMPLOYEE_INFO_FILE);  		// remove the original file
    rename(TMP1_FILE, EMPLOYEE_INFO_FILE);
    remove(EMPLOYEE_WORK_FILE);
    rename(TMP2_FILE, EMPLOYEE_WORK_FILE);	// rename the temporary file to original name
}

/*
 * Function:  approx_pi
 * --------------------
 * computes an approximation of pi using:
 *    pi/6 = 1/2 + (1/2 x 3/4) 1/5 (1/2)^3  + (1/2 x 3/4 x 5/6) 1/7 (1/2)^5 +
 *
 *  n: number of terms in the series to sum
 *
 *  returns: the approximate value of pi obtained by suming the first n terms
 *           in the above series
 *           returns zero on error (if n is non-positive)
 */
int menu()
{
    int choice;

    printf("\n\n/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\");
    printf("\n");
    printf("\n\t\t\t\t\t  WELCOME CLERK");
    printf("\n\t\t\t             John's and Brothers LTD");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    printf("\n\t\t\t\t     PAYROLL MANAGEMENT SYSTEM ");
    printf("\n");
    printf("\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t\t\tPlease choose from the following menu options:");
    printf("\n\t\t\t\t\t\t\t\t");
    printf("\n\t\t\t\t 1 - View Records");              /* < func. req # */
    printf("\n\t\t\t\t 2 - Payroll Register");          /* < func. req # */
    printf("\n\t\t\t\t 3 - Payslip of an Employee");    /* < func. req # */
    printf("\n\t\t\t\t 4 - Search Records");            /* < func. req # */
    printf("\n\t\t\t\t 5 - Sorted Employee Record");    /* < func. req # */
    printf("\n\t\t\t\t 6 - Edit Records");              /* < func. req # */
    printf("\n\t\t\t\t 7 - Delete Records");            /* < func. req # */
    printf("\n\t\t\t\t 8 - Add Records");               /* < func. req # */
    printf("\n\t\t\t\t 9 - Exit System");
    printf("\n");
    printf("\n\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\");

    printf("\n\nOption: ");
    scanf("%d",&choice);
    return choice;
}

/*
 * Function:  approx_pi
 * --------------------
 * computes an approximation of pi using:
 *    pi/6 = 1/2 + (1/2 x 3/4) 1/5 (1/2)^3  + (1/2 x 3/4 x 5/6) 1/7 (1/2)^5 +
 *
 *  n: number of terms in the series to sum
 *
 *  returns: the approximate value of pi obtained by suming the first n terms
 *           in the above series
 *           returns zero on error (if n is non-positive)
 */
void view_information()
{
    int i;

    printf("\t\t__________Deparment Information________________\n");
    printf("\nDeparment ID\t\tDepartment Name\n");
    for(i=0;i<num_records_Department; i++)
    {
        printf("\n%-10s              %-10s",department[i].departmentID,department[i].departmentName);
    }

    printf("\nLoad more?...");
    system("pause");

    printf("\n\n\n\t\t__________ Employee Personal Information____________\n");

    printf("\nEmployee ID \tEmployee Name\t   Gender    Date Of Birth   Address \t\t Contact \t# of Dpdts\n");

    for (i=0; i<num_records_Employees; i++)
    {
        printf("\n%-10s    %-10s %-9s %7s     %-10s    %-15s %-14s %13d",
               employees[i].employeeID,
               employees[i].firstName,
               employees[i].lastName,
               employees[i].gender,
               employees[i].dob,
               employees[i].address,
               employees[i].contactNumber,
               employees[i].numDependants);
    }

    printf("\nLoad more?...");
    system("pause");

    printf("\n\n\t\t\t\t__________ Employee Work Information____________\n");

    printf("\n\nEmp ID\t    Title\t\tYear of Emp\t Dept ID\t Standard Pay\tHours Worked\t OT\tDays Worked\n\n");

    for (i=0; i<num_records_Employees; i++)
    {
        printf("%-8s  %-23s  %-8d  %12s  %14.2f    %10d  %10d   %10d\n",
               mwages[i].employeeID,
               employees[i].jobTitle,
               employees[i].startYear,
               employees[i].departmentID,
               mwages[i].RateOfPay,
               mwages[i].hoursWorked,
               mwages[i].overtimeHoursWorked,
               mwages[i].daysWorked);
    }

}

/*
 * Function:  approx_pi
 * --------------------
 * computes an approximation of pi using:
 *    pi/6 = 1/2 + (1/2 x 3/4) 1/5 (1/2)^3  + (1/2 x 3/4 x 5/6) 1/7 (1/2)^5 +
 *
 *  n: number of terms in the series to sum
 *
 *  returns: the approximate value of pi obtained by suming the first n terms
 *           in the above series
 *           returns zero on error (if n is non-positive)
 */
void add_record()
{
    system("cls");

    int i;

    printf("\t\t\t\t__________ Adding Employee Work Information____________\n");
    printf("\nEmployee ID:  ");
    scanf("%s",&employees[i].employeeID);
    printf("\nEmployee first name: ");
    scanf("%s",&employees[i].firstName);
    printf("\nEmployee last name:  ");
    scanf("%s",&employees[i].lastName);
    printf("\nEmployee Gender: ");
    scanf("%s",&employees[i].gender);
    printf("\nEmployee date of birth:  ");
    scanf("%s",&employees[i].dob);
    printf("\nEmployee Adress:  ");
    scanf("%s",&employees[i].address);
    printf("\nEmployee contact:  ");
    scanf("%s",employees[i].contactNumber);
    printf("/nEmployee Number of Dependants:  ");
    scanf("%d",employees[i].numDependants);
    printf("\nEmployee Employment Year:  ");
    scanf("%d",employees[i].startYear);
    printf("\nDepartment ID:  ");
    scanf("%s",employees[i].departmentID);
    printf("\nEmployee Position:  ");
    scanf("%s",employees[i].jobTitle);

    FILE *output= fopen("Department_Information.txt","w");

    if(output == NULL)
    {
        printf("Error");
        exit(1);
    }

    fprintf(output,"%s %s %s %s %s %s %s %d %d %s %s\n",
            employees[i].employeeID,
            employees[i].firstName,
            employees[i].lastName,
            employees[i].gender,
            employees[i].dob,
            employees[i].address,
            employees[i].contactNumber,
            employees[i].numDependants,
            employees[i].startYear,
            employees[i].departmentID,
            employees[i].jobTitle);

    printf("\n\nEmployee ID:  ");
    scanf("%s",&mwages[i].employeeID);
    printf("\nEmployee Rate of Pay:  ");
    scanf("%f",&mwages[i].RateOfPay);
    printf("\nEmployee Work Hours:  ");
    scanf("%d",&mwages[i].hoursWorked);
    printf("\nEmployee Overtime Hours:  ");
    scanf("%d",&mwages[i].overtimeHoursWorked);
    printf("\nEmployee Work Days:  ");
    scanf("%d",&mwages[i].daysWorked);

    FILE *output1= fopen("Work_Information.txt","w");

    if(output1 == NULL)
    {
        printf("Error");
        exit(1);
    }

    fprintf(output1,"%s %f %d %d %d\n",
            mwages[i].employeeID,
            mwages[i].RateOfPay,
            mwages[i].hoursWorked,
            mwages[i].overtimeHoursWorked,
            mwages[i].daysWorked);
}

/*
 * Function:  approx_pi
 * --------------------
 * computes an approximation of pi using:
 *    pi/6 = 1/2 + (1/2 x 3/4) 1/5 (1/2)^3  + (1/2 x 3/4 x 5/6) 1/7 (1/2)^5 +
 *
 *  n: number of terms in the series to sum
 *
 *  returns: the approximate value of pi obtained by suming the first n terms
 *           in the above series
 *           returns zero on error (if n is non-positive)
 */
void edit_record()
{
    char id_employee[MAX_CHARS];
    int i;
    system("cls");

    FILE *input2= fopen("Work_Information.txt","r");
    FILE * temp2= fopen("Temp2_information.txt","w");

    if (input2 == NULL || temp2 == NULL)
    {
        exit(1);
    }
    printf("Enter Employee ID to Edit : ");

    fflush(stdin);

    scanf("%s",id_employee);

    printf("Here\n");
    system("pause");


    for (i = 0; i < num_records_Employees; i++) {


    if((strcmp(id_employee, mwages[i].employeeID)) == 0)
    {
        printf("\nEmployee New Rate of Pay:  ");
        scanf("%f",&mwages[i].RateOfPay);
        printf("\nEmployee New Work Hours:  ");
        scanf("%d",&mwages[i].hoursWorked);
        printf("\nEmployee New Overtime Hours:  ");
        scanf("%d",&mwages[i].overtimeHoursWorked);
        printf("\nEmployee New Work Days:  ");
        scanf("%d",&mwages[i].daysWorked);

        fprintf(temp2,"%s %f %d %d %d\n",
                &mwages[i].employeeID,
                &mwages[i].RateOfPay,
                &mwages[i].hoursWorked,
                &mwages[i].overtimeHoursWorked,
                &mwages[i].daysWorked);
    }
    }

    printf("Before while \n");
    system("pause");
    while(!(feof(input2)));

    fclose(input2);
    fclose(temp2);
    remove(EMPLOYEE_WORK_FILE);
    rename(TMP2_FILE, EMPLOYEE_WORK_FILE);

    system ("cls");
}

/*
 * Function:  approx_pi
 * --------------------
 * computes an approximation of pi using:
 *    pi/6 = 1/2 + (1/2 x 3/4) 1/5 (1/2)^3  + (1/2 x 3/4 x 5/6) 1/7 (1/2)^5 +
 *
 *  n: number of terms in the series to sum
 *
 *  returns: the approximate value of pi obtained by suming the first n terms
 *           in the above series
 *           returns zero on error (if n is non-positive)
 */
int loadDATA()
{

    int i;

    FILE *input= fopen("Department_Information.txt","r");

    if(input == NULL)
    {
        printf("Error");
        exit(1);
    }
    for (i=0; i<NUM_RECORDS_DEPT; i++)
    {
        fscanf(input, "%s %s",department[i].departmentID,
               department[i].departmentName );
        num_records_Department++;
    }
    fclose(input);


    i=0;
    FILE *input1= fopen("Employee_Information.txt","r");

    if(input1 == NULL)
    {
        printf("Error");
        exit(1);
    }
    for (i=0; i<NUM_RECORDS_IN_FILE; i++)
    {
        fscanf(input1,"%s %s %s %s %s %s %s %d %d %s %s",
               &employees[i].employeeID,
               &employees[i].firstName,
               &employees[i].lastName,
               &employees[i].gender,
               &employees[i].dob,
               &employees[i].address,
               &employees[i].contactNumber,
               &employees[i].numDependants,
               &employees[i].startYear,
               &employees[i].departmentID,
               &employees[i].jobTitle);

        /* printf("%s %s %s %s %s %s %s %d %d %s %s\n",
               employees[i].employeeID,
               employees[i].firstName,
               employees[i].lastName,
               employees[i].gender,
               employees[i].dob,
               employees[i].address,
               employees[i].contactNumber,
               employees[i].numDependants,
               employees[i].startYear,
               employees[i].departmentID,
               employees[i].jobTitle);*/

        num_records_Employees ++;
    }
    fclose(input1);

    i=0;
    FILE *input2= fopen("Work_Information.txt","r");

    if(input2 == NULL)
    {
        printf("Error");
        exit(1);
    }
    for (i=0; i<NUM_RECORDS_IN_FILE; i++)
    {
        fscanf(input2,"%s %f %d %d %d\n",
               &mwages[i].employeeID,
               &mwages[i].RateOfPay,
               &mwages[i].hoursWorked,
               &mwages[i].overtimeHoursWorked,
               &mwages[i].daysWorked);
    }
    fclose (input2);
}


int main ()
{
    num_records_Employees = 0;
    num_records_Department =0;
    loadDATA();

    int mm_option;
    int i;
    if ( entry()  )
    {
        getchar();

        system ("cls");

        mm_option = menu();
        getchar();

        while (1)
        {
            switch (mm_option)
            {
            case 1:
                view_information();             /* < func. req # */
                break;
            case 2:
                payroll_register();             /* < func. req # */
                getchar();
                break;
            case 3:
                paySlip();                      /* < func. req # */
                break;
            case 4:
                search();                       /* < func. req # */
                break;
            case 5:
                bubble_sort();                  /* < func. req # */
                break;
            case 6:
                edit_record();                  /* < func. req # */
                break;
            case 7:
                delete_record();                /* < func. req # */
                break;
            case 8:
                add_record();                   /* < func. req # */
                break;
            case 9:
                exit_message();
                break;
            default:
                exit(1);
            }//end switch
            mm_option = menu();
        }//end while
    }//end if @entry

    return 0;
}
