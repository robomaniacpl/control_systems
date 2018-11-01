//
// Created by lukas on 03/10/18.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Mandatory headers needed by CMocka
#include <stdbool.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>

//pa = table2array(data(:,4));pd = table2array(data(:,3));e = table2array(data(:,1));u = table2array(data(:,2));figure(1);plot(e,u,'.');figure(2);plot(t,pa,'.',t,pd);legend('pa','pd');figure(3);plot(t,u);
#define a 0.2
#define H 0.5

#define step 0.1

float pressure_actual = 0;

bool pressure_up = false;


void valve_tank(int is_on){
    if(is_on)
        pressure_up = true;
}
void valve_ambient(int is_on){
    if(is_on)
        pressure_up = false;
}

// This is our wrapper, for the purpose of testing only
void __wrap_valve_tank(int is_on)
{
    check_expected(is_on);

}

void __wrap_valve_ambient(int is_on) {
    check_expected(is_on);


}

int regulator(float error, int control) {
    if((error > a+H) || (error > a && control == 1)){
        control = 1;
    } else if((error < -a-H) || (error < -a && control == -1)){
        control = -1;
    } else {
        control = 0;
    }


    return control;
}

void valve_control(float pressure_demand) {

    pressure_actual = 0;
    float error = 100;
    int control, i;

    for(i=0;i<1000;++i) {
        if(i==200) {
            pressure_demand = 0;
        }
        if(i==600) {
            pressure_demand = 9;
        }
        if(i==800) {
            pressure_demand = 0;
        }

        error = pressure_demand-pressure_actual;
        control = regulator(error, control);

        if(control == 1) {
            valve_tank(1);
            valve_ambient(0);
        } else if (control == -1) {
            valve_tank(0);
            valve_ambient(1);
        }
//        else {
//            valve_tank(0);
//            valve_ambient(0);
//        }
        pressure_actual-=0.01;

        if(pressure_up)
            pressure_actual+=step;
        else
            pressure_actual-=step;

//        printf("e: %.2f, u: %d, pd: %.2f, pa: %.2f\n", error, control, pressure_demand, pressure_actual);
        printf("%.2f,%d,%.2f,%.2f\n", error, control, pressure_demand, pressure_actual);

    }



}


//// Test functions
//static void test_successful_deposit(void** state)
//{
//    (void)state;  //unused variable
//
//    // These expects must match the order of declaration of "check_expected"
//    // in __wrap_deposit()
//    int deposit_money = 400;
//    const char* deposit_bank = "Citibank";
//
//    expect_value(__wrap_deposit, money, deposit_money);
//    expect_string(__wrap_deposit, bank, deposit_bank);
//
//    // These will_return's must match the order of declaration of "mock_type"s
//    // in __wrap_deposit()
//    will_return(__wrap_deposit, true);  // assume account is valid
//    will_return(__wrap_deposit, deposit_money);
//    will_return(__wrap_deposit, deposit_bank);
//
//    // Test the production code
//    int ret = production_code(deposit_money, deposit_bank);
//
//
//    assert_int_equal(ret, EXIT_SUCCESS);
//}

//static void test_failed_deposit(void** state)
//{
//    (void)state;  //unused variable
//
//    // These expects must match the order of declaration of "check_expected"
//    // in __wrap_deposit()
//    int deposit_money = 199;
//    const char* deposit_bank = "Citibank";
//
//    expect_value(__wrap_deposit, money, deposit_money);
//    expect_string(__wrap_deposit, bank, deposit_bank);
//
//    // These will_return's must match the order of declaration of "mock_type"s
//    // in __wrap_deposit()
//    will_return(__wrap_deposit, false);  // assume account is invalid
//
//    // Test the production code
//    int ret = production_code(deposit_money, deposit_bank);
//
//    assert_int_equal(ret, EXIT_FAILURE);
//}


int main(void)
{
    valve_control(2);
//    const struct CMUnitTest tests[] = {
//            cmocka_unit_test(test_successful_deposit),
////            cmocka_unit_test(test_failed_deposit),
//    };
//
//    return cmocka_run_group_tests(tests, NULL, NULL);

    return EXIT_SUCCESS;

}