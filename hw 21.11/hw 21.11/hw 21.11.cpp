#include "settings.h"

struct Moment {
	unsigned int day;
	unsigned int month;
	int year;
    unsigned int hours;
    unsigned int minutes;
};

struct Device {
    string product_type;
    string name;
    string model;
    string brand;
    unsigned int guarantee;
    float price;
    Moment sell_date;
    Moment actual_date;
};

void SetInfoDevice(Device& prod) {
    cout << "Enter type of product: ";
    cin >> prod.product_type;

    cout << "Enter name of product: ";
    cin >> prod.name;

    cout << "Enter model of product: ";
    cin >> prod.model;

    cout << "Enter brand of product: ";
    cin >> prod.brand;

    cout << "Enter how many months the guarantee is valid: ";
    cin >> prod.guarantee;
    if (prod.guarantee < 0) {
		cout << "Inccorrect value for a month(\n";
		throw "ERROR!!!";
	}

    cout << "Enter price of your product ($): ";
    cin >> prod.price;
    if (prod.price < 0) {
        cout << "Inccorrect value for a price(\n";
        throw "ERROR!!!";
    }

    cout << "Enter day when you bought the product: ";
    cin >> prod.sell_date.day;
    if (prod.sell_date.day < 1 || prod.sell_date.day > 31) {
        cout << "Inccorrect value for a day(\n";
        throw "ERROR!!!";
    }

    cout << "Enter month when you bought the product: ";
    cin >> prod.sell_date.month;
    if (prod.sell_date.month < 1 || prod.sell_date.month > 12) {
        cout << "Inccorrect value for a month(\n";
        throw "ERROR!!!";
    }

    cout << "Enter year when you bought the product: ";
    cin >> prod.sell_date.year;

    cout << "Enter hours when you bought the product: ";
    cin >> prod.sell_date.hours;
    if (prod.sell_date.hours < 0 || prod.sell_date.hours > 23) {
        cout << "Inccorrect value for a hour(\n";
        throw "ERROR!!!";
    }

    cout << "Enter minutes when you bought the product: ";
    cin >> prod.sell_date.minutes;
    if (prod.sell_date.minutes < 0 || prod.sell_date.minutes > 59) {
        cout << "Inccorrect value for a minute(\n";
        throw "ERROR!!!";
    }

    cout << "Enter number of actual day: ";
    cin >> prod.actual_date.day;
    if (prod.actual_date.day < 1 || prod.actual_date.day > 31) {
        cout << "Inccorrect value for a day(\n";
        throw "ERROR!!!";
    }

    cout << "Enter number of actual month: ";
    cin >> prod.actual_date.month;
    if (prod.actual_date.month < 1 || prod.actual_date.month > 12) {
        cout << "Inccorrect value for a month(\n";
        throw "ERROR!!!";
    }

    cout << "Enter actual year: ";
    cin >> prod.actual_date.year;

    cout << "Enter actual hours: ";
    cin >> prod.actual_date.hours;
    if (prod.actual_date.hours < 0 || prod.actual_date.hours > 23) {
        cout << "Inccorrect value for a hour(\n";
        throw "ERROR!!!";
    }

    cout << "Enter actual minutes: ";
    cin >> prod.actual_date.minutes;
    if (prod.actual_date.minutes < 0 || prod.actual_date.minutes > 59) {
        cout << "Inccorrect value for a minute(\n";
        throw "ERROR!!!";
    }
}

void PrintInfoDevice(const Device& prod) {
    system("cls");
    cout << "\t\tYour purchases\n";
    cout << "\t" << prod.product_type << "\n";
    cout << prod.name << " " << prod.brand << " " << prod.model << "____________________" << prod.price << "$\n";
    cout << "Time of purchase - ";
    printf("%02d.%02d.%04d  %02d:%02d\n\n", prod.sell_date.day, prod.sell_date.month, prod.sell_date.year, prod.sell_date.hours, prod.sell_date.minutes);
    cout << "Guarantee - " << prod.guarantee << " months\t";
}

void IsGuaranteeActual(Device& prod) {
    Moment guarantee_moment;
    guarantee_moment.year = prod.sell_date.year;
    guarantee_moment.month = prod.sell_date.month;
    guarantee_moment.year += prod.guarantee / 12;
    guarantee_moment.month += prod.guarantee % 12;
    guarantee_moment.day = prod.sell_date.day;
    guarantee_moment.hours = prod.sell_date.hours;
    guarantee_moment.minutes = prod.sell_date.minutes;

    if (guarantee_moment.month > 12) {
        guarantee_moment.month -= 12;
        guarantee_moment.year++;
    }

    bool actual_guarantee;
    if (prod.actual_date.year == guarantee_moment.year) {
        if (prod.actual_date.month == guarantee_moment.month) {
            if (prod.actual_date.day == guarantee_moment.day) {
                if (prod.actual_date.hours == guarantee_moment.hours) {
                    if (prod.actual_date.minutes == guarantee_moment.minutes) {
                        actual_guarantee = true;
                    }
                    else if (prod.actual_date.minutes < guarantee_moment.minutes) {
                        actual_guarantee = true;
                    }
                    else actual_guarantee = false;
                }
                else if (prod.actual_date.hours < guarantee_moment.hours) {
                    actual_guarantee = true;
                }
                else actual_guarantee = false;
            }
            else if (prod.actual_date.day < guarantee_moment.day) {
                actual_guarantee = true;
            }
            else actual_guarantee = false;
        }
        else if (prod.actual_date.month < guarantee_moment.month) {
            actual_guarantee = true;
        }
        else actual_guarantee = false;
    }
    else if (prod.actual_date.year < guarantee_moment.year) {
        actual_guarantee = true;
    }
    else actual_guarantee = false;

    if (actual_guarantee) {
        cout << "(actual)\n";
    }
    else {
        cout << "(out of date)\n";
    }
}

int main()
{
    Device product;
    SetInfoDevice(product);
    PrintInfoDevice(product);
    IsGuaranteeActual(product);
    Sleep(INFINITE);
}