#include <iostream>

//I've NOT added std namespace on purpose!
// using namespace std; //<-uncomment this line if you like to use it

//enums used for Challenge:1
enum MessageType{
    Error,
    Confirm,
    Info,
    Warning
};

//Displays a message: enum Message Type, string Message
void message(MessageType mt, std::string message){
    switch (mt)
    {
    case Error:
        std::cout<<"Message type:ERROR: "<<message<<std::endl;
        break;
    case Confirm:
        std::cout<<"Message type:CONFRIM: "<<message<<std::endl;
        break;
    case Info:
        std::cout<<"Message type:INFO: "<<message<<std::endl;
        break;
    case Warning:
        std::cout<<"Message type:WARNING: "<<message<<std::endl;
        break;
    }
    
}
//returns the sum of 2 whole numbers:
int add(int a, int b){
        return a+b;
}
//returns the product of 2 partial numbers:
float multiply(float a, float b){
    return a*b;
}
//displays the sum of 2 arrays of whole numbers: Array A, Array B, Size of Array A, Size of Array B
void add(int* a, int* b, int sizeA, int sizeB){
    int size = sizeA >= sizeB ? sizeA : sizeB;
    int sum [size];
    std::cout<<"Sum of the arrays: ";
    for(int i = 0; i < size; i++){
        if(i>=sizeB)
            *(sum+1) = *(a+i);
        else
            *(sum+i) = *(a+i)+*(b+i);
            std::cout<<*(sum+i)<<" ,";
    }
    std::cout<<std::endl;   
}
//Contains usefull conversion methods
class Conversions{
    //meter to foot constant:
    const float meterToFoot = 0.3048;
    //foot to meter constant:
    const float footToMeter = 3.2808;
    //checks if a letter is upper case:
    bool isUpper(char c){
        int inASCII = (int)c;
        return (inASCII>=65 && inASCII<=90)? true : false; 
    }
    //returns a string from char array: Char Array, Array Size
    std::string toString(char* arr, int size){
        std::string s = "";
        for(int i=0; i<size; i++){
            s+=arr[i];
        }
        return s;
    }
public:
    //returns converted meters to feet:
    float meterToFeet(float meters){
        return meters/meterToFoot;
    }
    //returns converted feets to meters:
    float feetToMeters(float feet){
        return feet/footToMeter;
    }
    //returns converted C temperature to F:
    float celsiusToFarenheit(float tempC){
        float tempF = (tempC*1.8)+32;
        return tempF;
    }
    //returns converted F temperature to C:
    float farenheitToCelsius(float tempF){
        float tempC = (tempF-32)/1.8;
        return tempC;
    }
    //returns a string to all upper case:
    std::string toUpperCase(std::string text){
        int textLength=text.length();
        char letters[textLength];
        for(int i=0; i<textLength; i++){
            if(text[i]==' '){
                letters[i] = ' ';
            }
            else
                {
                    if(isUpper(text[i])){
                        letters[i]=text[i];
                    }
                    else
                        {
                        int letter = (int)text[i]-32;
                        letters[i] = (char)letter;
                        }
                }        
        }
        return toString(letters,textLength);    
    }
    //returns substring to desired lenght: String, Length
    std::string trim(std::string text, int length){
        std::string trimmed ="";
        if(length>text.length())
        {
            return text;
        }
        else
        {
            for(int i=0; i<length; i++){
                trimmed += text[i];
            }
            return trimmed;
        }
    }

};
//returns the average value of a whole numbers array: Array, Array Size
int average(int* range, int size){
    int average, sum =0;
    for(int i=0; i<size; i++){
         sum += range[i];
    }
    average = sum/size;
    return average;
}
//returns the average value of a fraction numbers array: Array, Array Size
float average(float* range,int size){
    float average, sum =0;
    for(int i=0; i<size; i++){
         sum += range[i];
    }
    average = sum/size;
    return average;
}
//displays a sorting of a whole number array: Array, Array, Size, Ascending or Descending
void arraySort(int* arr,int size, bool way){
    int temp;
    if(way){
        for(int i =0; i<size; i++){
            for(int j=i+1;j<size;j++){
                if(arr[i]>arr[j]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        std::cout<<"sorted ascending arr[";
        for(int i=0;i<size;i++){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<"]"<<std::endl;
    }
    else
    {
        for(int i =0; i<size; i++){
            for(int j=i+1;j<size;j++){
                if(arr[i]<arr[j]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        std::cout<<"sorted descending arr[";
        for(int i=0;i<size;i++){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<"]"<<std::endl;
    }

}
//displays duplicates in a whole numbers array: Array, Array Size
void duplicates(int* arr,int size){
    for(int i=0; i<size;i++){
        for(int j=i+1;j<size; j++){
            if(arr[i]==arr[j])
            {
                std::cout<<arr[i]<<": is duplicated"<<std::endl;
            }
        }       
    }
}
int main(){
    //Challenge 1 - Print out a greeting message
    message(Info,"You've just printed a info message to console");
    //Challenge 2 - Add 2 numbers + Bonus Add 2 number arrays
    int a = 26, b= 17;
    std::cout<<a<<"+"<<b<<"="<<add(a,b)<<std::endl;
    int st [4] ={19,86,12,17};
    int sv [4] ={19,89,7,26};
    add(st,sv,4,4);
    //Challenge 3 Convert feet to meters + Bonus Meter to feet
    Conversions convert;
    float distanceInFeet = 38.5, distanceInMeters=10.3;
    std::cout<<distanceInFeet<<" in feet is: "<<convert.feetToMeters(distanceInFeet)<<" in meters."<<std::endl;
    std::cout<<distanceInMeters<<" in meters is: "<<convert.meterToFeet(distanceInMeters)<<" in feet"<<std::endl;
    //Challenge 4 Convert Celsius to Farenheite + Bonus vice versa
    float tempC = 22.3, tempF = 68.5;
    std::cout<<tempC<<"in C is "<<convert.celsiusToFarenheit(tempC)<<" in F"<<std::endl;
    std::cout<<tempF<<"in F is "<<convert.farenheitToCelsius(tempF)<<" in C"<<std::endl;
    //Challenge 5 Multiply 2 floats:
    float x=3.5,y=6.7;
    std::cout<<x<<"*"<<y<<"="<<multiply(x,y)<<std::endl;
    //Challenge 6 String to upper case
    std::cout<<"Lorem ipsum dolor sit amet"<<" -in lower case"<<std::endl;
    std::cout<<convert.toUpperCase("Lorem ipsum dolor sit amet")<<" -IN UPPER CASE"<<std::endl;
    //Challenge 7 Average of numbers:
    int range[4] = {20,17,12,16};
    float frange[4] = {20,17,12,16};
    std::cout<<"The average of the range is: "<<average(range,4)<<" -whole numbers"<<std::endl;
    std::cout<<"The average of the range is: "<<average(frange,4)<<" -with fractions"<<std::endl;
    //Challenge 8 Trim a string up to N-th char:
    std::string address ="34 Slivnitsa str. Burgas, 8000, Bulgaria";
    std::cout<<address<<" -String to be Trimmed"<<std::endl;
    std::cout<<convert.trim(address,16)<<" -Trimmed to the 16-th character"<<std::endl;
    //Challenge 9 Array sorter
    std::cout<<"Choose true for ascending and false for ascending sorting:"<<std::endl;
    arraySort(range,4,true);
    arraySort(range,4,false);
    //Challenge 10 finding duplicates in the array
    int numbers[12] = {19,86,12,17,20,17,12,16,19,89,8,17};
    duplicates(numbers,12);

    system("pause>nul");
}