#include <iostream>

class Calculator
{
public:
    float result;

    float on()
    {
        result = 0;
        return result;
    }

    float sum(float num)
    {
        result = result + num;
        return result;
    }
    float sub(float num)
    {
        result -= num;
        return result;
    }
    float mul(float num)
    {
        result *= num;
        return result;
    }
    float div(float num){
        result /= num;
        return result;
    }
    float eqalTo(){
        return result;
    }
};

using namespace std;
int main()
{
    Calculator cal;
    bool exit = false;
    cout << "Result: "<< cal.on() << "\n";
    while( exit == false)
    {
        char ch;
        float value;
        cout << "Choice: 1-Sum, 2-Sub, 3-Mul, 4-Div, 5: Result, 6: Exit\n";
        cin >> ch;
        if(!(ch == '5' || ch == '6'))
        {
            cout << "Enter Data:";
            cin >> value;
        }
        switch (ch)
        {
        case '1':
            cal.sum(value);
            break;
        case '2':
            cal.sub(value);
            break;
        case '3':
            cal.mul(value);
            break;
        case '4':
            cal.div(value);
            break;
        case '5':
            cout<<"Result:"<<cal.eqalTo()<<endl;
            break;
        default:
            exit = true;
            break;
        };
    }
    cout << "Result: "<< cal.eqalTo() << endl;
}