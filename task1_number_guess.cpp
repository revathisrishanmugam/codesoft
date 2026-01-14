#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
using namespace std;

int main() 
{
    int number,guess;
    srand(time(0));
    number=rand()%100 +1;
    cout<<"Guess a number between 1 and 100 "<< endl;
    do{
        while(!(cout<<" Enter your guess: " && cin>> guess))
        {
            cout<<"Invalid input! Please enter a number."<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            
        }
        if(guess>number){
        cout<<"Too high!"<<endl;}
        else if(guess<number){
        cout<<"Too low!"<<endl;}
        else{
        cout<<"Congratulations! you guessed correctly"<<endl;
        }
    }while(guess!= number);
    
    return 0;
    
}
