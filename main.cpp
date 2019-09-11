// Program coded by Mesut Apil
#include<iostream>
#include<cstdlib>
#include <iomanip>
using namespace std;

void Reverse(int[],int);
void squared(int[],int);
int raiseToPower(int,int);
void checkPrime(int[],int,int);

void Reverse(int array[],int size){
    if ( size >= 0){
        cout<<array[size]<<" ";
        Reverse(array, size -1);
    }
}
void squared(int array[],int integer){
    if (integer != array[0]){
        cout<<integer;
        cout<< setw(13);
        cout <<integer*integer<<endl;
        squared(array, integer +1);
    }
    else if(integer == array[0]){
        cout<< integer << setw(13) << integer*integer;
    }
}
int raiseToPower(int lastNum,int exponent){
    if (exponent == 0)
        return 1;
    else
        return lastNum * raiseToPower(lastNum, exponent-1);
    
}
void checkPrime(int array[],int size,int temp){
    int count = 0; // counts the multiple of users value
    
    while (size == temp) {
        for(int i = 2;i < array[temp]; i++){
            if (array[temp] % i == 0)
                count++;
        }
        if (count > 1)
            cout << "The number "<<array[temp]<<" is not prime"<<endl;
        else
            cout << "The number "<<array[temp]<<" is prime"<<endl;
        
        cout << endl << "Mesut Apil - Tweak Programming Director "
        << "April 2019" << endl;
        
        exit (0);
        
    }
    
    for(int i = 2;i < array[temp]; i++){
        if (array[temp] % i == 0)
            count++;
    }
    if (count > 1)
        cout << "The number "<<array[temp]<<" is not prime"<<endl;
    else
        cout << "The number "<<array[temp]<<" is prime"<<endl;
    checkPrime(array, size,temp+1);
}

int main(){
    int size;
    int square =1;
    int temp =0;
    cout<< "*** Welcome To My Recursion App ***"<<endl << endl;
    cout << "Enter The array size. (Must be >= 5) ";
    cin>>size;
    cout << endl;
    
    if (size < 5){
        cout << "Invalid arrays size. Size must >= 5" << endl << endl;
        cout << "Mesut Apil - Tweak Programming Director7 April 2019" << endl;
        
        return 1;
    }
    size = size - 1;
    int Array[size];
    
    for (int i = 0;i <= size; i++){
        Array[i] = rand()%375 + 10;
    }
    cout<<"Generated array: "<<endl;
    for (int i =0; i <= size; i++){
        cout<<Array[i] << " ";
    }
    cout << endl << endl;
    cout<<"Inverse with recursion:"<<endl;
    Reverse(Array,size);
    cout<<endl << endl;
    cout<<"Table of square values 1 - " << Array[size] <<endl;
    cout<<endl;
    cout<<"N          N Squared:"<<endl;
    squared(Array,square);
    cout<< endl << endl;
    int lastNum = Array[size];
    cout << lastNum << " raised to the power of two is: " << raiseToPower(lastNum, 2);
    cout<< endl <<endl;
    cout<<"Prime Check"<<endl;
    checkPrime(Array,size, temp);
    
}
