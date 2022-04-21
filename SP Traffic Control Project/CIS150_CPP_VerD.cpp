#include <iostream>
#include <string>
using namespace std;

struct date
{
    int year, month, day;
};

struct fines
{
    int value;
    string street_name;
    date fine_date;
    bool paid;
}list_of_fines[100] = {0};

struct cars
{
    int car_plate_num, production_year;
    string model;
    fines list_of_fines[100];
}owned_cars[2];

struct drivers 
{
    string driver_name;
    date birth_date;
    cars owned_cars[2];
    int license_num;
}d[2];

int const max_speed = 60;
int car_speed;
int fine(int, int);  // calculate the fine
void violation_recording(int);  // assign fine to it's driver
int payment(char);  // update fine value
bool search(int);  // search for the car

int main()
{  
    for (int i = 0; i < 2; i++)
    {
        cout << "enter driver name, birth date and license number: ";
        cin >> d[i].driver_name >> d[i].birth_date.day >> d[i].birth_date.month >> d[i].birth_date.year >> d[i].license_num;
        for (int j = 0; j < 2; j++)
        {
            cout << " enter car's plate number, model, production year: ";
            cin >> d[j].owned_cars[j].car_plate_num >> d[j].owned_cars[j].model >> d[j].owned_cars[j].production_year;
        }
        cout << endl;
    }

    int car_number;
    cout << "search for a car by enetring car plate number: ";
    cin >> car_number;
    search(car_number);
    cout << endl;
    cout << endl;

    char answer;
    for (int i = 0; i < 2; i++)
    {
        cout << "enter car speed for the car with plate number " << d[i].owned_cars[i].car_plate_num << ": ";
        cin >> car_speed;
        cout << "enter the date: ";
        cin >> d[i].owned_cars[i].list_of_fines[i].fine_date.day >> d[i].owned_cars[i].list_of_fines[i].fine_date.month 
            >> d[i].owned_cars[i].list_of_fines[i].fine_date.year;
        cout << "enter streat name: ";
        cin >> d[i].owned_cars[i].list_of_fines[i].street_name;
        violation_recording(car_speed);
        cout << "your fine = " << d[i].owned_cars[i].list_of_fines[i].value << endl;
        cout << "will you pay now? Y or N: ";
        cin >> answer;
        payment(answer);
        cout << endl;
    }

    return 0;
    system("pause");
}

int fine(int max_speed, int car_speed)
{
    return (car_speed - max_speed) * 2;
}

void violation_recording(int car_speed)
{
    for (int i = 0; i < 2; i++)
    {
        if (car_speed < max_speed || car_speed == max_speed)
        {
            d[i].owned_cars[i].list_of_fines[i].value += 0;
        }
          
        else if (car_speed > max_speed)
        {
            d[i].owned_cars[i].list_of_fines[i].value += fine(max_speed, car_speed);
        }
    }
}

int payment(char answer)
{
    for (int i = 0; i < 2; i++)
    {
        if (answer == 'Y' || 'y')
        {
            d[i].owned_cars[i].list_of_fines[i].paid = true;
            d[i].owned_cars[i].list_of_fines[i].value -= fine(max_speed, car_speed);
        }
        else if (answer == 'N' || 'n')
        {
            d[i].owned_cars[i].list_of_fines[i].paid = false;
            d[i].owned_cars[i].list_of_fines[i].value == fine(max_speed, car_speed);
        }
        cout << d[i].owned_cars[i].list_of_fines[i].value;
        return d[i].owned_cars[i].list_of_fines[i].value;
    }
}

bool search(int car_number)
{
    for (int i = 0; i < 2; i++)
    {
        if (d[i].owned_cars[i].car_plate_num == car_number)
        {
            cout << d[i].driver_name << "\n" << d[i].birth_date.day << "/" << d[i].birth_date.month << "/" << d[i].birth_date.year << "\n"
                << d[i].license_num;
            return true;
        }
    }
}